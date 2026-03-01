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
/// Lee los datos del acelerómetro y giroscopio, almacenándolos en una estructura de datos.
acelerometro_data_t acelerometro_leer(void) {
    acelerometro_data_t data;
    //Aquí se deben implementar las funciones de lectura específicas para el sensor MPU5060, utilizando la comunicación I2C para obtener los valores de aceleración y velocidad angular en los ejes x, y, z.
    data.ax = ACCELEROMETER_X_PIN;
    data.ay = ACCELEROMETER_Y_PIN;

    //Coreccion para x
    if (data.ax > 0.0) data.ax -= 0.1;
    else data.ax += 0.1;
    //Coreccion para y
    if (data.ay > 0.0) data.ay -= 0.1;
    else data.ay += 0.1;
    return data;
}