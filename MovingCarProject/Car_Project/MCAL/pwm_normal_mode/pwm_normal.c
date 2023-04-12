/*
 * pwm_normal.c
 *
 * Created: 4/11/2023 10:05:17 PM
 *  Author: sharpel
 */ 

#include "pwm_normal.h"

Uint32_t FLAG_OVF = 0;
Uchar8_t comp_VAL = 0;

void timer2_init(void)
{
	//Select Normal Mode
	TCCR2 = 0x00;
	
	// Enable Interrupt
	SREG  |=(1<<7); // global
	TIMSK |=(1<<6); // overflow interrupt for timer 2
	
}
void timer2_start(void)
{
	
// clkio/1024 prescaler 
  TCCR2 |= (1<<0) | (1<<1) | (1<<2);
}
void timer2_stop(void)
{
	// stop the timer
	TCCR2 = 0x00;
}

void timer2_set_pwm_normal(Uchar8_t a_dutycycle)
{
	
	comp_VAL = ((a_dutycycle*256)/100)-1;
	TCNT2 = 256 - comp_VAL;
	
}

ISR(TIMER2_OVF_vect)
{
	
	
	if(FLAG_OVF==0)
	{
		//LED_off(DIO_PIN0,DIO_PORTA);
		FLAG_OVF=1;
		TCNT2 =comp_VAL;
	}
	else if(FLAG_OVF == 1)
	{
		//LED_on(DIO_PIN0,DIO_PORTA);
		FLAG_OVF=0;
		TCNT2 =256 - comp_VAL;
	}
	
}
