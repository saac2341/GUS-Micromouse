/*Logica para la gestion de la memoria SD*/

///Libreiras.
#include "SD_module.h"
#include "hardware/spi.h"
#include "Temps/Default.h"
#include <stdio.h>
#include <string.h>

//Variables globales.
static FATFS fs; // Sistema de archivos
static FIL file; // Archivo para escribir los checkpoints

//Iniciado de memoria SD.
bool SD_Init(){
    spi_init(spi0, 1000 * 1000); // Inicializar SPI a 1 MHz
    gpio_set_function(SD_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(SD_MOSI_PIN, GPIO_FUNC_SPI);
    gpio_set_function(SD_MISO_PIN, GPIO_FUNC_SPI);

    gpio_init(SD_CS_PIN);
    gpio_set_dir(SD_CS_PIN, GPIO_OUT);
    gpio_put(SD_CS_PIN, 1); // Desactivar el chip select

    FRESULT fr;
    fr = f_mount(&fs, "", 1); // Montar el sistema de archivos
    if (fr != FR_OK) {
        return false;
    }
    return true;
}

//Crear un nuevo archivo para guardar los checkpoints.
bool SD_createFile(const char* filename) {
    FRESULT fr;
    fr = f_open(&file, filename, FA_CREATE_ALWAYS | FA_WRITE);
    if (fr != FR_OK) {
        return false;
        return false;
    }
    return true;
}

//Escribir un checkpoint en el archivo.
bool SD_write_Checkpoint(Checkpoint_t *cp) {
    char buffer[64];
    UNIT bw;

    sprintf (buffer, "%d,%d,%d,%d,%d\n", 
        cp->step, cp->x, cp->y, cp->direction, cp->event);
    
        if (f_write(&file, buffer, strlen(buffer), &bw) != FR_OK) {
        return false;
        }
        return true;
}

//Guardar el estado del laberinto en el archivo.
bool SD_save_maze(uint8_t maze[16][16]) {
    FIL maze_file;
    UNIT bw;

    if (f_open(&maze_file, "maze.txt", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK) {
        return false;
    }
    char line[64];
    for (int y=0 ; y<16 ; y++){
        for (int x=0 ; x <16 ; x++){
            sprintf(line, "%d ", maze[y][x]);
            f_write(&maze_file, line, strlen(line), &bw);
        }
        f_write(&maze_file, "\n", 1, &bw);
    }
    f_close(&maze_file);
    return true;
}

//Cerrar el archivo.
void SD_closeFile() {
    f_close(&file);
}
