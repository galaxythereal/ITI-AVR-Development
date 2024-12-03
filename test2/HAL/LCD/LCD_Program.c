#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include"LCD.h"
#include<avr/delay.h>

void HLCD_voidSendCommand(u8 A_u8Cmd)
{
	//initialize control pins
	MDIO_voidSetPinValue('A', 0, 0);
	MDIO_voidSetPinValue('A', 1, 0);

	//Write command on data pins
	MDIO_voidSetPortValue('C', A_u8Cmd);

	//pulse on enable pin 1.53ms 1
	MDIO_voidSetPinValue('A', 2, 1);
	_delay_ms(2);
	MDIO_voidSetPinValue('A', 2, 0);
	_delay_ms(2);
}

void HLCD_voidSendData(u8 A_u8Data)
{
	MDIO_voidSetPinValue('A',0,1);
	MDIO_voidSetPinValue('A',1,0);
	//Write data
	MDIO_voidSetPortValue('C',A_u8Data);

	//pulse on enable pin
	MDIO_voidSetPinValue('A',2,1);
	_delay_ms(2);
	MDIO_voidSetPinValue('A',2,0);
	_delay_ms(2);
}

void HLCD_voidInit()
{
	//Wait for more than 30 micros
	_delay_ms(40);

	//Function set 0b00111000
	HLCD_voidSendCommand(0b00111000);

	//Wait for 40 ms
	_delay_ms(1);

	//Display ON/OFF  0b00001111
	HLCD_voidSendCommand(0b00001111);

	//Wait for 40 ms
	_delay_ms(1);

	//Clear Display 0b0000001 -----------
	HLCD_voidSendCommand(0b00000001);

	//wait for 2ms
	_delay_ms(2);

	//Entry mode set 0b00000110
	HLCD_voidSendCommand(0b00000110);

}

void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col)
{
	u8 L_u8DDRamAddress ;
	if(A_u8Row < 2 && A_u8Col < 16 )
	{
		if(A_u8Row == 0)
		{
			L_u8DDRamAddress = 0x00+A_u8Col;
		}
		else
		{
			L_u8DDRamAddress = 0x40+A_u8Col;
		}
		SET_BIT(L_u8DDRamAddress, 7);
		HLCD_voidSendCommand(L_u8DDRamAddress);

	}
}



void HLCD_voidSendString(u8 *String){
	u8 i =0;
	while(String[i] != '\0'){
		HLCD_voidSendData(String[i]);
		i++;
	}
}



void HLCD_voidDisplayNumber(s32 A_s32Number)
{
	u32 local_u32Number=1;
	if (A_s32Number==0)
	{
		HLCD_voidSendData('0');
	}
	if (A_s32Number<0)
	{
		HLCD_voidSendData('-');
		A_s32Number *=-1;
	}
	while (A_s32Number!=0)
	{
		local_u32Number = ((local_u32Number * 10)+(A_s32Number % 10));
		A_s32Number = A_s32Number /10;
	}
	while (local_u32Number!=1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number=local_u32Number/10;
	}
}



