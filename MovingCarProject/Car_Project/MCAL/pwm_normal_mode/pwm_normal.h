/*
 * pwm_normal.h
 *
 * Created: 4/11/2023 10:05:01 PM
 *  Author: sharpel
 */ 


#ifndef PWM_NORMAL_H_
#define PWM_NORMAL_H_

#include "../../Common/vect_table.h"
#include "../../Common/STD_Types.h"
#include "../../MCAL/dio/dio_interface.h"
#include "pwm_config.h"



/*
Description : This function selects the normal mode and enables the GLOBAL_INTERRUPT and overflow interrupt for timer2
ARGS        : void
return      : void
*/
void timer2_init(void);

/*
Description : This function selects the prescaler (clk/1024). the timer start counting once we call this function.
ARGS        : void
return      : void
*/
void timer2_start(void);


/*
Description : This function selects the no clock source option. the timer stop counting once we call this function.
ARGS        : void
return      : void
*/
void timer2_stop(void);


/*
Description : This function calculate the on time based on duty cycle we need .
ARGS        : takes the duty cycle
return      : void
*/
void timer2_set_pwm_normal(Uchar8_t a_dutycycle);

#endif /*  PWM_NORMAL_H_ */