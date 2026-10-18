/*
 * MPU6550.h
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */

#ifndef INC_MPU6500_DRIVER_H_
#define INC_MPU6500_DRIVER_H_

#include <comm_func.h>
#include "stm32g071xx.h"
#include "stm32g0xx_ll_spi.h"

#define SPI_READ_BIT 0x80


/***************************** REGISTER MAPPING **************************/

/* Configuration Registers */
#define SMPLRT_DIV           0x19  // Sample rate divider
#define CONFIG               0x1A  // General configuration
#define GYRO_CONFIG          0x1B  // Gyroscope configuration
#define ACCEL_CONFIG         0x1C  // Accelerometer configuration
#define ACCEL_CONFIG_2       0x1D  // Accelerometer configuration 2
#define FIFO_EN              0x23  // FIFO enable

/* Interrupt Registers */
#define INT_PIN_CFG          0x37  // Interrupt pin / bypass enable configuration
#define INT_ENABLE           0x38  // Interrupt enable
#define INT_STATUS           0x3A  // Interrupt status

/* Accelerometer Data Registers */
#define ACCEL_XOUT_H         0x3B  // Accelerometer X-axis high byte
#define ACCEL_XOUT_L         0x3C  // Accelerometer X-axis low byte
#define ACCEL_YOUT_H         0x3D  // Accelerometer Y-axis high byte
#define ACCEL_YOUT_L         0x3E  // Accelerometer Y-axis low byte
#define ACCEL_ZOUT_H         0x3F  // Accelerometer Z-axis high byte
#define ACCEL_ZOUT_L         0x40  // Accelerometer Z-axis low byte

/* Temperature Data Registers */
#define TEMP_OUT_H           0x41  // Temperature high byte
#define TEMP_OUT_L           0x42  // Temperature low byte

/* Gyroscope Data Registers */
#define GYRO_XOUT_H          0x43  // Gyroscope X-axis high byte
#define GYRO_XOUT_L          0x44  // Gyroscope X-axis low byte
#define GYRO_YOUT_H          0x45  // Gyroscope Y-axis high byte
#define GYRO_YOUT_L          0x46  // Gyroscope Y-axis low byte
#define GYRO_ZOUT_H          0x47  // Gyroscope Z-axis high byte
#define GYRO_ZOUT_L          0x48  // Gyroscope Z-axis low byte

/* System / Power Management Registers */
#define SIGNAL_PATH_RESET    0x68  // Signal path reset
#define USER_CTRL            0x6A  // User control
#define PWR_MGMT_1           0x6B  // Power management 1
#define PWR_MGMT_2           0x6C  // Power management 2

/* FIFO & ID Registers */
#define FIFO_COUNT_H         0x72  // FIFO count high byte[cite: 3]
#define FIFO_COUNT_L         0x73  // FIFO count low byte[cite: 3]
#define FIFO_R_W             0x74  // FIFO read/write[cite: 3]
#define WHO_AM_I             0x75  // Device ID[cite: 3]

uint8_t MPU6500_WHO_AM_I();
void MPU6500_Power();
void MPU6500_Read_Accel_All(int16_t *pAccelX, int16_t *pAccelY, int16_t *pAccelZ);
void SPI_WriteRegister(uint8_t regAddr, uint8_t data);
#endif /* INC_MPU6500_DRIVER_H_ */
