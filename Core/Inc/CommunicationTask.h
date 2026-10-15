/*
 * CommunicationTask.h
 *
 *  Created on: 14 Eki 2026
 *      Author: dombayli
 */

#ifndef INC_COMMUNICATIONTASK_H_
#define INC_COMMUNICATIONTASK_H_
#include "FreeRTOS.h"
#include "task.h"
#include "MPU6500.h"

extern int16_t MPU6500_AccelX;
extern int16_t MPU6500_AccelY;
extern int16_t MPU6500_AccelZ;

void vSPI_Task(void *pvParameters);


#endif /* INC_COMMUNICATIONTASK_H_ */
