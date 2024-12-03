/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mahmoud Ezzat
 */
#include"../MCAL/DIO/DIO_Interface.h"
#include"../LIB/BIT_MATH.h"
#include"../LIB/STD_TYPES.h"
#include <util/delay.h>


const u8 segmentPatterns[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

int main(void) {

   MDIO_voidSetPortDirection('C',1);

    while (1) {

        for (u8 i = 0; i < 10; i++) {
           MDIO_voidSetPortValue('C',segmentPatterns[i]);

            _delay_ms(1000);
        }
    }

    return 0;
}
