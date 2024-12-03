/*
 * LCD.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mahmoud Ezzat
 */

#ifndef _7SEGMENT_DRIVER_H_
#define _7SEGMENT_DRIVER_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h" // Include your MDIO library header

//// Define the common cathode pins of the 7-segment display
//#define COMMON_CATHODE_1 7 // Connect to the common cathode pin of the first 7-segment display
//#define COMMON_CATHODE_2 6 // Connect to the common cathode pin of the second 7-segment display
#define SEGMENT_PORT 'C'
void SevenSegmentDriver_init(void);
void SevenSegmentDriver_displayDigit(u8 digit);

#endif // _7SEGMENT_DRIVER_H_


