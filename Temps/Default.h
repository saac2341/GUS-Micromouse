/*Libreria encargada de asignar pines a los componentes y valores de configuración*/
#ifndef DEFAULF_H
#define DEFAULF_H
//Definición de pines para sensor infrarrojo
#define IR_LEFT_PIN 15
#define IR_RIGHT_PIN 14
#define IR_FRONT_PIN 13
#define IR_BACK_PIN 12
//Definición de pwm para motores
#define MOTOR_LEFT_PWM_PIN 5    
#define MOTOR_RIGHT_PWM_PIN 6
//Definicion de acerelometro
#define SCL_PIN 17
#define SDA_PIN 16
//Definición de pines para encoders
#define ENCODER_LEFT_PIN_A 2
#define ENCODER_LEFT_PIN_B 1
#define ENCODER_RIGHT_PIN_A 4
#define ENCODER_RIGHT_PIN_B 3
//Definicion de pines para puente h
#define MOTOR_LEFT_DIR_PIN 7
#define MOTOR_RIGHT_DIR_PIN 8
//De valores de configuracion estandar para el PWM de ambos motores
#define PWM_FREQUENCY 125 // Frecuencia de PWM en Hz
#define PWM_MAX_DUTY_CYCLE 1000 // Valor máximo de ciclo de trabajo para 16 bits

#define DIAMETER_WHEEL 20.0 // Diámetro de la rueda en cm
#define PULSES_PER_REVOLUTION_INICIAL 20 // Número de pulsos por revolución del encoder

//Definicion de velocidad para el PWM.
#define VELOCIDAD_MAX PWM_MAX_DUTY_CYCLE // Valor de ciclo de trabajo para el 50% de velocidad   
#define VELOCIDAD_MEDIA (PWM_MAX_DUTY_CYCLE / 2) // Valor de ciclo de trabajo para el 75% de velocidad
#define VELOCIDAD_BAJA (PWM_MAX_DUTY_CYCLE / 4) // Valor de ciclo de trabajo para el 25% de velocidad

#endif
