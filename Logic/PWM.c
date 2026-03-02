// PWM.c
#include "PWM.h"
#include "Default.h"
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

//variables para slinces.
uint slice_left;
uint slice_right;

void motores_init(void){
    //Configuracion de pines con PWM.
    gpio_set_function(MOTOR_LEFT_PWM_PIN, GPIO_FUNC_PWM);
    gpio_set_function(MOTOR_RIGHT_PWM_PIN, GPIO_FUNC_PWM);

    //Configurar slices de PWM para cada motor.
    slice_left = pwm_gpio_to_slice_num(MOTOR_LEFT_PWM_PIN);
    slice_right = pwm_gpio_to_slice_num(MOTOR_RIGHT_PWM_PIN);

    //Configuracion de PWM.
    pwm_set_wrap(slice_left, PWM_MAX_DUTY_CYCLE);
    pwm_set_wrap(slice_right, PWM_MAX_DUTY_CYCLE);

    pwm_set_clkdiv(slice_left, PWM_FREQUENCY);
    pwm_set_clkdiv(slice_right, PWM_FREQUENCY);

    ///iNICIALIZAR EN 0.
    pwm_set_chan_level(slice_left, pwm_gpio_to_channel(MOTOR_LEFT_PWM_PIN), 0);
    pwm_set_chan_level(slice_right, pwm_gpio_to_channel(MOTOR_RIGHT_PWM_PIN), 0);

    //Habilitar PWM.
    pwm_set_enabled(slice_left, true);
    pwm_set_enabled(slice_right, true);
}

void motor_set_speed(uint motor, float speed){
    if(speed < 0) speed = 0;
    if(speed > VELOCIDAD_MAX) speed = VELOCIDAD_MAX;

    uint level= (uint)(speed * PWM_MAX_DUTY_CYCLE / VELOCIDAD_MAX);
    if (motor == 1) { // Motor izquierdo
        pwm_set_chan_level(slice_left, pwm_gpio_to_channel(MOTOR_LEFT_PWM_PIN), level);
    } else if (motor == 2) { // Motor derecho
        pwm_set_chan_level(slice_right, pwm_gpio_to_channel(MOTOR_RIGHT_PWM_PIN), level);
    }
}
