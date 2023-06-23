/*
 * SEVEN_SEG.h
 *
 * Created: 8/13/2022 12:53:05 PM
 *  Author: Esraa
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_macros.h"
#define INIT_SEVEN_SEG_PINS DDRC |= 0b1111111;  \
							DDRD |= 0xff;
#define DISABLE_ALL_7S PORTD = 0xff;
#define  PORT_WRITE PORTC
void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t data , uint8_t num);
#define E1 CLRBIT(PORTD,1);
#define E2 CLRBIT(PORTD,2);
#define E3 CLRBIT(PORTD,3);
#define E4 CLRBIT(PORTD,4);
#define E5 CLRBIT(PORTD,5);
#define E6 CLRBIT(PORTD,6);



#endif /* SEVEN_SEG_H_ */