/*
 * pwm_normal.c
 *
 * Created: 4/11/2023 10:05:17 PM
 *  Author: sharpel
 */ 

#include "pwm_normal.h"

Uint32_t FLAG_OVF = 0;
Uchar8_t comp_VAL = 0;


ST_pin_config_t pwm_left_pin =
{
	.port = GPIO_PORTA_INDEX,
	.pin = GPIO_PIN4,
	.direction = GPIO_DIRECTION_OUTPUT,
	.logic = GPIO_LOGIC_HIGH
};

ST_pin_config_t pwm_right_pin =
{
	.port = GPIO_PORTC_INDEX,
	.pin = GPIO_PIN4,
	.direction = GPIO_DIRECTION_OUTPUT,
	.logic = GPIO_LOGIC_HIGH
};



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
	GPIO_pin_intialize(&pwm_left_pin);
	GPIO_pin_intialize(&pwm_right_pin);
	comp_VAL = ((a_dutycycle*256)/100)-1;
	TCNT2 = 256 - comp_VAL;
}


ISR(TIM2_OVF_INT)
{
	
	
	if(FLAG_OVF==0)
	{
		GPIO_pin_write_logic(&pwm_right_pin,GPIO_LOGIC_LOW);
		GPIO_pin_write_logic(&pwm_left_pin,GPIO_LOGIC_LOW);
		FLAG_OVF=1;
		TCNT2 =comp_VAL;
	}
	else if(FLAG_OVF == 1)
	{
		GPIO_pin_write_logic(&pwm_right_pin,GPIO_LOGIC_HIGH);
		GPIO_pin_write_logic(&pwm_left_pin,GPIO_LOGIC_HIGH);
		FLAG_OVF=0;
		TCNT2 =256 - comp_VAL;
	}
	
}
