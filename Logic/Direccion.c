/*Programa encargado de gestionar la dirección del micromouse*/

#include "Direccion.h"
#include "pico/stdlib.h"  
#include "Default.h"

/// Inicializa los pines de dirección del micromouse, configurándolos como salidas.
void direccion_init() {
    gpio_init(DIR_LEFT_PIN);
    gpio_set_dir(DIR_LEFT_PIN, GPIO_OUT);
    gpio_put(DIR_LEFT_PIN, 0); // Inicialmente en bajo

    gpio_init(DIR_RIGHT_PIN);
    gpio_set_dir(DIR_RIGHT_PIN, GPIO_OUT);
    gpio_put(DIR_RIGHT_PIN, 0); // Inicialmente en bajo
}
void direccion_izquierda() {
    gpio_put(DIR_LEFT_PIN, 1); // Activar dirección izquierda
    gpio_put(DIR_RIGHT_PIN, 0); // Desactivar dirección derecha
}
void direccion_derecha() {
    gpio_put(DIR_LEFT_PIN, 0); // Desactivar dirección izquierda
    gpio_put(DIR_RIGHT_PIN, 1); // Activar dirección derecha
}
void direccion_frente() {
    gpio_put(DIR_LEFT_PIN, 0); // Desactivar dirección izquierda
    gpio_put(DIR_RIGHT_PIN, 0); // Desactivar dirección derecha
}
void direccion_atras() {
    gpio_put(DIR_LEFT_PIN, 1); // Activar dirección izquierda
    gpio_put(DIR_RIGHT_PIN, 1); // Activar dirección derecha
}
void direccion_parar() {
    gpio_put(DIR_LEFT_PIN, 0); // Desactivar dirección izquierda
    gpio_put(DIR_RIGHT_PIN, 0); // Desactivar dirección derecha
}

