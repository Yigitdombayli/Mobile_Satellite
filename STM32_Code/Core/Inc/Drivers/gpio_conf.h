/*
 * GpioConf.h
 *
 *  Created on: 10 Eki 2026
 *      Author: dombayli
 */
#include "stm32g0xx_ll_gpio.h"
#include "stm32g071xx.h"
#include "stm32g0xx_ll_spi.h"
#include "stm32g0xx_ll_bus.h"
#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_usart.h"

#ifndef INC_GPIOCONF_H_
#define INC_GPIOCONF_H_

/************************************ PIN DEFINES ******************************/
#define SCK_PIN									LL_GPIO_PIN_1			// PA1
#define MOSI_PIN								LL_GPIO_PIN_12			// PA12
#define MISO_PIN								LL_GPIO_PIN_11			// PA11
#define CS_PIN									LL_GPIO_PIN_4			// PA4

void Initialize_GPIO();
void SPI1_Peripheral_Init();
void UART_Peripheral_Init(void);

#endif /* INC_GPIOCONF_H_ */
