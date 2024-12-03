

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"

#include<util/delay.h>

#include"../MCAL/SPI/SPI_Interface.h"





int main(){ {


	/*SPI as Master*/
MDIO_voidSetPinDirection('B',4,0);
MDIO_voidSetPinValue('B',4,1);
//MOSI Pin
MDIO_voidSetPinDirection('B',5,1);
//MISO Pin
MDIO_voidSetPinDirection('B',6,1);
//SCK
MDIO_voidSetPinDirection('B',7,1);
MSPI_voidMasterInit();

}
for (;;)
{
	 const char message[] = "Mahmoud ";

	        // Send each character of the string to the slave
for (int i = 0; message[i] != '\0'; i++) {
     MSPI_u8Transcieve(message[i]);
	_delay_ms(10); // Delay between characters

}

}
return 0;
}
