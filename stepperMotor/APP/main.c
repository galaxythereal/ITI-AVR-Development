/*
 * main.c

 *
 *  Created on: Aug 15, 2023
 *      Author: Mahmoud Ezzat
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/MOTOR/motorInterface.h"
#include<util/delay.h>
#include<avr/interrupt.h>
int main(void) {
   MDIO_voidSetPortDirection('D',0xFF);

   sei();
    while (1) {

    	MDIO_voidSetPinValue('D',0,1);
    	MDIO_voidSetPinValue('D',1,0);
    	MDIO_voidSetPinValue('D',2,0);
    	MDIO_voidSetPinValue('D',3,0);

    	_delay_ms(500);

    	MDIO_voidSetPinValue('D',0, 0);
    	MDIO_voidSetPinValue('D',1,1);
    	MDIO_voidSetPinValue('D',2,0);
    	MDIO_voidSetPinValue('D',3,0);
    	_delay_ms(500);
    	MDIO_voidSetPinValue('D',0,0);
    	MDIO_voidSetPinValue('D',1,0);
    	MDIO_voidSetPinValue('D',2,1);
    	MDIO_voidSetPinValue('D',3,0);
    	_delay_ms(500);

    	MDIO_voidSetPinValue('D',0,0);

    	MDIO_voidSetPinValue('D',1,0);

    	MDIO_voidSetPinValue('D',2,0);

    	MDIO_voidSetPinValue('D',3,1);
    	_delay_ms(500);
        }



    return 0;
}
