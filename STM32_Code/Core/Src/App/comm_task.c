/*
 * CommunicationTask.c
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */
#include <comm_task.h>
#include "stm32g0xx_ll_spi.h"


// Tek bir karakter gönderme fonksiyonu
void UART_SendChar(char ch) {
    // TX buffer'ı boşalana kadar bekle (G0 serisi için TXE_TXFNF veya TXE bayrağı)
    while (!LL_USART_IsActiveFlag_TXE_TXFNF(USART2));

    // Karakteri gönder
    LL_USART_TransmitData8(USART2, ch);
}

// Tüm metni (String) gönderme fonksiyonu
void UART_SendString(const char *str) {
    while (*str) {
        UART_SendChar(*str++);
    }
    // Tüm verinin hattan fiziksel olarak çıkmasını bekle (Transmission Complete)
    while (!LL_USART_IsActiveFlag_TC(USART2));
}

void vSPI_Task(void *pvParameters){
	for(; ;){
		UART_SendString("UART Test Basarili!\r\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
