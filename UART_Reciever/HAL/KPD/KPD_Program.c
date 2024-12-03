

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_Interface.h"

#include"KPD_Interface.h"



u8 G_u8KeyPadButtons[4][4] = {
		{'7', '8', '9', '/'},
		{'4', '5', '6', '*'},
		{'1', '2', '3', '-'},
		{'#', '0', '=', '+'}
};


u8 HKPD_u8GetPressedKey(){

	u8 L_u8PressedKey = 255, Row, Col;

	for(Col =0; Col<4; Col++){
		/*Activate Current Col*/
		MDIO_voidSetPinValue('D', Col, 0);

		for(Row = 0; Row<4; Row++){
			u8 L_u8PinValue = MDIO_u8GetPinValue('D', (Row+4));

			if(L_u8PinValue == 0){
				L_u8PressedKey = G_u8KeyPadButtons[Row][Col];

				while(MDIO_u8GetPinValue('D', (Row+4)) == 0);

				return L_u8PressedKey;
			}

		}
		/*Deactivate Current Col*/
	   MDIO_voidSetPinValue('D', Col, 1);

	}
	return L_u8PressedKey;

}
