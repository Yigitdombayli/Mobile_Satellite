/*
 * task_control.c
 *
 *  Created on: 21 Eki 2026
 *      Author: dombayli
 */

#include "task_control.h"


void StartTask_Control(void *argument){
	for(; ;){
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
