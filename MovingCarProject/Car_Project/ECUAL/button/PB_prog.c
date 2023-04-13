/*
 * PB_prog.c
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#include"pb_interface.h"

/**
 * \brief : This Function Use To Initialize Button Pin And Port 
 * 
 * \param ST_PUSH_BTN_t  *btn
 * 
 * \return Std_ReturnType
 */
Std_ReturnType PUSH_BTN_intialize(const ST_PUSH_BTN_t *btn)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == btn)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = GPIO_pin_intialize(&(btn->PUSH_BTN_pin));
	}
	return ret;
}

/**
 * \brief : This Function Will Use To Read Button Statues If It Is Pressed Or Releassed 
 * 
 * \param ST_PUSH_BTN_t  *btn
 * \param EN_PUSH_BTN_state_t  *btn_state
 * 
 * \return Std_ReturnType
 */
Std_ReturnType PUSH_BTN_read_state(const ST_PUSH_BTN_t *btn , EN_PUSH_BTN_state_t *btn_state)
{
	Std_ReturnType ret = E_NOT_OK;
	if(NULL == btn || NULL == btn_state )
	{
		ret = E_NOT_OK;
	}
	else
	{
		EN_logic_t pin_logic_status = GPIO_LOGIC_LOW;
		ret = GPIO_pin_read_logic(&(btn->PUSH_BTN_pin) , &pin_logic_status);
		if(PUSH_BTN_PULL_UP == btn->PUSH_BTN_connection)
		{
			if(GPIO_LOGIC_HIGH == pin_logic_status)
			{
				*btn_state = PUSH_BTN_STATE_RELEASED;
			}
			else
			{
				*btn_state = PUSH_BTN_STATE_PRESSED;
			}
		}
		else if(PUSH_BTN_PULL_DOWN == btn->PUSH_BTN_connection)
		{
			if(GPIO_LOGIC_HIGH == pin_logic_status)
			{
				*btn_state = PUSH_BTN_STATE_PRESSED;
			}
			else
			{
				*btn_state = PUSH_BTN_STATE_RELEASED;
			}
		}
		else{/* nothing */}
		ret = E_OK;
	}

	return ret;
}


ST_PUSH_BTN_t startBtn =
{
	.PUSH_BTN_pin =
	{
		.port = GPIO_PORTD_INDEX,
		.pin = GPIO_PIN3,
		.direction = GPIO_DIRECTION_INPUT,
		.logic = GPIO_LOGIC_HIGH
	},
	.PUSH_BTN_connection = PUSH_BTN_PULL_UP,
	.PUSH_BTN_state = PUSH_BTN_STATE_RELEASED
};

ST_PUSH_BTN_t stopBtn =
{
	.PUSH_BTN_pin =
	{
		.port = GPIO_PORTD_INDEX,
		.pin = GPIO_PIN2,
		.direction = GPIO_DIRECTION_INPUT,
		.logic = GPIO_LOGIC_HIGH
	},
	.PUSH_BTN_connection = PUSH_BTN_PULL_UP,
	.PUSH_BTN_state = PUSH_BTN_STATE_RELEASED
};