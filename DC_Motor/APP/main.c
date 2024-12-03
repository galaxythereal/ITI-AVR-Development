/*
 * main.c

 *
 *  Created on: Aug 15, 2023
 *      Author: Mahmoud Ezzat
 */
#include<util/delay.h>
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/MOTOR/motorInterface.h"





int main(void) {

	motorInit();


	while(1)
	{
	motorForward();


	_delay_ms(1000);
	motorStop();
	//reversing direction
	motorReverse();
	_delay_ms(1000);
	motorStop();

	}


	return 0;
}
