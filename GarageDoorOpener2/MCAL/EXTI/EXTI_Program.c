#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "EXTI_Interface.h" // Include the EXTI library header

/*
 * A_u8State
 * 0 -------> Low
 * 1--------> on change
 * 2--------> Falling
 * 3--------> Rising
 */

// Function to configure the sense control of an external interrupt
void MEXTI_voidSenseControl(u8 A_u8ExtiNumber, u8 A_u8State) {
    switch (A_u8ExtiNumber) {
        /*EXTI INT0*/
        case 0:
            switch (A_u8State) {
                case 0:
                    CLR_BIT(MCUCR, 0); // Clear ISC00 for low-level trigger
                    CLR_BIT(MCUCR, 1); // Clear ISC01 for low-level trigger
                    break;

                case 1:
                    SET_BIT(MCUCR, 0); // Set ISC00 for any logical change trigger
                    CLR_BIT(MCUCR, 1); // Clear ISC01 for any logical change trigger
                    break;

                case 2:
                    CLR_BIT(MCUCR, 0); // Clear ISC00 for falling edge trigger
                    SET_BIT(MCUCR, 1); // Set ISC01 for falling edge trigger
                    break;

                case 3:
                    SET_BIT(MCUCR, 0); // Set ISC00 for rising edge trigger
                    SET_BIT(MCUCR, 1); // Set ISC01 for rising edge trigger
                    break;
            }
            break;
        /*EXTI INT1*/
        case 1:
            switch (A_u8State) {
                case 0:
                    CLR_BIT(MCUCR, 2); // Clear ISC10 for low-level trigger
                    CLR_BIT(MCUCR, 3); // Clear ISC11 for low-level trigger
                    break;

                case 1:
                    SET_BIT(MCUCR, 2); // Set ISC10 for any logical change trigger
                    CLR_BIT(MCUCR, 3); // Clear ISC11 for any logical change trigger
                    break;

                case 2:
                    CLR_BIT(MCUCR, 2); // Clear ISC10 for falling edge trigger
                    SET_BIT(MCUCR, 3); // Set ISC11 for falling edge trigger
                    break;

                case 3:
                    SET_BIT(MCUCR, 2); // Set ISC10 for rising edge trigger
                    SET_BIT(MCUCR, 3); // Set ISC11 for rising edge trigger
                    break;
            }
            break;
        /*EXTI INT2*/
        case 2:
            switch (A_u8State) {
                case 2:
                    CLR_BIT(MCUCSR, 6); // Clear ISC2 for falling edge trigger
                    break;
                case 3:
                    SET_BIT(MCUCSR, 6); // Set ISC2 for rising edge trigger
                    break;
            }
            break;
    }

}

// Function to enable the specified external interrupt
void MEXTI_voidEnable(u8 A_u8ExtiNumber) {
    switch (A_u8ExtiNumber) {
        case 0:
            SET_BIT(GICR, 6); // Enable INT0
            break;
        case 1:
            SET_BIT(GICR, 7); // Enable INT1
            break;
        case 2:
            SET_BIT(GICR, 5); // Enable INT2
            break;
    }
}

// Function to disable the specified external interrupt
void MEXTI_voidDisable(u8 A_u8ExtiNumber) {
    switch (A_u8ExtiNumber) {
        case 0:
            CLR_BIT(GICR, 6); // Disable INT0
            break;
        case 1:
            CLR_BIT(GICR, 7); // Disable INT1
            break;
        case 2:
            CLR_BIT(GICR, 5); // Disable INT2
            break;
    }
}





