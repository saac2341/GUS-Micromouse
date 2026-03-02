/*Libreria enfocadad a la base de datos desde el monitor*/

#ifndef MAXE_H
#define MAXE_H
#include <stdio.h>
#define MAZE_SIZE 16
// Definición de la estructura de una celda del laberinto
typedef struct{
    uint8_t wall;
    uint8_t visited;
}Cell;

// Definición de la estructura del laberinto
extern Cell maze[MAZE_SIZE][MAZE_SIZE];
// Funciones para manipular el laberinto
void maze_init();
void maze_set_wall(int x, int y, uint8_t wall);
uint8_t maze_get_wall(int x, int y);
#endif /* MAXE_H */