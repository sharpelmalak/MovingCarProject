/*============================== Includes ==============================*/
#include "../../Common/STD_Types.h"
#include "../../Common/BIT_Math.h"

#include "tim0_register.h"
#include "tim0_private.h"
#include "tim0_interface.h"

/*========================= Global Variables ========================*/
/* prescaler options */
static Uint16_t arr_gs_prescalers[] = {1,8,64,265,1024};
	
static Uchar8_t u8_gs_OVFCount = 0, u8_gs_TotalOVF = 0, u8_gs_delayStatusFlag = DELAY_IDLE;

void (*TIM0_OVFCallbackFn)(void) = NULL;

/*========================= Function Implementation ========================*/
en_TIMErrorState_t TIM0_voidInit(en_TIMMode_t u8_a_Mode)
{
	Uchar8_t u8_l_T0Mode;
	
	switch(u8_a_Mode)
	{
		case NormalMode:   u8_l_T0Mode = TIM0_NORMAL;	 break;
		case PWM_Mode:     u8_l_T0Mode = TIM0_PWM;	     break;
		case CTC_Mode:	   u8_l_T0Mode = TIM0_CTC;		 break;
		case FastPWM_Mode: u8_l_T0Mode = TIM0_FAST_PWM; break;
		default: return TIM_NOK;
	}
	
	/* Clear the timer0 mode bit */
	TCCR0 &= TIMER0_MODE_MASK;
	/* Set the bits to the given value */
	TCCR0 |= u8_l_T0Mode;
	
	return TIM_OK;
}

en_TIMErrorState_t TIM0_Start(en_TIM_CLK_SELECT_t u8_a_prescaler)
{
	en_TIMErrorState_t u8_l_ErrorState = TIM_OK;
	
	/* Check that prescaler is valid */
	if(u8_a_prescaler > TIM_NO_CLOCK && u8_a_prescaler <= TIM_EXTERNAL_RISING_EDGE)
	{
		/* Clear the prescaler bits */
		TCCR0 &= TIM0_CLK_MASK;
		/* Set prescaler value */
		TCCR0 |= u8_a_prescaler;
	}
	else
	{
		u8_l_ErrorState = TIM_NOK;
	}
	
	return u8_l_ErrorState;
}

void TIM0_Stop()
{
	/* Clear the prescaler bits */
	TCCR0 &= TIM0_CLK_MASK;
}

void TIM0_SetValue(Uchar8_t u8_a_startValue)
{
	TCNT0 = u8_a_startValue;
}

en_TIMErrorState_t TIM0_SyncDelay(Uint32_t u32_a_delay, en_timeUnits_t Copy_timeUnit)
{
	Uchar8_t u8_l_prescaler, Local_TotalOverFlows, Local_OverFlowCounter=0;
	Uint16_t Local_TotalTicks;
	float Local_TickTime;
	
	/* Get Value in micro seconds */
	if(Copy_timeUnit == Seconds)	{u32_a_delay *= SEC_TO_uSEC;}
	else if(Copy_timeUnit == mSeconds)	{u32_a_delay *= mSEC_TO_uSEC;}
	else if(Copy_timeUnit == uSeconds)	{/* Do Nothing */}
	else return TIM_NOK;
	
	/* Set prescaler according to delay time */
	if(u32_a_delay <= MAX_CLK_DEV1_DELAY  )	{u8_l_prescaler = TIM_DIV_BY_1;}
	else if(u32_a_delay <= MAX_CLK_DEV8_DELAY  ) {u8_l_prescaler = TIM_DIV_BY_8;}
	else if(u32_a_delay <= MAX_CLK_DEV64_DELAY ) {u8_l_prescaler = TIM_DIV_BY_64;}
	else if(u32_a_delay <= MAX_CLK_DEV256_DELAY) {u8_l_prescaler = TIM_DIV_BY_256;}
	else {u8_l_prescaler = TIM_DIV_BY_1024;}
	
	Local_TickTime = arr_gs_prescalers[u8_l_prescaler-1]; //CPU Prescaler
	Local_TotalTicks = (Uint16_t)(u32_a_delay/Local_TickTime);
	Local_TotalOverFlows = Local_TotalTicks/TIM0_MAX_TICKS;
	
	/* Initialize timer in normal mode */
	TIM0_voidInit(NormalMode);
	
	/* Set timer start value */
	TIM0_SetValue(TIM0_MAX_TICKS-(Local_TotalTicks%TIM0_MAX_TICKS));
	
	/* Start Timer */
	TIM0_Start(u8_l_prescaler);
	
	while(Local_OverFlowCounter <= Local_TotalOverFlows)
	{
		/* Wait until the overflow flag is raised */
		while(!GET_BIT(TIFR, TIFR_TOV0));
		
		/* Clear the overflow flag */
		SET_BIT(TIFR, TIFR_TOV0);
		
		Local_OverFlowCounter++;
	}
	
	TIM0_Stop();
	
	return TIM_OK;
}

en_TIMErrorState_t TIM0_AsyncDelay(Uint32_t u32_a_delay, en_timeUnits_t u8_a_timeUnit, void (*Copy_pvCallbackFn)(void))
{
	Uchar8_t u8_l_prescaler;
	Uint16_t u8_l_TotalTicks;
	float Local_TickTime;
	
	if(u8_gs_delayStatusFlag == DELAY_BUSY) return TIM_NOK;
	
	/* Get Value in micro seconds */
	if(u8_a_timeUnit == Seconds)	{u32_a_delay *= SEC_TO_uSEC;}
	else if(u8_a_timeUnit == mSeconds)	{u32_a_delay *= mSEC_TO_uSEC;}
	else if(u8_a_timeUnit == uSeconds)	{/* Do Nothing */}
	else return TIM_NOK;
	
	/* Set prescaler according to delay time */
	if(u32_a_delay <= MAX_CLK_DEV1_DELAY  )	{u8_l_prescaler = TIM_DIV_BY_1;}
	else if(u32_a_delay <= MAX_CLK_DEV8_DELAY  ) {u8_l_prescaler = TIM_DIV_BY_8;}
	else if(u32_a_delay <= MAX_CLK_DEV64_DELAY ) {u8_l_prescaler = TIM_DIV_BY_64;}
	else if(u32_a_delay <= MAX_CLK_DEV256_DELAY) {u8_l_prescaler = TIM_DIV_BY_256;}
	else {u8_l_prescaler = TIM_DIV_BY_1024;}
	
	Local_TickTime = arr_gs_prescalers[u8_l_prescaler-1]; //CPU Prescaler
	u8_l_TotalTicks = (Uint16_t)(u32_a_delay/Local_TickTime);
	u8_gs_TotalOVF = u8_l_TotalTicks/TIM0_MAX_TICKS;
	
	/*Set the callback function */
	TIM0_OVFCallbackFn = Copy_pvCallbackFn;
	
	/* Enable Timer 0 overflow interrupt */
	SET_BIT(TIMSK, TIMSK_TOIE0);
	
	/* Set timer start value */
	TIM0_SetValue(TIM0_MAX_TICKS-(u8_l_TotalTicks%TIM0_MAX_TICKS));
	
	/* Set the function state as busy */
	u8_gs_delayStatusFlag = DELAY_BUSY;
	
	/* Start Timer */
	TIM0_Start(u8_l_prescaler);
	
	return TIM_OK;
}



en_TIMErrorState_t TIM0__SyncDelay(Uint32_t Copy_delayTime, en_timeUnits_t Copy_timeUnit)
{
	Uchar8_t Local_prescaler, Local_TotalOverFlows, Local_OverFlowCounter=0;
	Uint16_t Local_TotalTicks;
	float Local_TickTime;
	
	/* Get Value in micro seconds */
	if(Copy_timeUnit == Seconds)	{Copy_delayTime *= 1000000;}
	else if(Copy_timeUnit == mSeconds)	{Copy_delayTime *= 1000;}
	else if(Copy_timeUnit == uSeconds)	{/* Do Nothing */}
	else return TIM_NOK;
	
	/* Get prescaler according to delay time */
	if(Copy_delayTime>=300000)
	{
		Local_prescaler = TIM_DIV_BY_1024;
	}
	else if(Copy_delayTime<=5000)
	{
		Local_prescaler = TIM_DIV_BY_1;
	}
	else
	{
		Local_prescaler = TIM_DIV_BY_64;
	}
	
	Local_TickTime = arr_gs_prescalers[Local_prescaler-1]; //CPU Prescaler
	Local_TotalTicks = (Uint16_t)(Copy_delayTime/Local_TickTime);
	Local_TotalOverFlows = Local_TotalTicks/TIM0_MAX_TICKS;
	
	/* Initialize timer in normal mode */
	TIM0_voidInit(NormalMode);
	
	/* Set timer start value */
	TIM0_SetValue(TIM0_MAX_TICKS-(Local_TotalTicks%TIM0_MAX_TICKS));
	
	/* Start Timer */
	TIM0_Start(Local_prescaler);
	
	while(Local_OverFlowCounter <= Local_TotalOverFlows)
	{
		/* Wait until the overflow flag is raised */
		while(!GET_BIT(TIFR, TIFR_TOV0));
		
		/* Clear the overflow flag */
		SET_BIT(TIFR, TIFR_TOV0);
		
		Local_OverFlowCounter++;
	}
	
	TIM0_Stop();
	return TIM_OK;
}
/*========================== ISRs =============================*/

ISR(TIM0_OVF_INT)
{
	if(TIM0_OVFCallbackFn != NULL)
	{
		/* Delay is complete */
		if(u8_gs_OVFCount == u8_gs_TotalOVF)
		{
			/* Stop the timer */
			TIM0_Stop();
			
			/* Reset the OVF counter */
			u8_gs_OVFCount = 0;
			
			/* Change the delay function state back to idle */
			u8_gs_delayStatusFlag = DELAY_IDLE;
			
			/* Call the Callback function */
			TIM0_OVFCallbackFn();
		}
		else
		{
			/* Increment the overflow count */
			u8_gs_OVFCount++;
		}
	}
}