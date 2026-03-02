/*Programa enfocado en monitorizar el estado del micromouse de todos los sensores y actuadores.
visualizandolos en el puerto seria en forma de tabla*/

#include <stdio.h>
#include "pico/stdlib.h"    
#include "Monitor.h"
#include "Libreria/Acelerometro.h"
#include "Libreria/Encoder.h"
#include "Libreria/SensorInfrarrojo.h"

void monitorizar_estado(void) {
    while (true) {
        // Leer los datos de los sensores
        encoder_data_t encoder_data = encoder_leer();
        acelerometro_data_t acelerometro_data = acelerometro_leer();
        bool ir_left  = infrarrojo_leer_LEFT();
        bool ir_right = infrarrojo_leer_RIGHT();
        bool ir_front = infrarrojo_leer_FRONT();
        bool ir_back  = infrarrojo_leer_BACK();

        //impresora del estado de los sensores en forma de tabla.
        printf("L:%ld\tR:%ld\tDL:%.2f\tDR:%.2f\tAX:%.2f\tAY:%.2f\tAZ:%.2f\tIR:%d%d%d%d\n",
                encoder_data.left_steps,
                encoder_data.right_steps,
                encoder_data.left_distance,
                encoder_data.right_distance,
                acelerometro_data.ax,
                acelerometro_data.ay,
                acelerometro_data.az,
                ir_left,
                ir_right,
                ir_front,
                ir_back);

        sleep_ms(100); // Ajusta el tiempo de actualización según tus necesidades
    }
}