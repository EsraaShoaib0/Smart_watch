/*
 * TIMER1.c
 *
 * Created: 8/20/2022 11:25:11 AM
 *  Author: Esraa
 */ 
#include "TIMER1.h"
void (*timer1_ctc_isr)(void);

void TIMER1_CTC_init(/*uint32_t oc*/)
{
	SETBIT(TCCR1B,CS10); // PRESCALER
	SETBIT(TCCR1B,CS11); // PRESCALER
	//SETBIT(TCCR1A,FOC1A);
	//SETBIT(TCCR1A,WGM12); // CTC
	SETBIT(TIMSK,TOIE1); // enable timer ctc interrupt
	SETBIT(SREG, 7); // enable global interrupt
}
ISR(TIMER1_OVF_vect){
	timer1_ctc_isr();
}
