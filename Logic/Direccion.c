/*Programa encargado de gestionar la dirección del micromouse a traves de los pines del puente h*/

#include "Direccion.h"
#include "pico/stdlib.h"  
#include "Default.h"

/// Inicializa los pines de dirección del micromouse, configurándolos como salidas.
void direccion_init() {
    gpio_init(MOTOR_LEFT_DIR_PIN);
    gpio_set_dir(MOTOR_LEFT_DIR_PIN, GPIO_OUT);
    gpio_put(MOTOR_LEFT_DIR_PIN, 0); // Inicialmente en bajo

    gpio_init(MOTOR_RIGHT_DIR_PIN);
    gpio_set_dir(MOTOR_RIGHT_DIR_PIN, GPIO_OUT);
    gpio_put(MOTOR_RIGHT_DIR_PIN, 0); // Inicialmente en bajo
}
void direccion_izquierda() {
    gpio_put(MOTOR_LEFT_DIR_PIN, 1); // Activar dirección izquierda
    gpio_put(MOTOR_RIGHT_DIR_PIN, 0); // Desactivar dirección derecha
}
void direccion_derecha() {
    gpio_put(MOTOR_LEFT_DIR_PIN, 0); // Desactivar dirección izquierda
    gpio_put(MOTOR_RIGHT_DIR_PIN, 1); // Activar dirección derecha
}
void direccion_frente() {
    gpio_put(MOTOR_LEFT_DIR_PIN, 0); // Desactivar dirección izquierda
    gpio_put(MOTOR_RIGHT_DIR_PIN, 0); // Desactivar dirección derecha
}
void direccion_atras() {
    gpio_put(MOTOR_LEFT_DIR_PIN, 1); // Activar dirección izquierda
    gpio_put(MOTOR_RIGHT_DIR_PIN, 1); // Activar dirección derecha
}
void direccion_parar() {
    gpio_put(MOTOR_LEFT_DIR_PIN, 0); // Desactivar dirección izquierda
    gpio_put(MOTOR_RIGHT_DIR_PIN, 0); // Desactivar dirección derecha
}

