/*
 * app.h
 *
 * Created: 12/04/2023 22:07:51
 *  Author: 20101
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/h_pwm_normal/h_pwm_normal.h"
#include "../ECUAL/htimer0/htimer0.h"
#include "../ECUAL/h_ext_int/h_ext_int.h"
#include "../ECUAL/led/led_interface.h"
#include "../ECUAL/button/pb_interface.h"
#include "../ECUAL/motor/motor.h"



void initMain(void);
void appMain(void);

static void APP_moveForward(void);
static void APP_Stop(void);
static void APP_rotate(void);

void btn0_callback(void);
void btn1_callback(void);

#endif /* APP_H_ */