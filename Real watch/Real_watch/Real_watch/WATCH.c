/*
 * WATCH.c
 *
 * Created: 9/17/2022 3:06:49 AM
 *  Author: Esraa
 */ /*
#include "WATCH.h"
static void ctc_isr(void);
uint8_t on =0;
void clock_init(){
	timer0_ctc_isr = ctc_isr;
	TIMER0_CTC_init(16);
	
}



void clock (uint8_t hours, uint8_t min , uint8_t sec)
{
	
	if (on == 0)
	{
		SEVEN_SEG_write(sec%10,1);
	}
	if (on == 1)
	{
		SEVEN_SEG_write(sec/10,2);	
	}
	if (on == 2)
	{
		SEVEN_SEG_write(min%10,3);
	}
	if (on == 3)
	{
		SEVEN_SEG_write(min/10,4);
	}
	if (on == 4)
	{
		SEVEN_SEG_write(hours%10,5);
	}
	if (on == 5)
	{
		SEVEN_SEG_write(hours/10,6);
	}
	
}
static void ctc_isr(void){
	on ++;
	if (on == 6)
	{
		on = 0;
	}
	
}*/