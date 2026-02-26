/*Esta libreria se encargara del control del PWM de los motores*/
#ifndef PWM_H
#define PWM_H
#include "pico/stdlib.h"
#include "hardware/pwm.h"
/// Control de PWM para los motores.
void pwm_izquierdo_init();

void pwm_derecho_init();

#endif /* PWM_H */