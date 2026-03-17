/*Programa que ejecuta las instrucciones de la libreria*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "memory.h"
#include "maze.h"

//Inicializacion de X y Y del laberinto, para la memoria 
int pos_x = 0;
int pos_y = 0;
// Definición de la estructura de una celda del laberinto
Cell maze[MAZE_SIZE][MAZE_SIZE];

// Funcion mas inicializadora del laberinto.
void maze_init(void) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j].wall = 0; // Sin paredes
            maze[i][j].visited = 0; // No visitada
        }
    }
}

// Función para establecer una pared en una celda específica
void maze_set_wall(int x, int y, uint8_t wall) {
    if (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE) {
        maze[x][y].wall |= wall;
    }
}

// Función para obtener el estado de las paredes en una celda específica
uint8_t maze_has_wall(int x, int y, uint8_t wall){
    return (maze[x][y].wall & wall);
}