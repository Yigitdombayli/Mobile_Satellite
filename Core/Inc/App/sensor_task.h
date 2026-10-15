/*
 * sensor_task.h
 *
 *  Created on: 11 Eki 2026
 *      Author: dombayli
 */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "stm32g0xx_ll_gpio.h"
#include "stm32g071xx.h"
#include "stm32g0xx_ll_spi.h"

#ifndef INC_SENSOR_TASK_H_
#define INC_SENSOR_TASK_H_

extern SemaphoreHandle_t xSemLed1;
extern SemaphoreHandle_t xSemLed2;

void vLed1Task(void *pvParameters);
void vLed2Task(void *pvParameters);

#endif /* INC_SENSOR_TASK_H_ */
