/*
 * KEYPAD.h
 *
 * Created: 8/13/2022 11:18:53 AM
 *  Author: safifi
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "std_macros.h"

#define INIT_KEYPAD_PIN 	                   \
							DDRA = 0b11110000; \
							PORTA = 0b1111;
#define K0 READBIT(PINA,0)
#define K1 READBIT(PINA,1)
#define K2 READBIT(PINA,2)
#define K3 READBIT(PINA,3)
#define K4(x) if(x == 1) SETBIT(PORTA,4); else CLRBIT(PORTA,4);
#define K5(x) if(x == 1) SETBIT(PORTA,5); else CLRBIT(PORTA,5);
#define K6(x) if(x == 1) SETBIT(PORTA,6); else CLRBIT(PORTA,6);
#define K7(x) if(x == 1) SETBIT(PORTA,7); else CLRBIT(PORTA,7);

void KEYPAD_init(void);
uint8_t KEYPAD_read(void);



#endif /* KEYPAD_H_ */