/*
* app.c
*
* Created: 12/04/2023 22:07:16
*  Author: 20101
*/

#include "app.h"


extern ST_led_t longSide,shortSide,rotate,stop;
extern ST_PUSH_BTN_t startBtn,stopBtn;
extern st_Motor_t st_g_Motor1, st_g_Motor3;

typedef enum
{
	APP_IdleState,
	APP_StartState,
	APP_LongSideState,
	APP_RotateState,
	APP_ShortSideState
}en_APPStates_t;

Uchar8_t u8_g_state;

static Uchar8_t u8_gs_NextSide = APP_ShortSideState;

/*===================================== Function Implementation =====================================*/

void initMain(void)
{

	/* Initialize LEDs */
	LED_initialize(&longSide);
	LED_initialize(&shortSide);
	LED_initialize(&rotate);
	LED_initialize(&stop);
	
	/* Initialize Buttons */
	PUSH_BTN_intialize(&startBtn);
	PUSH_BTN_intialize(&stopBtn);
		
	/* Initialize Motors */
	DCM_Init(&st_g_Motor1);
	DCM_Init(&st_g_Motor3);
	
	/* Initialize PWM Timer */
	timer2_init();
	
	/* Initialize External Interrupts */
	EXTINT_init(EXTINT1,LOW_LEVEL);
	EXTINT_CallBack(EXTINT1,btn0_callback);
	EXTINT_init(EXTINT0,LOW_LEVEL);
	EXTINT_CallBack(EXTINT0,btn1_callback);
}

void btn0_callback(void)
{
	/* Set the app state to APP_StartState */
	u8_g_state = APP_StartState;
}

void btn1_callback(void)
{
	TIM0_AsyncEndDelay();
	u8_g_state = APP_IdleState;
}


void APP_moveForward(void)
{
	DCM_Start(&st_g_Motor1);
	DCM_Start(&st_g_Motor3);
}

void APP_Stop(void)
{
	LED_turn_on(&stop);
	DCM_Stop(&st_g_Motor1);
	DCM_Stop(&st_g_Motor3);
}

void APP_rotate(void)
{
	LED_turn_on(&rotate);
	DCM_Start(&st_g_Motor1);
	DCM_Stop(&st_g_Motor3);
	TIM0_SyncDelay(2,Seconds);
	LED_turn_off(&rotate);
}

void appMain(void)
{
	switch(u8_g_state)
	{
		case APP_IdleState: APP_Stop(); break;
		case APP_StartState: 
		{
			u8_g_state = APP_LongSideState;
			TIM0_SyncDelay(1,Seconds);			
			break;
		}		
		case APP_LongSideState:
		{
			u8_g_state = APP_RotateState;
			LED_turn_off(&stop);
			timer2_set_pwm_normal(50);
			timer2_start();
			LED_turn_on(&longSide);
			APP_moveForward();
			TIM0_SyncDelay(3,Seconds);
			u8_gs_NextSide = APP_ShortSideState;
			LED_turn_off(&longSide);
			break;
		}
		case APP_RotateState:
		{
			u8_g_state = u8_gs_NextSide;
			APP_Stop();
			TIM0_SyncDelay(500,mSeconds);
			LED_turn_off(&stop);
			APP_rotate();
			APP_Stop();
			TIM0_SyncDelay(500,mSeconds);
			
			break;
		}
		case APP_ShortSideState:
		{
			u8_g_state = APP_RotateState;
			LED_turn_off(&stop);
			timer2_set_pwm_normal(30);
			timer2_start();
			LED_turn_on(&shortSide);
			APP_moveForward();
			TIM0_SyncDelay(2,Seconds);
			LED_turn_off(&shortSide);
			u8_gs_NextSide = APP_LongSideState;
			LED_turn_off(&shortSide);
			break;
		}
		
	}
}