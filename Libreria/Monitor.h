/*librerioa en cargada de monitorizar el estado del micromouse en
la memoria flash se borran cuando se apaga el pico*/
#ifndef MONITOR_H
#define MONITOR_H
#include "Temps/Default.h"
#include "stdbool.h"
#include "stdint.h"

//Definir x_pos y y_pos como variables externas para mantener la posición actual del micromouse en el laberinto.
extern int pos_x;
extern int pos_y;
//Estructura para sensores ir.
typedef struct{
    bool front;
    bool right;
    bool back;
    bool left;
}ir_data_t;
//Estructura para el sistema.
typedef struct{
    ir_data_t ir;
    long encoder_left;
    long encoder_right;
    float dist_left;
    float dist_right;
    float ax;
    float ay;
    float az;
}monitor_data_t;

//Funcion para leer los datos de los sensores y almacenarlos en la estructura monitor_data_t.
monitor_data_t monitor_leer_datos(void);

// Función para imprimir el estado del micromouse
void monitor_imprimir(monitor_data_t data);

// Funcion para actualizar el estado del laberinto desde el monitor.
void monitor_actualizar_laberinto(monitor_data_t data);
<<<<<<< HEAD
#endif /* MONITOR_H */
=======
#endif
>>>>>>> d22cfb466c89b98ae95b4d76a1866a732c0d705c
