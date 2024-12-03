/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mahmoud Ezzat
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/sevenSegment/sevenSegmentInterface.h"
#include<util/delay.h>



int main(void) {
    SevenSegmentDriver_init();

    while (1) {

        for (u8 digit = 0; digit < 10; digit++) {
            SevenSegmentDriver_displayDigit(digit);
        }
    }

    return 0;
}
