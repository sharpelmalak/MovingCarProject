/*
 * app.h
 *
 * Created: 12/04/2023 22:07:51
 *  Author: 20101
 */ 


#ifndef APP_H_
#define APP_H_

#include "../MCAL/pwm_normal_mode/pwm_normal.h"
#include "../MCAL/timer0/tim0_interface.h"
#include "../MCAL/extint/extinterrupt.h"
#include "../ECUAL/led/led_interface.h"
#include "../ECUAL/button/pb_interface.h"
#include "../ECUAL/motor/motor.h"



void initMain(void);
void appMain(void);

static void APP_moveForward(void);
static void APP_Stop(void);
static void APP_rotate(void);


#endif /* APP_H_ */