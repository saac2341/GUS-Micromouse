#include "Encoder.h"
#include "pico/stdlib.h"
#include "Default.h"
#include <math.h>

// Variables de estado del encoder (globales o en estructura)
static struct {
    int left_steps;
    int right_steps;
    int last_left;
    int last_right;
    uint32_t last_time;
} encoder_state = {0};

void encoder_init() {
    gpio_init(ENCODER_LEFT_PIN);
    gpio_set_dir(ENCODER_LEFT_PIN, GPIO_IN);
    gpio_pull_up(ENCODER_LEFT_PIN);
    
    gpio_init(ENCODER_RIGHT_PIN);
    gpio_set_dir(ENCODER_RIGHT_PIN, GPIO_IN);
    gpio_pull_up(ENCODER_RIGHT_PIN);
    
    // Inicializar estado
    encoder_state.last_left = gpio_get(ENCODER_LEFT_PIN);
    encoder_state.last_right = gpio_get(ENCODER_RIGHT_PIN);
    encoder_state.last_time = 0;
}

encoder_data_t encoder_leer(void) {
    encoder_data_t data = {0};  // Inicializar a cero
    
    // Filtrar rebotes (ajustar según necesidad)
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - encoder_state.last_time < 5) {
        // Mantener últimos valores
        data.left_steps = encoder_state.left_steps;
        data.right_steps = encoder_state.right_steps;
        return data;
    }
    encoder_state.last_time = current_time;
    
    // Leer estado actual
    int left_state = gpio_get(ENCODER_LEFT_PIN);
    int right_state = gpio_get(ENCODER_RIGHT_PIN);
    
    // Detectar cambio (flanco)
    if (encoder_state.last_left != left_state) {
        // Determinar dirección basándose en el otro canal
        if (left_state == encoder_state.last_right) {
            encoder_state.left_steps++;
        } else {
            encoder_state.left_steps--;
        }
    }
    
    if (encoder_state.last_right != right_state) {
        if (right_state == left_state) {
            encoder_state.right_steps--;
        } else {
            encoder_state.right_steps++;
        }
    }
    
    encoder_state.last_left = left_state;
    encoder_state.last_right = right_state;
    
    // Calcular distancia (circunferencia, no diámetro)
    float circumference = M_PI * DIAMETER_WHEEL;
    
    data.left_steps = encoder_state.left_steps;
    data.right_steps = encoder_state.right_steps;
    data.left_distance = encoder_state.left_steps * circumference / PULSES_PER_REVOLUTION_INICIAL;
    data.right_distance = encoder_state.right_steps * circumference / PULSES_PER_REVOLUTION_INICIAL;
    
    return data;
}

// Función para reiniciar contadores
void encoder_reset(void) {
    encoder_state.left_steps = 0;
    encoder_state.right_steps = 0;
}