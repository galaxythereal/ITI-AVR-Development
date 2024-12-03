/*
 * KPD_Program.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mahmoud Ezzat
 */



#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_Interface.h"




u8 G_u8KPDButtons[4][4] ={
		{'7', '8', '9', '/'},
		{'4', '5', '6', '*'},
		{'1', '2', '3', '-'},
		{'#', '0', '=', '+'}
};



/*
 *
 *
 * */

u8 HKPD_u8GetPressedKey(){
	u8 Local_u8PressedKey=255, Col, Row;

	for(Col = 0; Col<4; Col++){
		/*Activate Current Col*/
		MDIO_voidSetPinValue('D',Col ,0);

		for(Row = 0; Row<4; Row++){

			u8 L_u8PinValue = MDIO_u8GetPinValue('D', (Row+4));

			/*Check If Key Is Pressed*/
			if(L_u8PinValue == 0){
				Local_u8PressedKey = G_u8KPDButtons[Row][Col];

				while(MDIO_u8GetPinValue('D', (Row+4)) == 0);

				return Local_u8PressedKey;
			}
		}
		/*Deactivate Current Col*/
		MDIO_voidSetPinValue('D',Col ,1);
	}
	return Local_u8PressedKey;

}


