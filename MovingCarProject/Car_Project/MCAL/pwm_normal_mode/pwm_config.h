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




#define NORMAL_MODE 0x00
#define REG_SIZE    256
#define ONE_BIT     1
#define PERCENT     100
#define ON_TIME     0
#define OFF_TIME    1


// TIMSK bits
#define TOIE2 6

// TCCR2 bits
#define CS20  0
#define CS21  1
#define CS22  2

#endif /* PWM_CONFIG_H_ */