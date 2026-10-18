/*
 * Kalman.c
 *
 *  Created on: 15 Eki 2026
 *      Author: dombayli
 */
#include <kalman_func.h>

void Kalman_Init(Kalman_Filter_Component *kf, float initial_X, float initial_P, float Q, float R){
	kf->KalmanX = initial_X;
	kf->KalmanP = initial_P;
	kf->KalmanQ = Q;
	kf->KalmanR = R;
	kf->KalmanK = 0.0f;
}
float Kalman_Update(Kalman_Filter_Component *kf, float measurement){
	kf->KalmanP = kf->KalmanP + kf->KalmanQ;
	kf->KalmanK = (kf->KalmanP / (kf->KalmanP + kf->KalmanR));
	kf->KalmanX = kf->KalmanX + kf->KalmanK * (measurement - kf->KalmanX);
	kf->KalmanP = (1.0f - kf->KalmanK)* kf->KalmanP;
	return kf->KalmanX;
}
