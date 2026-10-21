/*
 * task_uart_rx.h
 *
 *  Created on: 21 Eki 2026
 *      Author: dombayli
 */

#ifndef STM32_CODE_CORE_INC_APP_TASK_UART_RX_H_
#define STM32_CODE_CORE_INC_APP_TASK_UART_RX_H_

#include "FreeRTOS.h"
#include "task.h"

void StartTask_UART_RxParser(void *argument);

#endif /* STM32_CODE_CORE_INC_APP_TASK_UART_RX_H_ */
