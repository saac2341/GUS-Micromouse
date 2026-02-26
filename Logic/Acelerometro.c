/*Programa del control de la logica del sensor MPU5060 de acelerometro*/
//Incluir las librerias necesarias
#include "Acelerometro.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "Default.h"
#include <stdio.h>
/// Inicializa el sensor de acelerómetro MPU5060, configurando el pin correspondiente como entrada con resistencia pull-up.
void acelerometro_init() {
    //Para el eje x
    gpio_init(ACCELEROMETER_X_PIN);
    gpio_set_dir(ACCELEROMETER_X_PIN, GPIO_IN);
    gpio_pull_up(ACCELEROMETER_X_PIN);
    //Para el eje y
    gpio_init(ACCELEROMETER_Y_PIN);
    gpio_set_dir(ACCELEROMETER_Y_PIN, GPIO_IN);
    gpio_pull_up(ACCELEROMETER_Y_PIN);
}

void acelerometro_leer(float* ax, float* ay, float* az, float* gx, float* gy, float* gz) {
    //Esta función se encarga de leer los datos del acelerómetro y giroscopio y almacenarlos en las variables correspondientes
    //En este ejemplo se asignan valores ficticios para ilustrar el funcionamiento
    *ax = 0.0; // Valor del eje x del acelerómetro
    *ay = 0.0; // Valor del eje y del acelerómetro
    *az = 0.0; // Valor del eje z del acelerómetro
    *gx = 0.0; // Valor del eje x del giroscopio
    *gy = 0.0; // Valor del eje y del giroscopio
    *gz = 0.0; // Valor del eje z del giroscopio
}
