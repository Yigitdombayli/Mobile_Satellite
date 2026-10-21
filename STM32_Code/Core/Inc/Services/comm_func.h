/*
 * CommunicationFunction.h
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */

#ifndef INC_COMM_FUNC_H_
#define INC_COMM_FUNC_H_

#include <gpio_conf.h>
#include <string.h>
#include <stddef.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "stm32g0xx_ll_gpio.h"
#include "stm32g071xx.h"
#include "stm32g0xx_ll_spi.h"
#include "uart_protocol_defs.h"
#include "protocol_parser.h"
#include "stm32g0xx_ll_usart.h"

uint8_t Transfer_SPI(uint8_t data);
uint8_t SPI_ReadRegister(uint8_t regAddr);
void CS_Low();
void CS_High();
void Send_Telemetry_Frame(TelemetryData_t* telemetry);

#endif /* INC_COMM_FUNC_H_ */
