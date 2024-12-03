

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/KPD/KPD_Interface.h"
#include"../HAL/LCD/LCD_Interface.h"
#include<avr/delay.h>
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include"../MCAL/ADC/ADC_Interface.h"
#include"../MCAL/Timer/Timer_Interface.h"
#include<avr/interrupt.h>

#include"../MCAL/UART/UART_Interface.h"

int main(){

	/*
	 * UART As A Reciever
	 * */

	MDIO_voidSetPinDirection('A',1,1);

	MUART_voidInit();

	u8 L_u8Data;

	while(1){
		L_u8Data = MUART_u8Recieve();

		if(L_u8Data == 'A'){
			MDIO_voidSetPinValue('A',1,1);
		}

	}
}





