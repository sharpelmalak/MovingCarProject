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
	TCCR2 = NORMAL_MODE;
	
	// Enable Interrupt
	sei(); // global
	SET_BIT(TIMSK,TOIE2); // overflow interrupt for timer 2
	
}
void timer2_start(void)
{
	
// clkio/1024 prescaler 
  SET_BIT(TCCR2,CS20);
  SET_BIT(TCCR2,CS21);
  SET_BIT(TCCR2,CS22);
}
void timer2_stop(void)
{
	// stop the timer
	TCCR2 = NORMAL_MODE;
}

void timer2_set_pwm_normal(Uchar8_t a_dutycycle)
{
	GPIO_pin_intialize(&pwm_left_pin);
	GPIO_pin_intialize(&pwm_right_pin);
	comp_VAL = ((a_dutycycle*REG_SIZE)/PERCENT)-ONE_BIT;
	TCNT2 = REG_SIZE - comp_VAL;
}


ISR(TIM2_OVF_INT)
{
	
	
	if(FLAG_OVF==ON_TIME)
	{
		// switch level of cycle to LOW
		GPIO_pin_write_logic(&pwm_right_pin,GPIO_LOGIC_LOW);
		GPIO_pin_write_logic(&pwm_left_pin,GPIO_LOGIC_LOW);
		FLAG_OVF=OFF_TIME;
		TCNT2 =comp_VAL;
	}
	else if(FLAG_OVF == OFF_TIME)
	{
		// switch level of cycle to HIGH
		GPIO_pin_write_logic(&pwm_right_pin,GPIO_LOGIC_HIGH);
		GPIO_pin_write_logic(&pwm_left_pin,GPIO_LOGIC_HIGH);
		FLAG_OVF=ON_TIME;
		TCNT2 =REG_SIZE - comp_VAL;
	}
	
}
