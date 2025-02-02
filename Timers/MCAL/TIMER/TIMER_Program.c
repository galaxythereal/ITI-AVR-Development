#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Timer_Interface.h"

/*
 * Timer Options
 *
 * A_u8TimerMode ----> 0 ------> Normal Mode
 * A_u8TimerMode ----> 1 ------> Compare Mode
 * A_u8TimerMode ----> 2 ------> Fast PWM Mode
 */

/**
 * @brief Initialize the timer with the specified mode.
 *
 * @param A_u8TimerMode: The desired timer mode (0 for Normal, 1 for Compare, 2 for Fast PWM).
 */
void MTimer_voidTimerInit(u8 A_u8TimerMode) {
    /* Choose Timer Mode */
    if (A_u8TimerMode == 0) {
        CLR_BIT(TCCR0, 6); // Clear WGM00 bit for Normal Mode
        CLR_BIT(TCCR0, 3); // Clear WGM01 bit for Normal Mode

        /* Set Timer Overflow Interrupt Enable */
        SET_BIT(TIMSK, 0);
    } else if (A_u8TimerMode == 1) {
        CLR_BIT(TCCR0, 6); // Clear WGM00 bit for CTC Mode
        SET_BIT(TCCR0, 3); // Set WGM01 bit for CTC Mode

        /* Set Compare Match Interrupt Enable */
        SET_BIT(TIMSK, 1);
    } else if (A_u8TimerMode == 2) {
        SET_BIT(TCCR0, 6); // Set WGM00 bit for Fast PWM Mode
        SET_BIT(TCCR0, 3); // Set WGM01 bit for Fast PWM Mode

        /* Set OC0 as Non-inverted PWM */
        SET_BIT(TCCR0, 5);
        CLR_BIT(TCCR0, 4);
    }
}


/**
 * @brief Set the preload value of the timer.
 *
 * @param A_u8Preload: The preload value to set.
 * @param A_u8TimerMode: The current timer mode (0 for Normal, 1 for Compare, 2 for Fast PWM).
 */
void MTimer_voidSetPreloadValue(u8 A_u8Preload, u8 A_u8TimerMode) {
    if (A_u8TimerMode == 0) {
        TCNT0 = A_u8Preload; // Set Timer0 preload value for Normal Mode
    } else {
        /* Set Compare Register Value */
        OCR0 = A_u8Preload; // Set Timer0 Compare Match value for Compare and Fast PWM Modes
    }
}

/**
 * @brief Start the timer with a prescaler of 8.
 */
void MTimer_voidStart() {
    /* Choose Prescaler 8 */
    CLR_BIT(TCCR0, 0);
    SET_BIT(TCCR0, 1);
    CLR_BIT(TCCR0, 2);
}

/**
 * @brief Stop the timer (disable the clock source).
 */
void MTimer_voidStop() {
    CLR_BIT(TCCR0, 0);
    CLR_BIT(TCCR0, 1);
    CLR_BIT(TCCR0, 2);
}

/**
 * @brief Initialize Timer1 with a prescaler of 8.
 */
void MTimer1_voidInit() {
    /* Select Prescaler 8 */
    CLR_BIT(TCCR1B, 0);
    SET_BIT(TCCR1B, 1);
    CLR_BIT(TCCR1B, 2);
}

/**
 * @brief Set the value of Timer1.
 *
 * @param A_u16Value: The value to set in Timer1.
 */
void MTimer1_voidSetValue(u16 A_u16Value) {
    TCNT1 = A_u16Value;
}

/**
 * @brief Read the current value of Timer1.
 *
 * @return The current value of Timer1.
 */
u16 MTimer1_u16ReadTimer1Value() {
    return TCNT1;
}
void timer0_init(void)
{
	    	/* Disable Timer 0 */
	    	TCCR0 = 0x00;
	    	/* Setting pre scaler */
	    	TCCR0 = 0x01;
	    	/* Initializing the timer with zero */
	    	TCNT0 = 0x00;
				/* Timer overflow interrupt enable*/
				TIMSK |=(1<<TOIE0);

	return;
}
