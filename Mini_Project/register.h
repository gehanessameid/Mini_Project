#ifndef REGISTER_H_
#define REGISTER_H_
#include "stdTypes.h"

/*Direction(Input/ Output )*/
#define DIO_DDRA   *((volatile u8*)0x3A)
#define DIO_DDRB   *((volatile u8*)0x37)
#define DIO_DDRC   *((volatile u8*)0x34)
#define DIO_DDRD   *((volatile u8*)0x31)
/*Output (High / Low)*/
#define DIO_PORTA  *((volatile u8*)0x3B)
#define DIO_PORTB  *((volatile u8*)0x38)
#define DIO_PORTC  *((volatile u8*)0x35)
#define DIO_PORTD  *((volatile u8*)0x32)
/*Input Store the input value (high low)*/
#define DIO_PINA   *((volatile u8*)0x39)
#define DIO_PINB   *((volatile u8*)0x36)
#define DIO_PINC   *((volatile u8*)0x33)
#define DIO_PIND   *((volatile u8*)0x30)
/*------------------------------------------------------------------*/
/*Pins*/
#define DIO_Pin0 0
#define DIO_Pin1 1
#define DIO_Pin2 2
#define DIO_Pin3 3
#define DIO_Pin4 4
#define DIO_Pin5 5
#define DIO_Pin6 6
#define DIO_Pin7 7
/*Groups*/
#define DIO_GroupA  1
#define DIO_GroupB  2
#define DIO_GroupC  3
#define DIO_GroupD  4
#endif /* DIO_REGISTER_H_ */