/*Esta libreria se encargara del control del PWM de los motores*/
#ifndef PWM_H
#define PWM_H
#include "pico/stdlib.h"
#include "Temps/Default.h"
/// Inicializacion de motores.
void motores_init(void);

///Control de velocidad del motor.
void motor_set_speed(uint motor, float speed);

#endif /* PWM_H */
