#ifndef TIM_PRIVATE_H_
#define TIM_PRIVATE_H_

#define SEC_TO_uSEC					1000000
#define mSEC_TO_uSEC				1000

#define MAX_CLK_DEV1_DELAY			5000
#define MAX_CLK_DEV8_DELAY			25000
#define MAX_CLK_DEV64_DELAY			125000
#define MAX_CLK_DEV256_DELAY		500000
//#define MAX_CLK_DEV1024_DELAY		
 
#define TIM0_MAX_TICKS				256


#define TIMER0_MODE_MASK			0b10110111
#define TIM0_NORMAL					0
#define TIM0_PWM					0b01000000
#define TIM0_CTC					0b00001000
#define TIM0_FAST_PWM				0b01001000

#define TIM0_CLK_MASK				0b11111000

/* Timer/Counter 0 Overflow Interrupt */
#define TIM0_OVF_INT				__vector_11			

#define ISR(INT_VECT)			void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#endif 