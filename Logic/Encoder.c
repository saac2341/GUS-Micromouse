/*Programa encargado de gestionar el encoder del micromouse y contar los pasos*/

#include "Encoder.h"
#include "pico/stdlib.h"
#include "Default.h"
/// Inicializa los pines del encoder, configurándolos como entradas con resistencia pull-up.
void encoder_init() {
    gpio_init(ENCODER_LEFT_PIN);
    gpio_set_dir(ENCODER_LEFT_PIN, GPIO_IN);
    gpio_pull_up(ENCODER_LEFT_PIN);
s
    gpio_init(ENCODER_RIGHT_PIN);
    gpio_set_dir(ENCODER_RIGHT_PIN, GPIO_IN);
    gpio_pull_up(ENCODER_RIGHT_PIN);
}

/// Lee el estado de los pines del encoder y actualiza los contadores de pasos para cada rueda.
encoder_data_t encoder_leer(void) {
    static int left_steps = 0;
    static int right_steps = 0;
    static float left_distance = 0.0;
    static float right_distance = 0.0;

    // Leer el estado de los pines del encoder
    int left_state = gpio_get(ENCODER_LEFT_PIN);
    int right_state = gpio_get(ENCODER_RIGHT_PIN);

    // Actualizar contadores de pasos
if (last_left == 1 && left_state == 0) left_steps++;
    if (last_right == 1 && right_state == 0) right_steps++;

    last_left = left_state;
    last_right = right_state;

    float wheel_circumference = DIAMETER_WHEEL;
    int pulses_per_revolution = PULSES_PER_REVOLUTION_INICIAL;

    data.left_steps = left_steps;
    data.right_steps = right_steps;
    data.left_distance = left_steps * wheel_circumference / pulses_per_revolution;
    data.right_distance = right_steps * wheel_circumference / pulses_per_revolution;
    return data;
} 