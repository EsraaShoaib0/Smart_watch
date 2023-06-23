/*
 * TIMER1.h
 *
 * Created: 8/20/2022 11:25:36 AM
 *  Author: safifi
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "std_macros.h"
extern void (*timer1_ctc_isr)(void);
void TIMER1_CTC_init();



#endif /* TIMER1_H_ */