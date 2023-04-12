/*
 * pwm_normal.h
 *
 * Created: 4/11/2023 10:05:01 PM
 *  Author: sharpel
 */ 


#ifndef PWM_NORMAL_H_
#define PWM_NORMAL_H_
//#include <avr/interrupt.h>
#include "../../Utilities/Registers.h"
#include "../../ECUAL/LED/led.h"
#include <avr/interrupt.h>

//#define TCCR2  (*(volatile uint8_t*)(0x45))
//#define TCNT2  (*(volatile uint8_t*)(0x44))
//#define TIMSK  (*(volatile uint8_t*)(0x59))
//#define SREG   (*(volatile uint8_t*)(0x5F))


void timer2_init(void);
void timer2_start(void);
void timer2_stop(void);
void timer2_set_pwm_normal(uint8_t dutycycle);

#endif /*  PWM_NORMAL_H_ */