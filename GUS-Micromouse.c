#include <stdio.h>
#include "pico/stdlib.h"
#include "Libreria/Monitor.h"
#include "Libreria/Acelerometro.h"
#include "Libreria/Encoder.h"
#include "Libreria/SensorInfrarrojo.h"
#include "Libreria/PWM.h"
#include "Libreria/Direccion.h"
#include "Temps/Default.h"
#include "Memory/maze.h"

int main(){
    stdio_init_all();

    // Inicialización
    motores_init();
    direccion_init();
    sensor_infrarrojo_init_BACK();
    sensor_infrarrojo_init_FRONT();
    sensor_infrarrojo_init_LEFT();
    sensor_infrarrojo_init_RIGHT();
    encoder_init();
    acelerometro_init();

    while (true){
        //Funcon para monitorizar el estado del micromouse y actualizar el laberinto.
        monitor_data_t data = monitor_leer_datos();
        monitor_imprimir(data);
        monitor_actualizar_laberinto(data);

        //lógica de movimiento basada en los sensores infrarrojos.
        if(data.ir.front){
            direccion_adelante();
            motor_set_speed(1, VELOCIDAD_MEDIA);
            motor_set_speed(2, VELOCIDAD_MEDIA);
            sleep_ms(10); // Avanzar un poco antes de verificar nuevamente

        }else if(data.ir.left){
            direccion_izquierda();
            motor_set_speed(1, 0);
            motor_set_speed(2, VELOCIDAD_MEDIA);
            sleep_ms(10); // estabilidad
        }
        else if(data.ir.right){
            direccion_derecha();
            motor_set_speed(1, VELOCIDAD_MEDIA);
            motor_set_speed(2, 0);
            sleep_ms(10); // estabilidad
        }
        else if(data.ir.back){
            direccion_atras();
            motor_set_speed(1, VELOCIDAD_MEDIA);
            motor_set_speed(2, VELOCIDAD_MEDIA);
            sleep_ms(10); // Retroceder un poco antes de verificar nuevamente
        }
        else {
            direccion_parar();
            motor_set_speed(1, 0);
            motor_set_speed(2, 0);
            sleep_ms(10); // estabilidad
        }

        sleep_ms(20); // estabilidad
    }
    return 0;
}