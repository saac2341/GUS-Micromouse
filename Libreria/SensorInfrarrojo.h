/*Libreria encargada de manejar los sensores infrarrojos del micromouse*/
#ifndef SENSORINFRARROJO_H
#define SENSORINFRARROJO_H
#include "Default.h"
#include <stdbool.h>

void sensor_infrarrojo_init_BACK();
bool sensor_infrarrojo_leer_BACK();

void sensor_infrarrojo_init_FRONT();
bool sensor_infrarrojo_leer_FRONT();

void sensor_infrarrojo_init_LEFT();
bool sensor_infrarrojo_leer_LEFT();

void sensor_infrarrojo_init_RIGHT();
bool sensor_infrarrojo_leer_RIGHT();

#endif

