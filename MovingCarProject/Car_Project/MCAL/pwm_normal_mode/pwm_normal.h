/*
 * pwm_normal.h
 *
 * Created: 4/11/2023 10:05:01 PM
 *  Author: sharpel
 */ 


#ifndef PWM_NORMAL_H_
#define PWM_NORMAL_H_

#include "../../Common/vect_table.h"
#include "../../MCAL/dio/dio_interface.h"
#include "pwm_config.h"




void timer2_init(void);
void timer2_start(void);
void timer2_stop(void);
void timer2_set_pwm_normal(Uchar8_t dutycycle);

#endif /*  PWM_NORMAL_H_ */