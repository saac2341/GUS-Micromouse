/*Programa enfocado en monitorizar el estado del micromouse de todos los sensores y actuadores.
visualizandolos en el puerto seria en forma de tabla*/

#include <stdio.h>
#include "pico/stdlib.h"    
#include "Monitor.h"
#include "Libreria/Acelerometro.h"
#include "Libreria/Encoder.h"
#include "Libreria/SensorInfrarrojo.h"

void monitorizar_estado(void) {
    //Inicializar los sensores y actuadores
    acelerometro_init();
    encoder_init();
    sensor_infrarrojo_init();

    while (true) {
        // Leer los datos de los sensores
        encoder_data_t encoder_data = encoder_leer();
        acelerometro_data_t acelerometro_data = acelerometro_leer();
        int ir_left = sensor_infrarrojo_leer(IR_LEFT_PIN);
        int ir_right = sensor_infrarrojo_leer(IR_RIGHT_PIN);
        int ir_front = sensor_infrarrojo_leer(IR_FRONT_PIN);
        int ir_back = sensor_infrarrojo_leer(IR_BACK_PIN);
    

        // Visualizar los datos en el puerto serie en forma de tabla
       printf("L_steps\tR_steps\tL_dist\tR_dist\tAX\tAY\tIR\n");
       
       printf("%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n",
        encoder_data.left_steps, encoder_data.right_steps,
        encoder_data.left_distance, encoder_data.right_distance,
        acelerometro_data.ax, acelerometro_data.ay,
        ir_left + ir_right + ir_front + ir_back);
        sleep_ms(500); // Esperar medio segundo antes de la siguiente lectura
    }
}