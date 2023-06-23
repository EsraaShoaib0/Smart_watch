/*
 * std_macros.h
 *
 * Created: 8/7/2022 3:11:46 PM
 *  Author: Esraa
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#define SETBIT(REG,BIT)			(REG |=1<<BIT)			//TO MAKE THIS BIT = 1
#define READBIT(REG,BIT)	    ((REG>>BIT) & 1)		//TO READ THIS BIT AND GET ITS VALUE
#define CLRBIT(REG,BIT)			(REG &= ~(1<<BIT))		//TO MAKE THIS BIT = 0
#define TOGBIT(REG,BIT)			(REG ^= 1 << BIT)		//TO TOGGLE THIS BIT

#endif /* STD_MACROS_H_ */