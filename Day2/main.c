/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mahmoud Ezzat
 */


#include <avr/io.h>
#include <util/delay.h>

const uint8_t segmentPatterns[6] = {
 0b00000010,
 0b00000100,
 0b00001000,
 0b00010000,
 0b00100000,
 0b01000000
};

int main(void) {

    DDRA = 0xFF;
    DDRC= 0b00000000;
    PORTC=0x01;

    while (1) {

    	if( (((PINC)>>(0))& 0x01)== 0)
    	{
         PORTA=0xFF;
         _delay_ms(500);
         PORTA=0x00;
         _delay_ms(500);
        }

    }
    }



