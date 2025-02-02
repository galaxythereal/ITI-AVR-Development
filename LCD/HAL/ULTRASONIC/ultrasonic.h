#ifndef _ULTRA_H_
#define _ULTRA_H_

#include<avr/io.h>
#include <avr/interrupt.h>
#include<string.h>
#include <stdlib.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../timer/timer.h"
//#include"../../MCAL/TIMER/Timer_Interface.h"

#define   TRIGGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGGER_PORT   PORTD
#define   ECHO_PULLUP   PORTD
#define   TRIGGER        0
#define   ECHO          3

/*************************************************
 *  API functions
 *************************************************/

void HSNC_voidInit(void);
void HSNC_voidEnableInterrupt(void);
void HSNC_voidTrigger(void);

#endif
