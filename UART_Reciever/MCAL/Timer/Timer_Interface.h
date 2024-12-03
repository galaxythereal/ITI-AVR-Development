/*
 * Timer_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: mahmo
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

void MTimer_voidTimerInit(u8 A_u8TimerMode);

void MTimer_voidStart();

void MTimer_voidStop();

void MTimer_voidSetPreloadValue(u8 A_u8TimerMode, u8 A_u8PreloadValue);

/*Timer 1 Prototypes*/
void MTimer1_voidInit();

void MTimer1_voidSetTimer1Value(u16 A_u16Value);

u16 MTimer1_u16ReadTimer1Value();



#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
