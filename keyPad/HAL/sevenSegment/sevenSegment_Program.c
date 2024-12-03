/*
 * LCD_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mahmoud Ezzat
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include <avr/io.h>
#include <util/delay.h>

#include "sevenSegmentInterface.h"



// Define digit patterns for 0-9
static u8 digitPatterns[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

void SevenSegmentDriver_init(void) {
    MDIO_voidSetPortDirection(SEGMENT_PORT, 0xFF); // Set the segment pins as outputs

}

void SevenSegmentDriver_displayDigit(u8 digit) {
    if (digit < 10 && digit>=0) {
        // Display the digit on the first 7-segment display
        MDIO_voidSetPortValue(SEGMENT_PORT, digitPatterns[digit]);

        _delay_ms(1000);


    }
}
