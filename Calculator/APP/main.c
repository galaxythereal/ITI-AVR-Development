#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../HAL/LCD/LCD.h"
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

int main(void) {
    // Initialize LCD
    HLCD_voidInit();

    // Initialize Keypad Driver
    HKPD_voidInit();

    char input[16] = ""; // Buffer to store user input
    char operator = ' '; // Operator (+, -, *, /)
    int num1 = 0, num2 = 0, result = 0;
    int numReadState = 0; // 0 for num1, 1 for operator, 2 for num2

    while (1) {
        u8 pressedKey = HKPD_u8GetPressedKey(); // Get the pressed key from the Keypad Driver

        if (pressedKey != 255) { // Check if a key has been pressed
            if (pressedKey >= '0' && pressedKey <= '9') {
                // Numeric key pressed
                HLCD_voidSendData(pressedKey);
                input[strlen(input)] = pressedKey; // Append pressed key to input
            } else if (pressedKey == '+' || pressedKey == '-' ||
                       pressedKey == '*' || pressedKey == '/') {
                // Operator key pressed
                operator = pressedKey;
                input[strlen(input)] = '\0'; // Terminate the input string
                num1 = custom_atoi(input);
                numReadState = 1;
                input[0] = '\0'; // Clear the input buffer
                HLCD_voidSendData(operator);
            } else if (pressedKey == '=') {
                // Equals key pressed
                input[strlen(input)] = '\0'; // Terminate the input string
                num2 = custom_atoi(input);
                if (numReadState == 1 && operator != ' ') {
                    switch (operator) {
                        case '+':
                            result = num1 + num2;
                            break;
                        case '-':
                            result = num1 - num2;
                            break;
                        case '*':
                            result = num1 * num2;
                            break;
                        case '/':
                            if (num2 != 0) {
                                result = num1 / num2;
                            } else {
                                HLCD_voidSendString("Error: Division by zero");
                            }
                            break;
                        default:
                            HLCD_voidSendString("Error: Invalid operator");
                    }
                    HLCD_voidSendData('='); // Display equals sign
                    HLCD_voidSendData(result); // Display the calculated result
                }
                numReadState = 0;
                input[0] = '\0'; // Clear the input buffer
            } else if (pressedKey == '#') {
                // Clear key pressed
                input[0] = '\0'; // Clear the input buffer
                numReadState = 0;
                operator = ' ';
                HLCD_voidClearScreen(); // Clear the LCD screen
            }
        }
        _delay_ms(100); // Add a delay to prevent excessive loop iteration
    }

    return 0;
}
