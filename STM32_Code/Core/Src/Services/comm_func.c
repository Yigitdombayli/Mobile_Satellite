/*
 * ComminicationFunction.c
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */

#ifndef SRC_COMMINICATIONFUNCTION_C_
#define SRC_COMMINICATIONFUNCTION_C_

#include <comm_func.h>
#include "main.h"
#include "protocol_parser.h"
#include "uart_protocol_defs.h"
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


/**
 * @brief  Calculates the Modbus CRC16 checksum for data integrity verification.
 *
 * @param  data   Pointer to the byte array to be processed.
 * @param  length Number of bytes in the array to calculate the CRC for.
 * @retval        The calculated 16-bit CRC checksum value.
 */
uint16_t Calculate_CRC16(uint8_t *data, uint16_t length) {
    uint16_t crc = 0xFFFF;
    for (uint16_t i = 0; i < length; i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if ((crc & 0x0001) != 0) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

/**
 * @brief  Packages telemetry data into a structured communication frame and transmits it via USART2.
 *
 * This function encapsulates the provided telemetry struct with a start byte, command ID,
 * payload length, CRC16 checksum, and a stop byte. It then transmits the complete frame
 * byte-by-byte over the UART line using STM32 Low-Layer (LL) hardware registers.
 *
 * @param  telemetry Pointer to the telemetry data structure to be transmitted.
 * @retval None
 */
void Send_Telemetry_Frame(TelemetryData_t* telemetry) {
    UartFrame_t txFrame = {0};
    txFrame.startByte = START_BYTE;
    txFrame.commandID = CMD_RES_TELEMETRY;
    txFrame.payloadLength = sizeof(TelemetryData_t);

    memcpy(txFrame.payload, telemetry, txFrame.payloadLength);

    uint16_t crcDataLength = offsetof(UartFrame_t, crc16);
    txFrame.crc16 = Calculate_CRC16((uint8_t*)&txFrame, crcDataLength);

    txFrame.stopByte = STOP_BYTE;

    uint8_t *framePtr = (uint8_t*)&txFrame;
    uint16_t totalLength = sizeof(UartFrame_t);

    for (uint16_t i = 0; i < totalLength; i++) {
        while (!LL_USART_IsActiveFlag_TXE(USART2)) {
        }
        LL_USART_TransmitData8(USART2, framePtr[i]);
    }
}
#endif /* SRC_COMMINICATIONFUNCTION_C_ */
