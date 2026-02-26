/*Programa encargado de gestionar el encoder del micromouse y contar los pasos*/

#include "Encoder.h"
#include "pico/stdlib.h"
#include "Default.h"
/// Inicializa los pines del encoder, configurándolos como entradas con resistencia pull-up.
void encoder_init() {
    gpio_init(ENCODER_LEFT_PIN);
    gpio_set_dir(ENCODER_LEFT_PIN, GPIO_IN);
    gpio_pull_up(ENCODER_LEFT_PIN);

    gpio_init(ENCODER_RIGHT_PIN);
    gpio_set_dir(ENCODER_RIGHT_PIN, GPIO_IN);
    gpio_pull_up(ENCODER_RIGHT_PIN);
}
/// Lee el estado de los pines del encoder y actualiza los contadores de pasos para cada rueda.
void encoder_leer(int* left_steps, int* right_steps) {
    // Leer el estado de los pines del encoder
    int left_state = gpio_get(ENCODER_LEFT_PIN);
    int right_state = gpio_get(ENCODER_RIGHT_PIN);

    // Actualizar los contadores de pasos según el estado de los pines
    if (left_state == 0) {
        (*left_steps)++; // Incrementar contador de pasos para la rueda izquierda
    }
    if (right_state == 0) {
        (*right_steps)++; // Incrementar contador de pasos para la rueda derecha
    }
    //Transformas los contadores de pasos en distancia recorrida utilizando la fórmula: distancia = pasos * circunferencia de la rueda / número de pulsos por revolución.
    //En este ejemplo se asume una circunferencia de rueda de 20 cm y 20 pulsos por revolución
    float wheel_circumference = 20.0; // Circunferencia de la rueda en cm
    int pulses_per_revolution = 20; // Número de pulsos por revolución  
    float left_distance = (*left_steps) * wheel_circumference / pulses_per_revolution; // Distancia recorrida por la rueda izquierda en cm
    float right_distance = (*right_steps) * wheel_circumference / pulses_per_revolution; // Distancia recorrida por la rueda derecha en cm
}