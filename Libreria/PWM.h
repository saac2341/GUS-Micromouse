/*Esta libreria se encargara del control del PWM de los motores*/
#ifndef PWM_H
#define PWM_H
#include "pico/stdlib.h"
#include "Temps/Default.h"
/// Definiciones de pines y parámetros para el control del PWM. 
/// Control de PWM para los motores.
void pwm_izquierdo_init();
void pwm_derecho_init();

void pwm_set_izquierdo(uint16_t duty_cycle);
void pwm_set_derecho(uint16_t duty_cycle);
#endif /* PWM_H */