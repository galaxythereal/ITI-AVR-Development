#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD.h"
#include<util/delay.h>

#include"../MCAL/SPI/SPI_Interface.h"

int main() {
    // Initialize LCD
    MDIO_voidSetPortDirection('D', 0xFF);
    MDIO_voidSetPortDirection('C', 0xFF);
    HLCD_voidInit();

    // Initialize SPI as Slave
    MDIO_voidSetPinDirection('B', 4, 0); // SS Pin
    MDIO_voidSetPinDirection('B', 5, 0); // MOSI Pin
    MDIO_voidSetPinDirection('B', 6, 1); // MISO Pin
    MDIO_voidSetPinDirection('B', 7, 0); // SCK Pin

    MSPI_voidSlaveInit();
    // Buffer to store received message
    char receivedMessage[20];

	HLCD_voidGoTo(0,0);

    for(int i=0 ; i<=19;i++)
    {

    	receivedMessage[i]= MSPI_u8Transcieve('1');

    	}
while (1){
    for (int i=0; i<=19; i++)
    {
    	HLCD_voidSendData(receivedMessage[i]);
    //	_delay_ms(200);
    }
    _delay_ms(1000);
	HLCD_voidClearScreen();
    _delay_ms(500);
}

    return 0;
}
