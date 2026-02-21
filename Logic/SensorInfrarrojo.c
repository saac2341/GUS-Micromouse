/*Progrma encargado de manejar los sensores infrarrojos del micromouse*/
#include "SensorInfrarrojo.h"
#include "pico/stdlib.h"
#include "Default.h"

/// Inicializa el sensor infrarrojo trasero, configurando el pin correspondiente como entrada con resistencia pull-up.
void sensor_infrarrojo_init_BACK() {
    gpio_init(IR_BACK_PIN);
    gpio_set_dir(IR_BACK_PIN, GPIO_IN);
    gpio_pull_up(IR_BACK_PIN);
}

bool infrarrojo_leer_BACK(){
    return !gpio_get(IR_BACK_PIN);
}
/// Inicializa el sensor infrarrojo frontal, configurando el pin correspondiente como entrada con resistencia pull-up.
void sensor_infrarrojo_init_FRONT() {
    gpio_init(IR_FRONT_PIN);
    gpio_set_dir(IR_FRONT_PIN, GPIO_IN);
    gpio_pull_up(IR_FRONT_PIN);
}

bool infrarrojo_leer_FRONT(){
    return !gpio_get(IR_FRONT_PIN);
}
/// Inicializa el sensor infrarrojo izquierdo, configurando el pin correspondiente como entrada con resistencia pull-up.
void sensor_infrarrojo_init_LEFT() {
    gpio_init(IR_LEFT_PIN);
    gpio_set_dir(IR_LEFT_PIN, GPIO_IN);
    gpio_pull_up(IR_LEFT_PIN);
}

bool infrarrojo_leer_LEFT(){
    return !gpio_get(IR_LEFT_PIN);
}
/// Inicializa el sensor infrarrojo derecho, configurando el pin correspondiente como entrada con resistencia pull-up.
void sensor_infrarrojo_init_RIGHT() {
    gpio_init(IR_RIGHT_PIN);
    gpio_set_dir(IR_RIGHT_PIN, GPIO_IN);
    gpio_pull_up(IR_RIGHT_PIN);
}

bool infrarrojo_leer_RIGHT(){
    return !gpio_get(IR_RIGHT_PIN);
}
