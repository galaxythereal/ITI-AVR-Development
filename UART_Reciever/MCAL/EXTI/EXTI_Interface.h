/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: mahmo
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_



void MEXTI_voidSenseControl(u8 A_u8ExtiNumber, u8 A_u8State);

void MEXTI_voidEnable(u8 A_u8ExtiNumber);

void MEXTI_voidDisable(u8 A_u8ExtiNumber);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
