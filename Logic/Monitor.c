/*Programa enfocado en monitorizar el estado del micromouse de todos los sensores y actuadores.
visualizandolos en el puerto seria en forma de tabla*/

#include <stdio.h>
#include "pico/stdlib.h"    
#include "Monitor.h"
#include "Libreria/Acelerometro.h"
#include "Libreria/Encoder.h"
#include "Libreria/SensorInfrarrojo.h"
#include "Memory/maze.h"

//Incluir las librerias necesarias para leer los sensores y actualizar el estado del laberinto.
extern int pos_x;
extern int pos_y;

//Definicion de las paredes en la memoria del laberinto.
#define WALL_FRONT 0x01
#define WALL_RIGHT 0x02
#define WALL_BACK  0x04
#define WALL_LEFT  0x08
//Leer datos de los sensores y almacenarlos en la estructura monitor_data_t.
monitor_data_t monitor_leer_datos(void) {
    monitor_data_t data;
    encoder_data_t encoder_data = encoder_leer();
    acelerometro_data_t acelerometro_data = acelerometro_leer();

    data.encoder_left = encoder_data.left_steps;
    data.encoder_right = encoder_data.right_steps;
    data.distance_left = encoder_data.left_distance;
    data.distance_right = encoder_data.right_distance;
    data.ax = acelerometro_data.ax;
    data.ay = acelerometro_data.ay;
    data.az = acelerometro_data.az;
    data.ir.front = infrarrojo_leer_FRONT();
    data.ir.right = infrarrojo_leer_RIGHT();
    data.ir.back = infrarrojo_leer_BACK();
    data.ir.left = infrarrojo_leer_LEFT();

    return data;
}
void monitor_imprimir(monitor_data_t data) {
        //impresora del estado de los sensores en forma de tabla.
        printf("L:%ld\tR:%ld\tDL:%.2f\tDR:%.2f\tAX:%.2f\tAY:%.2f\tAZ:%.2f\tIR:%d%d%d%d\n",
                data.encoder_left,
                data.encoder_right,
                data.distance_left,
                data.distance_right,
                data.ax,
                data.ay,
                data.az,
                data.ir.left,
                data.ir.right,
                data.ir.front,
                data.ir.back);
}

void monitor_actualizar_laberinto(monitor_data_t d) {
    // Actualizar el estado del laberinto basado en los sensores infrarrojos
    if (d.ir.front) {
        maze_set_wall(pos_x, pos_y, 0x01); // Pared al frente
    }
    if (d.ir.right) {
        maze_set_wall(pos_x, pos_y, 0x02); // Pared a la derecha
    }
    if (d.ir.back) {
        maze_set_wall(pos_x, pos_y, 0x04); // Pared atrás
    }
    if (d.ir.left) {
        maze_set_wall(pos_x, pos_y, 0x08); // Pared a la izquierda
    }
}