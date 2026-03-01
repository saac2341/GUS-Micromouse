/*Programacion principal de GUS-Micromouse*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "Libreria/Monitor.h"
#include "Libreria/Acelerometro.h"
#include "Libreria/Encoder.h"
#include "Libreria/SensorInfrarrojo.h"
#include "Liberia/Motor.h"
#include "Temps/Default.h"


int main()
{
    stdio_init_all();
    //Inicializar de librerias.
    monitorizar_estado();
    pwm_izquierdo_init();
    pwm_derecho_init();

    //Lectura de sensores infrarrojos.
    ir_izquierdo_leer = sensor_infrarrojo_leer_LEFT;
    ir_derecho_leer = sensor_infrarrojo_leer_RIGHT; 
    ir_frontal_leer = sensor_infrarrojo_leer_FRONT;
    ir_trasero_leer = sensor_infrarrojo_leer_BACK;
    //Logica del control del micromouse.
    if(sensor_infrarrojo_leer_FRONT()==1){
        direccion_frente();
        pwm_set_izquierdo(VELOCIDAD_MEDIA);
        pwm_set_derecho(VELOCIDAD_MEDIA);
        } else if(sensor_infrarrojo_leer_LEFT()==1){
            direccion_izquierda();
            pwm_set_izquierdo(VELOCIDAD_MEDIA);
            pwm_set_derecho(VELOCIDAD_MEDIA);
        } else if(sensor_infrarrojo_leer_RIGHT()==1){
            direccion_derecha();
            pwm_set_izquierdo(VELOCIDAD_MEDIA);
            pwm_set_derecho(VELOCIDAD_MEDIA);
        } else if(sensor_infrarrojo_leer_BACK()==1){
            direccion_atras();
            pwm_set_izquierdo(VELOCIDAD_MEDIA);
            pwm_set_derecho(VELOCIDAD_MEDIA);
        } else {
            direccion_parar();
            pwm_set_izquierdo(0);
            pwm_set_derecho(0);
    }    return 0;
    void monitorizar_estado(void);
}
