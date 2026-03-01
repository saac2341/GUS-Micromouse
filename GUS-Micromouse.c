#include <stdio.h>
#include "pico/stdlib.h"
#include "Libreria/Monitor.h"
#include "Libreria/Acelerometro.h"
#include "Libreria/Encoder.h"
#include "Libreria/SensorInfrarrojo.h"
#include "Libreria/PWM.h"
#include "Libreria/Direccion.h"
#include "Temps/Default.h"

int main()
{
    stdio_init_all();

    // Inicialización
    monitorizar_estado();
    pwm_izquierdo_init();
    pwm_derecho_init();
    direccion_init();

    while (true)
    {
        if(sensor_infrarrojo_leer_FRONT()){
            direccion_adelante();
            pwm_set_izquierdo(VELOCIDAD_MEDIA);
            pwm_set_derecho(VELOCIDAD_MEDIA);
        }
        else if(sensor_infrarrojo_leer_LEFT()){
            direccion_izquierda();
            pwm_set_izquierdo(0);
            pwm_set_derecho(VELOCIDAD_MEDIA);
        }
        else if(sensor_infrarrojo_leer_RIGHT()){
            direccion_derecha();
            pwm_set_izquierdo(VELOCIDAD_MEDIA);
            pwm_set_derecho(0);
        }
        else if(sensor_infrarrojo_leer_BACK()){
            direccion_atras();
            pwm_set_izquierdo(VELOCIDAD_MEDIA);
            pwm_set_derecho(VELOCIDAD_MEDIA);
        }
        else {
            direccion_parar();
            pwm_set_izquierdo(0);
            pwm_set_derecho(0);
        }

        sleep_ms(10); // estabilidad
    }
}