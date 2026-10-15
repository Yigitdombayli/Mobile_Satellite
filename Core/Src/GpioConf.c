/*
 * GpioConf.c
 *
 *  Created on: 10 Eki 2026
 *      Author: dombayli
 */
#include "GpioConf.h"


LL_GPIO_InitTypeDef GPIO_InitStruct = {0};


void Initialize_GPIO(){
	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);

	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_DOWN;

	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	// SPI Configuration. SCK Pin -> PA1 ;; MOSI Pin -> PA12 ;; MISO Pin -> PA11
	GPIO_InitStruct.Alternate = LL_GPIO_AF_0;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	GPIO_InitStruct.Pin = LL_GPIO_PIN_1 | LL_GPIO_PIN_11| LL_GPIO_PIN_12;

	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	//CS Pin -> PA4
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;

	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4);
}

void SPI1_Peripheral_Init(void)
{
	 	 LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

	     LL_SPI_InitTypeDef SPI_InitStruct = {0};

	     SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	     SPI_InitStruct.Mode              = LL_SPI_MODE_MASTER;
	     SPI_InitStruct.DataWidth         = LL_SPI_DATAWIDTH_8BIT;
	     SPI_InitStruct.ClockPolarity     = LL_SPI_POLARITY_LOW;
	     SPI_InitStruct.ClockPhase        = LL_SPI_PHASE_1EDGE;
	     SPI_InitStruct.NSS               = LL_SPI_NSS_SOFT;
	     SPI_InitStruct.BaudRate          = LL_SPI_BAUDRATEPRESCALER_DIV256;
	     SPI_InitStruct.BitOrder          = LL_SPI_MSB_FIRST;
	     SPI_InitStruct.CRCCalculation    = LL_SPI_CRCCALCULATION_DISABLE;

	     LL_SPI_Init(SPI1, &SPI_InitStruct);
	     LL_SPI_SetStandard(SPI1, LL_SPI_PROTOCOL_MOTOROLA);
	     LL_SPI_SetRxFIFOThreshold(SPI1, LL_SPI_RX_FIFO_TH_QUARTER);

	     LL_SPI_Enable(SPI1);
}
