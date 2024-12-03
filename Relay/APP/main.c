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
#include <util/delay.h>

#define BUTTON_PIN   0 // Assuming the button is connected to pin A0

int main(void) {
   MDIO_voidSetPortDirection('C',1);

    while (1) {

    	MDIO_voidSetPinValue('C',0,1);

    	_delay_ms(5000);
    	MDIO_voidSetPinValue('C',0, 0);
    	    	_delay_ms(5000);
        }



    return 0;
}
