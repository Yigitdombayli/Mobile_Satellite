/*
 * MPU6550.c
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */

#include <MPU6500.h>

uint8_t MPU6500_WHO_AM_I(){
    uint8_t data;
    SPI_WriteRegister(0x6A, 0x10);
    for(volatile int i = 0; i < 5000; i++);
    data = SPI_ReadRegister(WHO_AM_I | 0x80);

    return data;
}
/**
 * @brief  Writes a single byte of data to the specified sensor register via SPI.
 * @param  regAddr The 8-bit address of the register to write to. The MSB will be cleared automatically for write mode.
 * @param  data    The 8-bit data byte to be written into the register.
 * @retval None
 */
void SPI_WriteRegister(uint8_t regAddr, uint8_t data) {
    CS_Low();

    Transfer_SPI(regAddr & 0x7F);

    Transfer_SPI(data);

    CS_High();
}

/**
 * @brief  Configures the power management registers to wake up the sensor
 *         and enable all accelerometer and gyroscope axes.
 * @retval None
 */
void MPU6500_Power(){
	uint8_t data;

	data = 0x01; // SLEEP bit = 0, CLKSEL = 001 (Auto-select best clock source)[cite: 3]
	SPI_WriteRegister(PWR_MGMT_1, data);

	data = 0x00; // Enable all accelerometer and gyroscope axes[cite: 3]
	SPI_WriteRegister(PWR_MGMT_2, data);
}
/**
 * @brief  Reads raw 16-bit accelerometer data for X, Y, and Z axes simultaneously using SPI burst read.
 * @param  pAccelX Pointer to store the 16-bit signed raw X-axis data.
 * @param  pAccelY Pointer to store the 16-bit signed raw Y-axis data.
 * @param  pAccelZ Pointer to store the 16-bit signed raw Z-axis data.
 * @retval None
 */
void MPU6500_Read_Accel_All(int16_t *pAccelX, int16_t *pAccelY, int16_t *pAccelZ) {
    uint8_t buffer[6];

    CS_Low();

    Transfer_SPI(ACCEL_XOUT_H | SPI_READ_BIT);

    for (uint8_t i = 0; i < 6; i++) {
        buffer[i] = Transfer_SPI(0x00);
    }

    CS_High();

    *pAccelX = (int16_t)((buffer[0] << 8) | buffer[1]);
    *pAccelY = (int16_t)((buffer[2] << 8) | buffer[3]);
    *pAccelZ = (int16_t)((buffer[4] << 8) | buffer[5]);
}
