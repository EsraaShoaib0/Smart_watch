/*
 * SEVEN_SEG.c
 *
 * Created: 8/13/2022 12:52:50 PM
 *  Author: Esraa
 */ 
#include "SEVEN_SEG.h"
uint8_t numbers [10] = {0b111111,0b110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b111,0b1111111,0b1101111};

void SEVEN_SEG_init(void){
	INIT_SEVEN_SEG_PINS
}
void SEVEN_SEG_write(uint8_t data , uint8_t num){
	 
	 DISABLE_ALL_7S
	 switch(num){
		 case 1: E1 break;
		 case 2: E2 break;
		 case 3: E3 break;
		 case 4: E4 break;
		 case 5: E5 break;
		 case 6: E6 break;
	 }
	 PORT_WRITE = numbers[data];
	 
}
