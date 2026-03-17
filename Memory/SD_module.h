/*Libreria encargada de ejecutar las funciones basicas del modulo SD de creacion y lectura de los datos*/
#ifndef SD_MODULE_H
#define SD_MODULE_H

//Incluir librerias.
#include <pico/stdlib.h>
#include "fatfs/ff.h"

//Estructura de un check point del laberinto.
typedef struct {
    uint16_t step;
    uint8_t x;
    uint8_t y;
    uint8_t direction;
    uint8_t event;
} Checkpoint_t;

//Funciones para el modulo SD.
bool SD_Init();
bool SD_createFile(const char* filename);
bool SD_write_Checkpoint(Checkpoint_t *cp);
bool SD_save_maze(uint8_t maze[16][16]);
void SD_closeFile();

#endif