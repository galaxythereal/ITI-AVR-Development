#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include<util/delay.h>
#include"../MCAL/UART/UART_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"

//#include"../LIB/STD_TYPES.h"
//#include"../LIB/BIT_MATH.h"
//#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD.h"

//
//#include"../MCAL/GIE/GIE_Interface.h"
//#include"../MCAL/EXTI/EXTI_Interface.h"
//#include"../MCAL/ADC/ADC_Interface.h"
//#include<avr/interrupt.h>
//#include<util/delay.h>
//#include"../MCAL/Timer/Timer_Interface.h"

//#include <avr/io.h>
//#include "UART_Interface.h"
//#include "LCD.h"

int main(void) {
	  MDIO_voidSetPortDirection('A',0xFF);
	    MDIO_voidSetPortDirection('B',0xFF);
    MUART_voidInit(); // Initialize UART
    HLCD_voidInit();  // Initialize LCD

    while (1) {

    	  u8 dataByte = MUART_u8Recieve();

    	            // Display received data on the LCD
    	            HLCD_voidClearScreen();

    	            HLCD_voidSendData(dataByte);

    	            // Delay before clearing the LCD
    	            _delay_ms(20);


    }

    return 0;
}
