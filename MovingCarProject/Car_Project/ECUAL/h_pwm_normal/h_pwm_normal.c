/*
 * h_pwm_normal.c
 *
 * Created: 4/13/2023 3:36:36 PM
 *  Author: sharpel
 */ 

#include "h_pwm_normal.h"


/*
Description : This function selects the normal mode and enables the GLOBAL_INTERRUPT and overflow interrupt for timer2
ARGS        : void
return      : void
*/
void H_PWM_NORMAL_init(void)
{
	timer2_init();
}

/*
Description : This function selects the no clock source option. the timer stop counting once we call this function.
ARGS        : void
return      : void
*/
void H_PWM_NORMAL_stop(void)
{
	timer2_stop();
}


/*
Description : This function calculate the on time based on duty cycle we need . then start the timer
ARGS        : takes the duty cycle
return      : void
*/
void H_PWM_NORMAL_setDutyCycle(Uchar8_t dutycycle)
{
	timer2_set_pwm_normal(dutycycle);
	timer2_start();
}

