/*
 * motor_handler.c
 *
 * Created: 4/12/2023 5:41:19 PM
 *  Author: ME
 */ 

#include "../../MCAL/dio/dio_interface.h"

#include "motor.h"

st_Motor_t st_g_Motor1 = {&st_g_Motor1Pin1, &st_g_Motor1Pin2, MOTOR_CW};
st_Motor_t st_g_Motor2 = {&st_g_Motor2Pin1, &st_g_Motor2Pin2, MOTOR_CW};
st_Motor_t st_g_Motor3 = {&st_g_Motor3Pin1, &st_g_Motor3Pin2, MOTOR_CW};
st_Motor_t st_g_Motor4 = {&st_g_Motor4Pin1, &st_g_Motor4Pin2, MOTOR_CW};
	
