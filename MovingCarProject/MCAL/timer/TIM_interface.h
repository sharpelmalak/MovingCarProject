
#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_

typedef enum
{
	uSeconds,
	mSeconds,
	Seconds
}en_timeUnits_t;

typedef enum
{
	TIM_OK,
	TIM_NOK
}en_TIMErrorState_t;

typedef enum
{
	NormalMode,
	PWM_Mode,
	CTC_Mode,
	FastPWM_Mode
}en_TIMMode_t;

typedef enum
{
	TIM_NO_CLOCK             ,
	TIM_DIV_BY_1             ,
	TIM_DIV_BY_8             ,
	TIM_DIV_BY_64            ,
	TIM_DIV_BY_256           ,
	TIM_DIV_BY_1024          ,
	TIM_EXTERNAL_FALLING_EDGE,
	TIM_EXTERNAL_RISING_EDGE
}en_TIM_CLK_SELECT_t;

/* Asynchronous Delay Function States */
#define  DELAY_BUSY			0
#define  DELAY_IDLE			1

/*=========================== Function Prototypes ===========================*/

/**
 * \brief Initialize the timer with given mode
 * 
 * \param u8_a_Mode
 * 
 * \return EN_TIMErrorState_t
 */
en_TIMErrorState_t TIM0_voidInit(en_TIMMode_t u8_a_Mode);

/**
 * \brief Start the timer clock after prescaling it with given value 
 * 
 * \param u8_a_prescaler
 * 
 * \return EN_TIMErrorState_t
 */
en_TIMErrorState_t TIM0_Start(en_TIM_CLK_SELECT_t u8_a_prescaler);

/**
 * \brief Stop the timer
 * 
 * \return void
 */
void TIM0_Stop();

/**
 * \brief Set the timer to start from the given value
 * 
 * \param Copy_Value
 * 
 * \return void
 */
void TIM0_SetValue(Uint8_t u8_a_startValue);


/**
 * \brief Generate Synchronous delay (busy waiting)
 * 
 * \param Copy_delayTime 
 * \param Copy_timeUnit
 * 
 * \return EN_TIMErrorState_t
 */
en_TIMErrorState_t TIM0_SyncDelay(Uint32_t u32_a_delay, en_timeUnits_t u8_a_timeUnit);


/**
 * \brief Generate an asynchronous delay using the timer0
 *		  OVF interrupt
 * \param u32_a_delay
 * \param u8_a_timeUnit
 * \param 
 * \param Copy_pvCallbackFn
 * \param 
 * 
 * \return en_TIMErrorState_t
 */
en_TIMErrorState_t TIM0_AsyncDelay(Uint32_t u32_a_delay, en_timeUnits_t u8_a_timeUnit, void (*Copy_pvCallbackFn)(void));

#endif