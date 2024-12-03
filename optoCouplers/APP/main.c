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

#define BUTTON_PIN   0 // Assuming the button is connected to pin A0

int main(void) {
    // Initialize the motor and button
//    motorInit();
    MDIO_voidSetPinDirection('A', BUTTON_PIN, 0);
    MDIO_voidSetPinValue('A', BUTTON_PIN, 1); // Enable pull-up resistor
    MDIO_voidSetPinDirection('C',0,1);
    while (1) {

        if (GET_BIT(MDIO_u8GetPinValue('A', BUTTON_PIN), 0) == 0) {
            // Button is pressed

        			MDIO_voidSetPinValue('C',0,0);
        }
        else
        {

        	MDIO_voidSetPinValue('C',0,1);
        }


    }

    return 0;
}
