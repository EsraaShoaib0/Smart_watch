/*
 * LCD.h
 *
 * Created: 8/18/2022 9:51:58 AM
 *  Author: Esraa
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "std_macros.h"

#define INIT_LCD_PIN  DDRB |= 0b11111100; // PB2 to PB7 output

#define EN(x) if(x == 1) SETBIT(PORTB,2); else CLRBIT(PORTB,2);
#define RS(x) if(x == 1) SETBIT(PORTB,3); else CLRBIT(PORTB,3);
#define D7(x) if(x == 1) SETBIT(PORTB,7); else CLRBIT(PORTB,7);
#define D6(x) if(x == 1) SETBIT(PORTB,6); else CLRBIT(PORTB,6);
#define D5(x) if(x == 1) SETBIT(PORTB,5); else CLRBIT(PORTB,5);
#define D4(x) if(x == 1) SETBIT(PORTB,4); else CLRBIT(PORTB,4);

void LCD_init(void);
void LCD_write_command(uint8_t data);
void LCD_write_data(uint8_t data);
void LCD_write_string(uint8_t *data);
void LCD_write_number(uint32_t data);




#endif /* LCD_H_ */