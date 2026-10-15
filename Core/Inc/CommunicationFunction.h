/*
 * CommunicationFunction.h
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */

#ifndef INC_COMMUNICATIONFUNCTION_H_
#define INC_COMMUNICATIONFUNCTION_H_

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "stm32g0xx_ll_gpio.h"
#include "stm32g071xx.h"
#include "stm32g0xx_ll_spi.h"
#include "GpioConf.h"

uint8_t Transfer_SPI(uint8_t data);
uint8_t SPI_ReadRegister(uint8_t regAddr);
void CS_Low();
void CS_High();

#endif /* INC_COMMUNICATIONFUNCTION_H_ */
