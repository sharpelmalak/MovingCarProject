/*
 * app.c
 *
 * Created: 12/04/2023 22:07:16
 *  Author: 20101
 */ 

#include"app.h"


extern ST_led_t longSide,shortSide,rotate,stop;
extern ST_PUSH_BTN_t startBtn,stopBtn;
extern st_Motor_t st_g_Motor1,st_g_Motor3;


void initMain(void)
{
	LED_initialize(&longSide);
	LED_initialize(&shortSide);
	LED_initialize(&rotate);
	LED_initialize(&stop);
	
		LED_turn_on(&longSide);
		TIM0__SyncDelay(3000,mSeconds);
		LED_turn_off(&longSide);
		TIM0__SyncDelay(3000,mSeconds);

	
	PUSH_BTN_intialize(&startBtn);
	PUSH_BTN_intialize(&stopBtn);
	

	
	DCM_Init(&st_g_Motor1);
	DCM_Init(&st_g_Motor3);
	timer2_init();
	EXTINT_init(EXTINT1,LOW_LEVEL);
	EXTINT_CallBack(EXTINT1,APP_moveForward);
}


void APP_moveForward(void)
{
	timer2_set_pwm_normal(50);
	timer2_start();
	DCM_Start(&st_g_Motor1);
	DCM_Start(&st_g_Motor3);
	TIM0__SyncDelay(3000,mSeconds);
	LED_turn_on(&longSide);
	TIM0__SyncDelay(3000,mSeconds);
	LED_turn_off(&longSide);
}

void APP_Stop(void)
{
	DCM_Stop(&st_g_Motor1);
	DCM_Stop(&st_g_Motor3);
}
void APP_rotate(void)
{
	DCM_Start(&st_g_Motor1);
	DCM_Stop(&st_g_Motor3);
}

void appMain(void)
{
	
}