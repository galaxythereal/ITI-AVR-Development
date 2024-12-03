#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../HAL/sevenSegment/sevenSegmentInterface.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/KPD/KPD_Interface.h"
#include<util/delay.h>

int main(void) {
    MDIO_voidSetPortDirection('C', 0xFF);
    MDIO_voidSetPortDirection('D', 0xFF);
    MDIO_voidSetPortDirection('B', 0xFF);

    // Initialize LCD
    HLCD_voidInit();

    HKPD_voidInit(); // Initialize the Keypad Driver
    SevenSegmentDriver_init();
    u8 SevenSegNumbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    while (1) {
        u8 pressedKey = HKPD_u8GetPressedKey(); // Get the pressed key from the Keypad Driver

        if (pressedKey != 0xFF) { // Check if a key has been pressed
            // A key has been pressed
            // Process the pressed key as needed
            // For example, you can display the key on an LCD or LED
            HLCD_voidSendData(pressedKey);
        }

        switch (pressedKey) {
            case '0': MDIO_voidSetPortValue('B', SevenSegNumbers[0]); break;
            case '1': MDIO_voidSetPortValue('B', SevenSegNumbers[1]); break;
            case '2': MDIO_voidSetPortValue('B', SevenSegNumbers[2]); break;
            case '3': MDIO_voidSetPortValue('B', SevenSegNumbers[3]); break;
            case '4': MDIO_voidSetPortValue('B', SevenSegNumbers[4]); break;
            case '5': MDIO_voidSetPortValue('B', SevenSegNumbers[5]); break;
            case '6': MDIO_voidSetPortValue('B', SevenSegNumbers[6]); break;
            case '7': MDIO_voidSetPortValue('B', SevenSegNumbers[7]); break;
            case '8': MDIO_voidSetPortValue('B', SevenSegNumbers[8]); break;
            case '9': MDIO_voidSetPortValue('B', SevenSegNumbers[9]); break;
         //   default:  MDIO_voidSetPortValue('B', 0x00); // Clear the seven-segment display
        }

        _delay_ms(100); // Add a delay to prevent excessive loop iteration
    }

    return 0;
}
