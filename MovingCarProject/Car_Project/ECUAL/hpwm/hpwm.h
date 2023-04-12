/*
 * hpwm.h
 *
 *  Created on: Apr 10, 2023
 *      Author: hp
 */

#ifndef HAL_HPWM_HPWM_H_
#define HAL_HPWM_HPWM_H_
/*************************************************************************************************************
 * 							User defined data type
 ************************************************************************************************************/
typedef enum
{
	PWM_OK,
	PWM_NOK,

}enu_pwmStatus_t;
/*************************************************************************************************************
 * 							Function Prototype
 ************************************************************************************************************/
/*
 * Author				: Bassel Yasser Mahmoud
 * Function Name		: pwm_enInit
 * Function Description : Initialize PWM to be fast PWM, set prescaller, Set PWM Mode
 * Arguments			: void
 * Return 				: enu_pwmStatus_t {PWM_OK or PWM_NOK}
 */
enu_pwmStatus_t pwm_enInit(void);
/*
 * Author				: Bassel Yasser Mahmoud
 * Function Name		: pwm_enGenerate
 * Function Description : Generate PWM signal
 * Arguments			: copy_u8PWMDutyCycle
 * Return 				: enu_pwmStatus_t {PWM_OK or PWM_NOK}
 */
enu_pwmStatus_t pwm_enGenerate(Uchar8_t copy_u8PWMDutyCycle);


#endif /* HAL_HPWM_HPWM_H_ */
