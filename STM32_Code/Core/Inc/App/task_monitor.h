/*
 * task_monitor.h
 *
 *  Created on: 21 Eki 2026
 *      Author: dombayli
 */

#ifndef STM32_CODE_CORE_INC_APP_TASK_MONITOR_H_
#define STM32_CODE_CORE_INC_APP_TASK_MONITOR_H_

#include "FreeRTOS.h"
#include "task.h"

void StartTask_System_Monitor(void *argument);

#endif /* STM32_CODE_CORE_INC_APP_TASK_MONITOR_H_ */
