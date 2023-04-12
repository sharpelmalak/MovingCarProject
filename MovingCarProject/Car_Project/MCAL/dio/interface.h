#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#define DIO_PORT_LOW	0x0
#define DIO_PORT_HIGH	0xff

typedef enum
{
 	DIO_PORT_A,
 	DIO_PORT_B,
 	DIO_PORT_C,
 	DIO_PORT_D
}en_DIOPort_t;

typedef enum
{
	DIO_PIN_0,
	DIO_PIN_1,
	DIO_PIN_2,
	DIO_PIN_3,
	DIO_PIN_4,
	DIO_PIN_5,
	DIO_PIN_6,
	DIO_PIN_7
}en_DIOPin_t;

typedef enum
{
	DIO_PIN_IN,
	DIO_PIN_OUT
}en_PinDirection_t;

typedef enum
{
	DIO_PIN_LOW,
	DIO_PIN_HIGH
}en_PinValue_t;

typedef enum
{
	DIO_OK,
	InvalidPort,
	InvalidPin,
	DIO_Error
}EN_DIOErrorState_t;


/**
 * @def function to set the value of a single DIO pin
 * @param u8_a_Port the port of the required pin
 * @param u8_a_Pin the pin number in the given port
 * @param u8_a_Direction desired direction to configure the pin
 * @return error status
 */
EN_DIOErrorState_t DIO_SetPinDir(en_DIOPort_t u8_a_Port, en_DIOPin_t u8_a_Pin, en_PinDirection_t u8_a_Direction);

/**
 * @def function to set the value of a single DIO pin
 * @param u8_a_Port the port of the required pin
 * @param u8_a_Pin the pin number in the given port
 * @param u8_a_Value desired value to set the pin to
 * @return error status
 */
EN_DIOErrorState_t DIO_SetPinVal(en_DIOPort_t u8_a_Port, en_DIOPin_t u8_a_Pin, en_PinValue_t u8_a_Value);


#endif
