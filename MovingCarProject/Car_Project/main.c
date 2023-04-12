
#include "MCAL/dio/interface.h"

#include "ECUAL/motor/motor.h"

extern st_Motor_t st_g_Motor1;
extern st_Motor_t st_g_Motor2;
extern st_Motor_t st_g_Motor3;
extern st_Motor_t st_g_Motor4;

int main(void)
{
	DCM_Init(&st_g_Motor1);
	DCM_Start(&st_g_Motor1);
    /* Replace with your application code */
    while (1) 
    {
    }
}

