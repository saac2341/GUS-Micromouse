#include "Encoder.h"
#include "pico/stdlib.h"
#include "Default.h"
#include "hardware/gpio.h"
#include "hardware/sync.h"
#include <math.h>

// Variables globales para contar los pasos de cada encoder
static struct{
volatile int32_t left_steps;
volatile int32_t right_steps;

uint8_t last_left_A;
uint8_t last_right_A;

} encoder_state={0};

//Callback para manejar las interrupciones de los encoders.
void encoder_callback(uint gpio, uint32_t events){
    if(gpio == ENCODER_LEFT_PIN_A){ //motor izquierdo
        uint8_t A = gpio_get(ENCODER_LEFT_PIN_A);
        uint8_t B = gpio_get(ENCODER_LEFT_PIN_B);
        if(A != encoder_state.last_left_A){
            if(B == A){
                encoder_state.left_steps++;
            }else{
                encoder_state.left_steps--;
            }
            encoder_state.last_left_A = A;
        }
    }else if(gpio == ENCODER_RIGHT_PIN_A){//motor derecho
        uint8_t A = gpio_get(ENCODER_RIGHT_PIN_A);
        uint8_t B = gpio_get(ENCODER_RIGHT_PIN_B);
        if(A != encoder_state.last_right_A){
            if(B == A){
                encoder_state.right_steps++;
            }else{
                encoder_state.right_steps--;
            }
            encoder_state.last_right_A = A;
        }
    }
}
//Inicializacion.
void encoder_init(void){
    //Motor izquierdo
    gpio_init(ENCODER_LEFT_PIN_A);
    gpio_set_dir(ENCODER_LEFT_PIN_A, GPIO_IN);
    gpio_pull_up(ENCODER_LEFT_PIN_A);

    gpio_init(ENCODER_LEFT_PIN_B);
    gpio_set_dir(ENCODER_LEFT_PIN_B, GPIO_IN); 
    gpio_pull_up(ENCODER_LEFT_PIN_B);

    //Motor derecho
    gpio_init(ENCODER_RIGHT_PIN_A);
    gpio_set_dir(ENCODER_RIGHT_PIN_A, GPIO_IN);
    gpio_pull_up(ENCODER_RIGHT_PIN_A);

    gpio_init(ENCODER_RIGHT_PIN_B);
    gpio_set_dir(ENCODER_RIGHT_PIN_B, GPIO_IN);
    gpio_pull_up(ENCODER_RIGHT_PIN_B);

    //guardar el estado inicial de los encoders
    encoder_state.last_left_A = gpio_get(ENCODER_LEFT_PIN_A);
    encoder_state.last_right_A = gpio_get(ENCODER_RIGHT_PIN_A);

    //arctivar interrupciones para flancos 
    gpio_set_irq_enabled_with_callback(
        ENCODER_LEFT_PIN_A,
        GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL,
        true,
        &encoder_callback
    );
    gpio_set_irq_enabled_with_callback(
        ENCODER_RIGHT_PIN_A,
        GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL,
        true,
        &encoder_callback
    );
}



//Lectura de los encoders, devuelve una estructura con los pasos y distancia recorrida por cada rueda.
encoder_data_t encoder_leer(void){
    encoder_data_t data;
    
    int32_t left;
    int32_t right;

    //Desactivar interrupciones.
    uint32_t save= save_and_disable_interrupts();

    left = encoder_state.left_steps;
    right = encoder_state.right_steps;

    restore_interrupts(save);
    float circuference = M_PI * DIAMETER_WHEEL; // Circunferencia de la rueda en cm
    data.left_steps = left;
    data.right_steps = right;

    data.left_distance = (left *circuference) / PULSES_PER_REVOLUTION_INICIAL; // Distancia recorrida por la rueda izquierda en cm
    data.right_distance = (right * circuference) / PULSES_PER_REVOLUTION_INICIAL; // Distancia recorrida por la rueda derecha en cm

    return data;
}

//reset.
void encoder_reset(void){
    uint32_t save = save_and_disable_interrupts();
    encoder_state.left_steps = 0;
    encoder_state.right_steps = 0;
    restore_interrupts(save);
}
