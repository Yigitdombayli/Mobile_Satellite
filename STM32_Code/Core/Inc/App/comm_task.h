/*
 * CommunicationTask.h
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */

#ifndef INC_COMM_TASK_H_
#define INC_COMM_TASK_H_
#include <mpu6500_driver.h>
#include "FreeRTOS.h"
#include "task.h"

extern int16_t MPU6500_AccelX;
extern int16_t MPU6500_AccelY;
extern int16_t MPU6500_AccelZ;

void vSPI_Task(void *pvParameters);


#endif /* INC_COMM_TASK_H_ */
