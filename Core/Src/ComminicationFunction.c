/*
 * ComminicationFunction.c
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */

#ifndef SRC_COMMINICATIONFUNCTION_C_
#define SRC_COMMINICATIONFUNCTION_C_

#include "CommunicationFunction.h"

/**
 * @brief  Transmits a single byte over SPI1 and receives the response simultaneously (full-duplex).
 * @param  data The 8-bit data byte to be transmitted.
 * @retval The 8-bit data byte received from the SPI slave.
 */
uint8_t Transfer_SPI(uint8_t data){
	while(!LL_SPI_IsActiveFlag_TXE(SPI1));

	LL_SPI_TransmitData8(SPI1, data);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1));

	return LL_SPI_ReceiveData8(SPI1);
}

/**
 * @brief  Reads a single byte of data from the specified register via SPI.
 * @param  regAddr The 8-bit address of the register to be read (including Read/Write flag bit).
 * @retval The 8-bit data byte read from the target register.
 */
uint8_t SPI_ReadRegister(uint8_t regAddr){
	uint8_t receivedData;

	CS_Low();

	for(volatile int i=0; i<200; i++);

	Transfer_SPI(regAddr);
	receivedData = Transfer_SPI(0x00);

	CS_High();
	return receivedData;
}

/**
 * @brief  Asserts the Chip Select line (pulls CS pin LOW) to initiate SPI communication.
 * @retval None
 */
void CS_Low(){
	LL_GPIO_ResetOutputPin(GPIOA, CS_PIN);
}

/**
 * @brief  De-asserts the Chip Select line (pulls CS pin HIGH) to terminate SPI communication.
 * @retval None
 */
void CS_High(){
	LL_GPIO_SetOutputPin(GPIOA, CS_PIN);
}


#endif /* SRC_COMMINICATIONFUNCTION_C_ */
