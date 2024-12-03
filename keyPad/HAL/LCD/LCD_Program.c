/*
 * LCD_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mahmoud Ezzat
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_Interface.h"
#include"LCD.h"
#include <avr/io.h>
#include <util/delay.h>


void HLCD_voidSendCommand(u8 A_u8Cmd)


{
//	Initialize control Pins
	MDIO_voidSetPinValue('C',0,0);
	MDIO_voidSetPinValue('C',1,0);
	//write command on Data Pins
	MDIO_voidSetPortValue('D', A_u8Cmd);
	MDIO_voidSetPinValue('C',2,1);
	_delay_ms(40);
	MDIO_voidSetPinValue('C',2,0);
	_delay_ms(40);

}

void HLCD_voidSendData(u8 A_u8Data)

{

	  //Initialize control  Pins
		MDIO_voidSetPinValue('C',0,1);
		MDIO_voidSetPinValue('C',1,0);
		//write command on Data Pins
		MDIO_voidSetPortValue('D', A_u8Data);
		MDIO_voidSetPinValue('C',2,1);
		_delay_ms(1);
		MDIO_voidSetPinValue('C',2,0);
		_delay_ms(1);

}

void HLCD_voidInit()
{

	//wait for more than 30ms
	_delay_ms(40);

	//function set0b00111000
	HLCD_voidSendCommand(0b00111000);
	//wait for 40us
	_delay_ms(1);
	//display on/off control
	HLCD_voidSendCommand(0b00001111);
	_delay_ms(1);
	//display clear
	HLCD_voidSendCommand(0b00000001);
	_delay_ms(1);
	//entry mode set
	HLCD_voidSendCommand(0b000001);
	_delay_ms(1);
}

void HLCD_voidClearScreen() {

    HLCD_voidSendCommand(0b00000001); // Send clear display command
    _delay_ms(2); // Give the LCD some time to clear the display
}


void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col)
{
	u8 L_u8DDRamAddress;
	if(A_u8Row<2&& A_u8Col<16)
	{

		L_u8DDRamAddress=0x00+A_u8Col;
	}
	else
	{

		L_u8DDRamAddress=0x40+A_u8Col;
	}
	SET_BIT(L_u8DDRamAddress, 7);
	HLCD_voidSendCommand(L_u8DDRamAddress);



}


