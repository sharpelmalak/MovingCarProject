/*
 * pwm_config.h
 *
 * Created: 13/04/2023 01:01:55
 *  Author: 20101
 */ 


#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

#define TCCR2  (*(volatile Uchar8_t*)(0x45))
#define TCNT2  (*(volatile Uchar8_t*)(0x44))
#define TIMSK  (*(volatile Uchar8_t*)(0x59))
#define SREG   (*(volatile Uchar8_t*)(0x5F))

#endif /* PWM_CONFIG_H_ */