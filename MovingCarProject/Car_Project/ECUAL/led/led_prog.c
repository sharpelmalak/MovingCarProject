/*
 * LED_prog.c
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#include"led_interface.h"



/**
 * \brief : This Function Is Used To Initialize Pin And Port Led
 * 
 * \param ST_LED_t *led
 * 
 * \return Std_ReturnType
 */
Std_ReturnType LED_initialize(const ST_led_t *led)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pin_config_t LED_pin_obj =
		{
			.port = led->port_name,
			.pin = led->pin,
			.direction = GPIO_DIRECTION_OUTPUT,
			.logic = led->led_status
		};
		ret = GPIO_pin_intialize(&LED_pin_obj);
	}
	return ret;
}


/**
 * \brief : This Function Used To Turn Led On 
 * 
 * \param ST_led_t *led
 * 
 * \return Std_ReturnType
 */
Std_ReturnType LED_turn_on(const ST_led_t *led)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pin_config_t LED_pin_obj =
		{
				.port = led->port_name,
				.pin = led->pin,
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = led->led_status
		};
		ret = GPIO_pin_write_logic(&LED_pin_obj , GPIO_LOGIC_HIGH);
	}
	return ret;
}

/**
 * \brief : This Function Used To Turn Led Off 
 * 
 * \param ST_led_t *led
 * 
 * \return Std_ReturnType
 */
Std_ReturnType LED_turn_off(const ST_led_t *led)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pin_config_t LED_pin_obj =
		{
				.port = led->port_name,
				.pin = led->pin,
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = led->led_status
		};
		ret = GPIO_pin_write_logic(&LED_pin_obj , GPIO_LOGIC_LOW);
	}
	return ret;
}

/**
 * \brief : This Function Used To Toggle Led 
 * 
 * \param ST_led_t *led
 * 
 * \return Std_ReturnType
 */
Std_ReturnType LED_toggle(const ST_led_t *led)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == led)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pin_config_t LED_pin_obj =
		{
				.port = led->port_name,
				.pin = led->pin,
				.direction = GPIO_DIRECTION_OUTPUT,
				.logic = led->led_status
		};
		ret = GPIO_pin_toggle_logic(&LED_pin_obj);
	}
	return ret;
}

ST_led_t longSide =
{
	.port_name = GPIO_PORTC_INDEX,
	.pin = GPIO_PIN2,
	.led_status = LED_STATUS_OFF
};

ST_led_t shortSide =
{
	.port_name = GPIO_PORTC_INDEX,
	.pin = GPIO_PIN3,
	.led_status = LED_STATUS_OFF
};
ST_led_t rotate =
{
	.port_name = GPIO_PORTA_INDEX,
	.pin = GPIO_PIN2,
	.led_status = LED_STATUS_OFF
};

ST_led_t stop =
{
	.port_name = GPIO_PORTA_INDEX,
	.pin = GPIO_PIN3,
	.led_status = LED_STATUS_ON
};

