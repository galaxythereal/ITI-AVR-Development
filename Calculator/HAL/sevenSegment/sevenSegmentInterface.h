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


#define SEGMENT_PORT 'B'
void SevenSegmentDriver_init(void);
void SevenSegmentDriver_displayDigit(u8 digit);

#endif // _7SEGMENT_DRIVER_H_


