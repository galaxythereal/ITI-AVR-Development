/*
 * motor.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Mahmoud Ezzat
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include"motorInterface.h"
#include<util/delay.h>
#include<avr/io.h>

void motorReverse(void)
{

	MDIO_voidSetPinValue(port,backwardPin,1);

}

void motorForward(void)
{

	MDIO_voidSetPinValue(port,forwardPin,1);

}

void motorStop(void)
{

	MDIO_voidSetPinValue(port,forwardPin,0);
	MDIO_voidSetPinValue(port,backwardPin,0);

}


void motorInit(void)
{


	MDIO_voidSetPortDirection(port,0xFF);

}
