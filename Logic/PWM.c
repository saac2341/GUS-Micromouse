/*Logica para el control del PWM de los motores*/
//Incluir las librerias necesarias
#include "PWM.h"
#include "Default.h"
/// Inicializa el PWM para el motor izquierdo, configurando el pin correspondiente y estableciendo la frecuencia.
void pwm_izquierdo_init() {
    // Configurar el pin de PWM para el motor izquierdo
    gpio_set_function(MOTOR_LEFT_PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(MOTOR_LEFT_PWM_PIN);
    pwm_set_wrap(slice_num, PWM_MAX_DUTY_CYCLE);
    pwm_set_clkdiv(slice_num, (float)clock_get_hz(clk_sys) / (PWM_FREQUENCY * (PWM_MAX_DUTY_CYCLE + 1)));
    pwm_set_enabled(slice_num, true);
}
/// Inicializa el PWM para el motor derecho, configurando el pin correspondiente y estableciendo la frecuencia.
void pwm_derecho_init() {
    // Configurar el pin de PWM para el motor derecho
    gpio_set_function(MOTOR_RIGHT_PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(MOTOR_RIGHT_PWM_PIN);
    pwm_set_wrap(slice_num, PWM_MAX_DUTY_CYCLE);
    pwm_set_clkdiv(slice_num, (float)clock_get_hz(clk_sys) / (PWM_FREQUENCY * (PWM_MAX_DUTY_CYCLE + 1)));
    pwm_set_enabled(slice_num, true);
}
