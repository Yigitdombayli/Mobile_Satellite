/*
 * Kalman.h
 *
 *  Created on: 15 Eki 2026
 *      Author: dombayli
 */

#ifndef INC_KALMAN_FUNC_H_
#define INC_KALMAN_FUNC_H_
typedef struct{
	float KalmanX;
	float KalmanP;
	float KalmanQ;
	float KalmanR;
	float KalmanK;
}Kalman_Filter_Component;


float Kalman_Update(Kalman_Filter_Component *kf, float measurement);
void Kalman_Init(Kalman_Filter_Component *kf, float initial_Q, float initial_P, float Q, float R);

#endif /* INC_KALMAN_FUNC_H_ */
