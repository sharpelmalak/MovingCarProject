/*
 * h_pwm_normal.h
 *
 * Created: 4/13/2023 3:37:00 PM
 *  Author: sharpel
 */ 


#ifndef H_PWM_NORMAL_H_
#define H_PWM_NORMAL_H_

#include "../../MCAL/pwm_normal_mode/pwm_normal.h"



/*
Description : This function selects the normal mode and enables the GLOBAL_INTERRUPT and overflow interrupt for timer2
ARGS        : void
return      : void
*/
void H_PWM_NORMAL_init(void);

/*
Description : This function selects the no clock source option. the timer stop counting once we call this function.
ARGS        : void
return      : void
*/
void H_PWM_NORMAL_stop(void);


/*
Description : This function calculate the on time based on duty cycle we need . then start the timer
ARGS        : takes the duty cycle
return      : void
*/
void H_PWM_NORMAL_setDutyCycle(Uchar8_t dutycycle);


#endif /* H_PWM_NORMAL_H_ */