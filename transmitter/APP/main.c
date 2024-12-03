

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"

#include"../HAL/LCD/LCD.h"
#include<util/delay.h>

#include"../MCAL/UART/UART_Interface.h"





int main() {
    MUART_voidInit();

    while (1) {
        MUART_voidTransmit('M');
        MUART_voidTransmit('A');
        MUART_voidTransmit('H');
        MUART_voidTransmit('M');
        MUART_voidTransmit('O');
        MUART_voidTransmit('U');
        MUART_voidTransmit('D');

        _delay_ms(1000);
    }

    return 0;
}
