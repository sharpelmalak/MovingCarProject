
#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

typedef struct
{
	volatile Uchar8_t PIN;
	volatile Uchar8_t DIR;
	volatile Uchar8_t PORT;
}st_PortRegisters_t;

#define PORTA			(volatile st_PortRegisters_t*)0x39
#define PORTB			(volatile st_PortRegisters_t*)0x36
#define PORTC			(volatile st_PortRegisters_t*)0x33
#define PORTD			(volatile st_PortRegisters_t*)0x30

#endif
