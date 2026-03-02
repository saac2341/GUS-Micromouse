#include <stdio.h>
#include "pico/stdlib.h"
#include "Libreria/Monitor.h"
#include "Libreria/Acelerometro.h"
#include "Libreria/Encoder.h"
#include "Libreria/SensorInfrarrojo.h"
#include "Libreria/PWM.h"
#include "Libreria/Direccion.h"
#include "Temps/Default.h"

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
        monitorizar_estado();
        if(infrarrojo_leer_FRONT()){
            direccion_adelante();
            motor_set_speed(1, VELOCIDAD_MEDIA);
            motor_set_speed(2, VELOCIDAD_MEDIA);
            sleep_ms(10); // Avanzar un poco antes de verificar nuevamente

        }else if(infrarrojo_leer_LEFT()){
            direccion_izquierda();
            motor_set_speed(1, 0);
            motor_set_speed(2, VELOCIDAD_MEDIA);
            sleep_ms(10); // estabilidad
        }
        else if(infrarrojo_leer_RIGHT()){
            direccion_derecha();
            motor_set_speed(1, VELOCIDAD_MEDIA);
            motor_set_speed(2, 0);
            sleep_ms(10); // estabilidad
        }
        else if(infrarrojo_leer_BACK()){
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

        sleep_ms(10); // estabilidad
    }
    return 0;
}