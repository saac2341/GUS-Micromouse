/*Libreria para leer los datos del acelerometro/giroscopio*/

#ifndef ACELEROMETRO_H
#define ACELEROMETRO_H
#include "Default.h"
#include <stdbool.h>
//Estas librerias son para el acelerometro/giroscopio MPU6050, se pueden cambiar por otras dependiendo del modelo que se use
//Descripcion de las funciones que se van a usar para el acelerometro/giroscopio

void acelerometro_init();
void acelerometro_leer(float* ax, float* ay, float* az, float*gx, float* gy, float* gz);

#endif /* ACELEROMETRO_H */
