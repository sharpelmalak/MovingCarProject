/*
* motor.c
*
* Created: 4/12/2023 4:12:38 PM
*  Author: ME
*/

#include "../../Common/STD_Types.h"

#include "../../MCAL/dio/interface.h"

#include "motor.h"

/*======================== Function Implementation ========================*/

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
		DIO_SetPinDir(pst_a_Motor->Port, pst_a_Motor->Pin1, DIO_PIN_OUT);
		DIO_SetPinDir(pst_a_Motor->Port, pst_a_Motor->Pin2, DIO_PIN_OUT);
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
			DIO_SetPinVal(pst_a_Motor->Port, pst_a_Motor->Pin1, DIO_PIN_HIGH);
			DIO_SetPinVal(pst_a_Motor->Port, pst_a_Motor->Pin2, DIO_PIN_LOW);
		}
		else if(pst_a_Motor->Dir == MOTOR_CCW)
		{
			DIO_SetPinVal(pst_a_Motor->Port, pst_a_Motor->Pin2, DIO_PIN_HIGH);
			DIO_SetPinVal(pst_a_Motor->Port, pst_a_Motor->Pin1, DIO_PIN_LOW);
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
		DIO_SetPinVal(pst_a_Motor->Port, pst_a_Motor->Pin1, DIO_PIN_LOW);
		DIO_SetPinVal(pst_a_Motor->Port, pst_a_Motor->Pin2, DIO_PIN_LOW);
	}
	else
	{
		return MOTOR_ERROR;
	}
	
	return MOTOR_OK;
}

