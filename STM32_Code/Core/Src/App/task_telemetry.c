/*
 * task_telemetry.c
 *
 *  Created on: 21 Eki 2026
 *      Author: dombayli
 */

#include "task_telemetry.h"
#define RAD_TO_DEG 57.295779513082320876798154814105f


static Kalman_Filter_Component kf_roll;
static Kalman_Filter_Component kf_pitch;

void StartTask_Telemetry_Tx(void *argument){

	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xFrequency = pdMS_TO_TICKS(100);

	int16_t accelX = 0;
	int16_t accelY = 0;
	int16_t accelZ = 0;
	TelemetryData_t telemetryData = {0};

	Kalman_Init(&kf_roll,  0.0f, 1.0f, 0.005f, 0.5f);
	Kalman_Init(&kf_pitch, 0.0f, 1.0f, 0.005f, 0.5f);

	for(;;){
		MPU6500_Read_Accel_All(&accelX, &accelY, &accelZ);
		float ax = (float)accelX;
		float ay = (float)accelY;
		float az = (float)accelZ;

		float raw_roll  = atan2f(ay, az) * RAD_TO_DEG;
	    float raw_pitch = atan2f(-ax, sqrtf(ay * ay + az * az)) * RAD_TO_DEG;

	    float filtered_roll  = Kalman_Update(&kf_roll, raw_roll);
	    float filtered_pitch = Kalman_Update(&kf_pitch, raw_pitch);

	    telemetryData.currentMode      = MODE_STANDBY;
	    telemetryData.currentAzimuth   = 0.0f;
	    telemetryData.currentElevation = 0.0f;
	    telemetryData.currentRoll      = filtered_roll;
	    telemetryData.currentPitch     = filtered_pitch;
	    telemetryData.systemStatus     = 0x00;

	    Send_Telemetry_Frame(&telemetryData);
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}
