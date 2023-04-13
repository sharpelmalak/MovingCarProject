/*
 * PB_interface.h
 *
 *  Created on: 6 Apr 2023
 *      Author: 20101
 */

#ifndef ECU_PUSH_BUTTON_PB_INTERFACE_H_
#define ECU_PUSH_BUTTON_PB_INTERFACE_H_

#include"../../Common/BIT_Math.h"
#include"../../MCAL/dio/dio_interface.h"
#include"pb_config.h"



Std_ReturnType PUSH_BTN_intialize(const ST_PUSH_BTN_t *btn);

Std_ReturnType PUSH_BTN_read_state(const ST_PUSH_BTN_t *btn , EN_PUSH_BTN_state_t *btn_state);

#endif /* ECU_PUSH_BUTTON_PB_INTERFACE_H_ */
