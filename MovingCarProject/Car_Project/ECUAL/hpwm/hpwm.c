/*
 * hpwm.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Bassel Yasser Mahmoud
 */

/*************************************************************************************************************
 * 								Includes
 ************************************************************************************************************/
#include "../../Common/STD_Types.h"
#include "../../Common/Bit_Math.h"
#include "../../MCAL/pwm/pwm_interface.h"
#include "../../MCAL/dio/dio_interface.h"
#include "hpwm_cfg.h"
#include "hpwm.h"
/*************************************************************************************************************
 * 							Function Implementation
 ************************************************************************************************************/
/*
 * Author				: Bassel Yasser Mahmoud
 * Function Name		: pwm_enInit
 * Function Description : Initialize PWM to be fast PWM, set prescaller, Set PWM Mode
 * Arguments			: void
 * Return 				: enu_pwmStatus_t {PWM_OK or PWM_NOK}
 */
enu_pwmStatus_t pwm_enInit(void)
{
	enu_pwmStatus_t errorStatus = PWM_OK;

	errorStatus = Timer2_enuInit (TIMER2_FAST_PWM_MODE);
	if (errorStatus == PWM_NOK)
	{
		return errorStatus;
	}
	errorStatus = Timer2_enuSetPrescallar(TIMER2_PRE_8);
	if (errorStatus == PWM_NOK)
	{
		return errorStatus;
	}
	errorStatus = Timer2_enuFastPWMInit(TIMER2_PWM_CLR_ON_CMP);
	if (errorStatus == PWM_NOK)
	{
		return errorStatus;
	}

	errorStatus = Timer1_enuInit (TIMER1_FAST_PWM_8_0x00FF);
	if (errorStatus == PWM_NOK)
	{
		return errorStatus;
	}
	errorStatus = Timer1_enuSetPrescallar(TIMER1_PRE_8);
	if (errorStatus == PWM_NOK)
	{
		return errorStatus;
	}
	errorStatus = Timer1_enuFastPWMInit(TIMER1_PWM_CLR_ON_CMP);
	if (errorStatus == PWM_NOK)
	{
		return errorStatus;
	}

	(void)DIO_s8SETPinDir(PWM_PIN_NUMBER,OUTPUT);
	(void)DIO_s8SETPinDir(PWM_PIN_OC1A_NUMBER,OUTPUT);

	return errorStatus;
}

/*
 * Author				: Bassel Yasser Mahmoud
 * Function Name		: pwm_enGenerate
 * Function Description : Generate PWM signal
 * Arguments			: copy_u8PWMDutyCycle
 * Return 				: enu_pwmStatus_t {PWM_OK or PWM_NOK}
 */
enu_pwmStatus_t pwm_enGenerate(Uchar8_t copy_u8PWMDutyCycle)
{
	enu_pwmStatus_t errorStatus ;

	errorStatus = Timer2_enuPWMGenerate(copy_u8PWMDutyCycle);
	errorStatus = Timer1_enuPWMGenerate(copy_u8PWMDutyCycle);

	return errorStatus;

}
