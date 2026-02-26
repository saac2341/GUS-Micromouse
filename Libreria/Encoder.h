/*Libreria para la lectura del encoder*/

#ifndef ENCODER_H
#define ENCODER_H  
#include "pico/stdlib.h"
/// Control del encoder para medir la velocidad de las ruedas.
void encoder_izquierdo_init();
void encoder_derecho_init();
void encoder_izquierdo_leer(int* velocidad);
void encoder_derecho_leer(int* velocidad);
#endif /* ENCODER_H */
