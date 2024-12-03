/*
 * LCD_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mahmoud Ezzat
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>

void HLCD_voidSendString(uint8_t word[20]) {
	int i=0;
		while(word[i]!='\0')
		{
			HLCD_voidSendData(word[i]);
			i++;
		}
}


void HLCD_voidSendCommand(u8 A_u8Cmd)

{
	DATA_BUS=((A_u8Cmd&0b11110000));
		CTL_BUS &=~(1<<LCD_RS);
		CTL_BUS |=(1<<LCD_EN);
		_delay_ms(5);
		CTL_BUS &=~(1<<LCD_EN);
		_delay_ms(5);
		DATA_BUS=((A_u8Cmd&0b00001111)<<4);
		CTL_BUS |=(1<<LCD_EN);
		_delay_ms(5);
		CTL_BUS &=~(1<<LCD_EN);
		_delay_ms(5);
}

void HLCD_voidSendData(u8 A_u8Data)

{

	DATA_BUS=(( A_u8Data & 0b11110000));
		CTL_BUS|=(1<<LCD_RS);
		CTL_BUS |=(1<<LCD_EN);
		_delay_ms(5);
		CTL_BUS &=~(1<<LCD_EN);
		_delay_ms(5);
		DATA_BUS=(( A_u8Data & 0b00001111)<<4);
		CTL_BUS |=(1<<LCD_EN);
		_delay_ms(5);
		CTL_BUS &=~(1<<LCD_EN);
		_delay_ms(5);
}

void HLCD_voidInit() {
	DATA_DDR = (1<<LCD_D7) | (1<<LCD_D6) | (1<<LCD_D5)| (1<<LCD_D4);
	CTL_DDR |= (1<<LCD_EN)|(1<<LCD_RW)|(1<<LCD_RS);

	DATA_BUS = (0<<LCD_D7)|(0<<LCD_D6)|(1<<LCD_D5)|(0<<LCD_D4);
	CTL_BUS|= (1<<LCD_EN)|(0<<LCD_RW)|(0<<LCD_RS);

	_delay_ms(5);
		CTL_BUS &=~(1<<LCD_EN);
		_delay_ms(5);

		 HLCD_voidSendCommand(LCD_CMD_4BIT_2ROW_5X7);
		_delay_ms(5);
		 HLCD_voidSendCommand(LCD_CMD_DISPLAY_CURSOR_BLINK);
		_delay_ms(5);
		 HLCD_voidSendCommand(0x80);
}



void HLCD_voidClearScreen() {

	 HLCD_voidSendCommand(LCD_CMD_CLEAR_DISPLAY);
		_delay_ms(5);
}

void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col) {
	 HLCD_voidSendCommand((0x80|(A_u8Row<<6))+A_u8Col);
	_delay_us (50);
}
