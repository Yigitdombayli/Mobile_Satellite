/*
 * GpioConf.c
 *
 *  Created on: 10 Eki 2026
 *      Author: dombayli
 */
#include "GpioConf.h"


LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

void Initialize_GPIO(){
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_DOWN;

	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

