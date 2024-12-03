#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include<avr/interrupt.h>
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include<util/delay.h>

int arr[]={0b00000001,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b10000000};


int main(){


	MDIO_voidSetPinDirection('D', 3, 0);
	MDIO_voidSetPortDirection('A', 0x00);
	/*Activate Pull up res*/

	MDIO_voidSetPinValue('D', 3,1);
	/*Global Interrupt Enable*/



	while(1){


	}
}







