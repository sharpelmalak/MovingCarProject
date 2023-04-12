#include "../../Common/STD_Types.h"
#include "../../Common/BIT_Math.h"

#include "register.h"
#include "interface.h"

st_PortRegisters_t* arr_gs_Ports[] = {PORTA, PORTB, PORTC, PORTD};

/**
* @def function to set the value of a single DIO pin
* @param u8_a_Port the port of the required pin
* @param u8_a_Pin the pin number in the given port
* @param u8_a_Direction desired direction to configure the pin
* @return error status
*/
EN_DIOErrorState_t DIO_SetPinDir(en_DIOPort_t u8_a_Port, en_DIOPin_t u8_a_Pin, en_PinDirection_t u8_a_Direction)
{
	if(u8_a_Port <= DIO_PORT_D)
	{
		if(u8_a_Pin <= DIO_PIN_7)
		{
			if(u8_a_Direction == DIO_PIN_OUT)
			{
				SET_BIT(arr_gs_Ports[u8_a_Port]->DIR, u8_a_Pin);
			}
			else if(u8_a_Direction == DIO_PIN_IN)
			{
				CLEAR_BIT(arr_gs_Ports[u8_a_Port]->DIR, u8_a_Pin);
			}
			else {return DIO_Error;}
		}
		else {return InvalidPin;}
	}
	else {return InvalidPort;}
	
	return DIO_OK;
}

/**
 * @def function to set the value of a single DIO pin
 * @param u8_a_Port the port of the required pin
 * @param u8_a_Pin the pin number in the given port
 * @param u8_a_Value desired value to set the pin to
 * @return error status
 */
EN_DIOErrorState_t DIO_SetPinVal(en_DIOPort_t u8_a_Port, en_DIOPin_t u8_a_Pin, en_PinValue_t u8_a_Value)
{
	if(u8_a_Port <= DIO_PORT_D)
	{
		if(u8_a_Pin <= DIO_PIN_7)
		{
			if(u8_a_Value == DIO_PIN_HIGH)
			{
				SET_BIT(arr_gs_Ports[u8_a_Port]->PORT, u8_a_Pin);
			}
			else if(u8_a_Value == DIO_PIN_LOW)
			{
				CLEAR_BIT(arr_gs_Ports[u8_a_Port]->PORT, u8_a_Pin);
			}
			else {return DIO_Error;}
		}
		else {return InvalidPin;}
	}
	else {return InvalidPort;}
	
	return DIO_OK;
}

