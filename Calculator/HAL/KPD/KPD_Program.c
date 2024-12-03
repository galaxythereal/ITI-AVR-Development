#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KPD_Interface.h"
#include <util/delay.h>

#define DEBOUNCE_DELAY_MS 50
#define LONG_PRESS_DELAY_MS 1000

u8 G_u8KeyPadButtons[4][4] = {
		{'#', '0', '=', '+'},
		{'1', '2', '3', '-'},
		{'4', '5', '6', '*'},
	{'7', '8', '9', '/'}
};
void HKPD_voidInit(void) {
    // Set columns as outputs and rows as inputs
    for (u8 col = 0; col < 4; col++) {
        MDIO_voidSetPinDirection('A', col, 1); // Columns as outputs
    }
    for (u8 row = 0; row < 4; row++) {
        MDIO_voidSetPinDirection('A', (row + 4), 0); // Rows as inputs
        MDIO_voidSetPinValue('A', (row + 4), 1); // Enable pull-up resistors
    }
}

u8 HKPD_u8GetPressedKey() {
    u8 L_u8PressedKey = 255, Row, Col;

    for (Col = 0; Col < 4; Col++) {
        /* Activate Current Col */
        MDIO_voidSetPinValue('A', Col, 0);

        for (Row = 0; Row < 4; Row++) {
            u8 L_u8PinValue = MDIO_u8GetPinValue('A', (Row + 4));

            if (L_u8PinValue == 0) {
                _delay_ms(DEBOUNCE_DELAY_MS);

                // Wait for the button to be released
                while (MDIO_u8GetPinValue('A', (Row + 4)) == 0);

                L_u8PressedKey = G_u8KeyPadButtons[Row][Col];

                // Check for long press
                _delay_ms(LONG_PRESS_DELAY_MS);
                if (MDIO_u8GetPinValue('A', (Row + 4)) == 0) {
                    // Long press detected
                    L_u8PressedKey = G_u8KeyPadButtons[Row][Col] + 0x80;
                }

                return L_u8PressedKey;
            }
        }
        /* Deactivate Current Col */
        MDIO_voidSetPinValue('A', Col, 1);
    }
    return L_u8PressedKey;
}
