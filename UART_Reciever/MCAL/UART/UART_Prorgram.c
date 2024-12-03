


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include"UART_Interface.h"





void MUART_voidInit(){

	UCSRB = 0b00011000;

	UCSRC = 0b10000110;

	/*Select Baud Rate 9600*/
	UBRRL = 51;
}

void MUART_voidTransmit(u8 A_u8Data){

	/*Wait Till Transmit Buffer Is empty*/
	while(GET_BIT(UCSRA, 5) == 0);
	UDR = A_u8Data;

}

u8 MUART_u8Recieve(){
	/*Wait Till Recieve Buffer Is complete*/
	while(GET_BIT(UCSRA, 7) == 0);
	return UDR;
}





