/*
 * CommunicationTask.c
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */
#include <comm_task.h>
#include "stm32g0xx_ll_spi.h"

void vSPI_Task(void *pvParameters){
	for(; ;){
		MPU6500_Read_Accel_All(&MPU6500_AccelX, &MPU6500_AccelY, &MPU6500_AccelZ);
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}
