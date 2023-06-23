/*
 * Real_watch.c
 *
 * Created: 9/17/2022 3:04:36 AM
 * Author : Esraa
 */ 

#include "SEVEN_SEG.h"
#include "LCD.h"
#include "TIMER0.h"
#include "TIMER1.h"
#include "KEYPAD.h"
//#include "WATCH.h"
static void ctc1_isr(void);
static void ctc_isr(void);
uint8_t s,m,h,operation;
uint8_t on =0;
uint8_t change = 0;
uint8_t clock_on = 0;
int main(void)
{
  // clock_init();
  // SETBIT(DDRA,0);
     SEVEN_SEG_init();
   timer1_ctc_isr = ctc1_isr;
   TIMER1_CTC_init();
   timer0_ctc_isr = ctc_isr;
   TIMER0_CTC_init(16);
   KEYPAD_init();
    /* Replace with your application code */
	LCD_init();
    while (1) 
    {
		if (clock_on == 0)
	{
		//clock(h,m,s);
		LCD_write_command(0x80);
		LCD_write_number(h);
		LCD_write_data(':');
		LCD_write_number(m);
		LCD_write_data(':');
		LCD_write_number(s);
		//
		change = KEYPAD_read();
		if (change == 'c')
		{
			_delay_ms(1);
			while(change == KEYPAD_read());
			clock_on = 1;
			
		//LCD_write_command(0x01);	
		}
		//
	}
	else{
		operation = KEYPAD_read();
		while(operation == KEYPAD_read());
		if (operation !=0)
		{
			
			if (operation == '+')
			{
				while(operation == KEYPAD_read());
				m++;
				s=0;
				LCD_write_command(0x80);
				LCD_write_number(h);
				LCD_write_data(':');
				LCD_write_number(m);
				LCD_write_data(':');
				LCD_write_number(s);
			}
			else if (operation == '-')			
			{
				while(operation == KEYPAD_read());
				m--;
				s=0;
				LCD_write_command(0x80);
				LCD_write_number(h);
				LCD_write_data(':');
				LCD_write_number(m);
				LCD_write_data(':');
				LCD_write_number(s);
			}
			else if (operation == 'c')
			{			
				while (clock_on == 1)
				{
					operation = KEYPAD_read();
					if (operation !=0)
					{
						operation = KEYPAD_read();
						while(operation == KEYPAD_read());
						//while(operation == KEYPAD_read());
						if (operation == '+')
						{
							while(operation == KEYPAD_read());
							h++;
							s=0;
							LCD_write_command(0x80);
							LCD_write_number(h);
							LCD_write_data(':');
							LCD_write_number(m);
							LCD_write_data(':');
							LCD_write_number(s);
						}
						else if (operation == '-')
						{
							while(operation == KEYPAD_read());
							h--;
							s=0;
							LCD_write_command(0x80);
							LCD_write_number(h);
							LCD_write_data(':');
							LCD_write_number(m);
							LCD_write_data(':');
							LCD_write_number(s);
						}
						else if (operation == 'c')
						{
							while(operation == KEYPAD_read());
							clock_on =0;
						}
						
						
					}//
				}
								
				
			}
				
			
		}
	}
    }
}
static void ctc1_isr(void){
	static uint8_t c = 0;
	if (clock_on == 0)
	{
		c++;
		if (c==4)
		{
			c =0;
			s++;
			if (s== 60)
			{
				m++;
				s=0;
			}
			if (m == 60)
			{
				h++;
				m=0;
			}
			
		}
	}
		
		
}
static void ctc_isr(void){
	
	
	
		if (on == 1)
		{
			SEVEN_SEG_write(s%10,1);
		}
		if (on == 2)
		{
			SEVEN_SEG_write(s/10,2);
		}
		if (on == 3)
		{
			SEVEN_SEG_write(m%10,3);
		}
		if (on == 4)
		{
			SEVEN_SEG_write(m/10,4);
		}
		if (on == 5)
		{
			SEVEN_SEG_write(h%10,5);
		}
		if (on == 6)
		{
			SEVEN_SEG_write(h/10,6);
		}
		if (on == 7)
		{
			on = 0;
		}
		on++;
	
	
}