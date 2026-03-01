/*Libreria para leer los datos del acelerometro/giroscopio*/

#ifndef ACELEROMETRO_H
#define ACELEROMETRO_H
#include "Default.h"
#include <stdbool.h>
//Estas librerias son para el acelerometro/giroscopio MPU6050, se pueden cambiar por otras dependiendo del modelo que se use
//Descripcion de las funciones que se van a usar para el acelerometro/giroscopio

void acelerometro_init();
acelerometro_data_t acelerometro_leer(void);

typedef struct {
    float ax; // Aceleración en el eje x
    float ay; // Aceleración en el eje y
    float az; // Aceleración en el eje z
    float gx; // Velocidad angular en el eje x
    float gy; // Velocidad angular en el eje y
    float gz; // Velocidad angular en el eje z
} acelerometro_data_t;

#endif /* ACELEROMETRO_H */
