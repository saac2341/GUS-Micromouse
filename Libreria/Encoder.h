/*Programa para el control de encoders*/

#ifndef ENCODER_H
#define ENCODER_H
#include "Default.h"
//Descripción de las funciones que se van a usar para el encoder
void encoder_init();

encoder_data_t encoder_leer(void);

typedef struct {
    int left_steps; // Contador de pasos para la rueda izquierda
    int right_steps; // Contador de pasos para la rueda derecha
    float left_distance; // Distancia recorrida por la rueda izquierda en cm
    float right_distance; // Distancia recorrida por la rueda derecha en cm
} encoder_data_t;

#endif /* ENCODER_H */
