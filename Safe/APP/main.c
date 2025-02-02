

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"

#include"../HAL/LCD/LCD.h"
#include<util/delay.h>
#include"../MCAL/I2C/I2C_Interface.h"
#include"../MCAL/EEPROM/EEPROM.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
//
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
//#include "I2C_Interface.h"
//#include "LCD_Driver.h"
//#include "Keypad_Driver.h"

#define EEPROM_ADDRESS 0xA0 // I2C address of the external EEPROM
#define EEPROM_PIN_ADDR 0x0000 // EEPROM address to store the PIN code
#define PIN_LENGTH 4
#define MAX_ATTEMPTS 3

void Initialize() {
    // Initialize peripherals
    HLCD_Init();
    Keypad_Init();
    MTWI_voidMasterInit();
}

void DisplayWelcomeMessage() {
    HLCD_voidClearScreen();
    HLCD_voidSendString("Welcome to Safe");
    _delay_ms(1000);
    HLCD_voidClearScreen();
}

void EnterPIN(char* pin) {
    HLCD_voidSendString("Enter PIN: ");
    for (int i = 0; i < PIN_LENGTH; i++) {
        pin[i] = HKPD_u8GetPressedKey();
        HLCD_voidSendData(pin[i]);
    }
    HLCD_voidSendString(" "); // Clear the last entered character
}

int VerifyPIN(const char* enteredPIN, const char* storedPIN) {
    return strncmp(enteredPIN, storedPIN, PIN_LENGTH) == 0;
}

int main() {
    char enteredPIN[PIN_LENGTH + 1]; // +1 for null terminator
    char storedPIN[PIN_LENGTH + 1];  // +1 for null terminator
    int attempts = 0;

    Initialize();
    MTWI_voidMasterInit();

    while (1) {
        DisplayWelcomeMessage();
        EnterPIN(enteredPIN);

        // Read the stored PIN code from the external EEPROM
        MTWI_SendStartCondition();
        MTWI_SendSlaveAdderssWithRead(EEPROM_ADDRESS);
        MTWI_MasterReadDataByte((uint8_t*)storedPIN, 1); // Read PIN with ACK
        MTWI_MasterReadDataByte((uint8_t*)(storedPIN + 1), 0); // Read last digit with NACK
        MTWI_voidSendStopCondition();

        if (VerifyPIN(enteredPIN, storedPIN)) {
            HLCD_voidClearScreen();
            HLCD_voidSendString("Access Granted");
            break;
        } else {
            attempts++;
            HLCD_voidClearScreen();
            HLCD_voidSendString("Access Denied");

            if (attempts >= MAX_ATTEMPTS) {
                HLCD_voidGoTo(1, 0);
                HLCD_voidSendString("Maximum attempts");
                HLCD_voidGoTo(2, 0);
                HLCD_voidSendString("Reached. Locked!");
                break;
            }

            _delay_ms(2000);
        }
    }

    while (1) {
        // Implement further actions for granted access, e.g., controlling a safe mechanism
    }

    return 0;
}
