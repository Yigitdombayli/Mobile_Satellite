/*
 * task_monitor.c
 *
 *  Created on: 21 Eki 2026
 *      Author: dombayli
 */

#include "task_monitor.h"

void StartTask_System_Monitor(void *argument){
	for(;;){
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
