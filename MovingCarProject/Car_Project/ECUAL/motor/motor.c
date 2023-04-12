/*
* motor.c
*
* Created: 4/12/2023 4:12:38 PM
*  Author: ME
*/

#include "../../Common/STD_Types.h"

#include "../../MCAL/dio/dio_interface.h"

#include "motor.h"

/*========================================= Global Variables =========================================*/

ST_pin_config_t st_g_Motor1Pin1 = {GPIO_PORTA_INDEX, GPIO_PIN0, GPIO_DIRECTION_OUTPUT, GPIO_LOGIC_LOW};
ST_pin_config_t st_g_Motor1Pin2 = {GPIO_PORTA_INDEX, GPIO_PIN1, GPIO_DIRECTION_OUTPUT, GPIO_LOGIC_LOW};
	
ST_pin_config_t st_g_Motor2Pin1 = {GPIO_PORTB_INDEX, GPIO_PIN0, GPIO_DIRECTION_OUTPUT, GPIO_LOGIC_LOW};
ST_pin_config_t st_g_Motor2Pin2 = {GPIO_PORTB_INDEX, GPIO_PIN1, GPIO_DIRECTION_OUTPUT, GPIO_LOGIC_LOW};	
	
ST_pin_config_t st_g_Motor3Pin1 = {GPIO_PORTC_INDEX, GPIO_PIN0, GPIO_DIRECTION_OUTPUT, GPIO_LOGIC_LOW};
ST_pin_config_t st_g_Motor3Pin2 = {GPIO_PORTC_INDEX, GPIO_PIN1, GPIO_DIRECTION_OUTPUT, GPIO_LOGIC_LOW};
	
ST_pin_config_t st_g_Motor4Pin1 = {GPIO_PORTD_INDEX, GPIO_PIN0, GPIO_DIRECTION_OUTPUT, GPIO_LOGIC_LOW};
ST_pin_config_t st_g_Motor4Pin2 = {GPIO_PORTD_INDEX, GPIO_PIN1, GPIO_DIRECTION_OUTPUT, GPIO_LOGIC_LOW};
	
/*===================================== Function Implementation =====================================*/

/**
* \brief initialize motor pins
*
* \param pst_a_Motor reference to desired motor
*
* \return en_MotorError_t
*/
en_MotorError_t DCM_Init(st_Motor_t *pst_a_Motor)
{
	if(pst_a_Motor != NULL)
	{
		/* Initialize motor pins as output pins */
		GPIO_pin_intialize(pst_a_Motor->Pin1);
		GPIO_pin_intialize(pst_a_Motor->Pin2);
	}
	else
	{
		return MOTOR_ERROR;
	}
	
	return MOTOR_OK;
}

/**
* \brief Function to start the given motor
*
* \param pst_a_Motor reference to desired motor
*
* \return en_MotorError_t
*/
en_MotorError_t DCM_Start(st_Motor_t *pst_a_Motor)
{
	if(pst_a_Motor != NULL)
	{
		if(pst_a_Motor->Dir == MOTOR_CW)
		{
			GPIO_pin_write_logic(pst_a_Motor->Pin1, GPIO_LOGIC_HIGH);
			GPIO_pin_write_logic(pst_a_Motor->Pin2, GPIO_LOGIC_LOW);
		}
		else if(pst_a_Motor->Dir == MOTOR_CCW)
		{
			GPIO_pin_write_logic(pst_a_Motor->Pin2, GPIO_LOGIC_HIGH);
			GPIO_pin_write_logic(pst_a_Motor->Pin1, GPIO_LOGIC_LOW);
		}
		else
		{
			return MOTOR_ERROR;
		}
	}
	else
	{
		return MOTOR_ERROR;
	}
	
	return MOTOR_OK;
}


/**
* \brief Function to stop the given motor
*
* \param pst_a_Motor reference to desired motor
*
* \return en_MotorError_t
*/
en_MotorError_t DCM_Stop(st_Motor_t *pst_a_Motor)
{
	if(pst_a_Motor != NULL)
	{
		GPIO_pin_write_logic(pst_a_Motor->Pin1, GPIO_LOGIC_LOW);
		GPIO_pin_write_logic(pst_a_Motor->Pin2, GPIO_LOGIC_LOW);
	}
	else
	{
		return MOTOR_ERROR;
	}
	
	return MOTOR_OK;
}

