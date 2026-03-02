/*Programa del control de la logica del sensor MPU5060 de acelerometro*/
//Incluir las librerias necesarias
#include "Acelerometro.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "Default.h"
#include <stdio.h>

#define I2C_PORT i2c0
#define MPU6050_ADDR 0x68


void acelerometro_init() {
    // Inicializar el I2C
    i2c_init(I2C_PORT, 400*1000); // Configurar a 400 kHz
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SCL_PIN);
    gpio_pull_up(SDA_PIN);

    // Verificar la conexión con el MPU6050
    uint8_t buf[2];
    buf[0] = 0x6B; // Registro de identificación del dispositivo
    buf[1] = 0x00; // Valor esperado para el MPU6050

    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, buf, 2, false);
}

acelerometro_data_t acelerometro_leer(void) {
    acelerometro_data_t data;

    // Leer los datos de aceleración del MPU6050
    uint8_t reg= 0x3B; // Registro de aceleración en el eje x
    uint8_t buf[6];
    i2c_write_blocking(I2C_PORT, MPU6050_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, MPU6050_ADDR, buf, 6, false);

    int16_t ax = (buf[0] << 8) | buf[1];
    int16_t ay = (buf[2] << 8) | buf[3];
    int16_t az = (buf[4] << 8) | buf[5];
    // Convertir los valores a g (gravedad)
    data.ax = ax / 16384.0f;
    data.ay = ay / 16384.0f;
    data.az = az / 16384.0f;
    
    return data;
}