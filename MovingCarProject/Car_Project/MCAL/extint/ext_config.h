/*
 * ext_config.h
 *
 * Created: 13/04/2023 01:17:01
 *  Author: 20101
 */ 


#ifndef EXT_CONFIG_H_
#define EXT_CONFIG_H_


#define SREG    (*(volatile Uchar8_t*)(0x5F))
#define GICR    (*(volatile Uchar8_t*)(0x5B))
#define GIFR    (*(volatile Uchar8_t*)(0x5A))
#define MCUCR   (*(volatile Uchar8_t*)(0x55))
#define MCUCSR  (*(volatile Uchar8_t*)(0x54))


#endif /* EXT_CONFIG_H_ */