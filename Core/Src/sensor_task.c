/*
 * sensor_task.c
 *
 *  Created on: 11 Eki 2026
 *      Author: dombayli
 */
#include "stm32g0xx_ll_gpio.h"
#include "stm32g071xx.h"

#include "sensor_task.h"

void vLed1Task(void *pvParameters){
	for(; ;){
		if(xSemaphoreTake(xSemLed1 , portMAX_DELAY) == pdTRUE)
		{
			LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
			LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_1);
			vTaskDelay(pdMS_TO_TICKS(1000));
			xSemaphoreGive(xSemLed2);
		}
	}
}
void vLed2Task(void *pvParameters){
	for(; ;){
		if(xSemaphoreTake(xSemLed2 , portMAX_DELAY) == pdTRUE)
		{
			LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
			LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);
			vTaskDelay(pdMS_TO_TICKS(1000));
			xSemaphoreGive(xSemLed1);
		}
	}
}

