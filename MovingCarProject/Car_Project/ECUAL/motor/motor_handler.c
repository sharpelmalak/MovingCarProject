/*
 * motor_handler.c
 *
 * Created: 4/12/2023 5:41:19 PM
 *  Author: ME
 */ 

#include "../../MCAL/dio/interface.h"

#include "motor.h"

st_Motor_t st_g_Motor1 = {DIO_PORT_A, DIO_PIN_0, DIO_PIN_1, MOTOR_CW};
st_Motor_t st_g_Motor2 = {DIO_PORT_A, DIO_PIN_2, DIO_PIN_3, MOTOR_CW};
st_Motor_t st_g_Motor3 = {DIO_PORT_B, DIO_PIN_0, DIO_PIN_1, MOTOR_CW};
st_Motor_t st_g_Motor4 = {DIO_PORT_B, DIO_PIN_2, DIO_PIN_3, MOTOR_CW};
	
