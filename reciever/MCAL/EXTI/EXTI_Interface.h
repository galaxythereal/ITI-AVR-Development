/*
 * interruptsInterface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mahmoud Ezzat
 */

#ifndef MCAL_INTERRUPTS_INTERRUPTSINTERFACE_H_
#define MCAL_INTERRUPTS_INTERRUPTSINTERFACE_H_

void MEXTI_voidSenseControl(u8 A_u8ExtiNumber, u8 A_u8State);
void MEXTI_voidDisable(u8 A_u8ExtiNumber);
void MEXTI_voidEnable(u8 A_u8ExtiNumber);
#endif /* MCAL_INTERRUPTS_INTERRUPTSINTERFACE_H_ */
