#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "ultrasonic.h" // Custom header file for ultrasonic sensor
#include "../LCD/LCD.h" // Custom header file for LCD display
#include "../../MCAL/EXTI/EXTI_Interface.h" // External Interrupt control
#include "../../MCAL/GIE/GIE_Interface.h"   // Global Interrupt Enable control
#include "../../MCAL/TIMER/Timer_Interface.h" // Timer control
#include "../Servo/servo.h" // Custom header file for servo motor control

// Global variables to store sensor state, edge detection, timer, distance, and distance as a string
u8 sensor_working = 0;
u8 rising_edge = 0;
u32 timer_counter = 0;
u32 distance;
u8 distance_str[10];

// Function to initialize the ultrasonic sensor and related components
void HSNC_voidInit(void){

  // Configure the TRIGGER pin as an output
  TRIGGER_DDR |= (1 << TRIGGER);

  // Configure the ECHO pin as an input with a pull-up resistor
  ECHO_DDR &= ~(1 << ECHO);
  ECHO_PULLUP |= (1 << ECHO);

  // Configure external interrupt (INT1) to trigger on rising edge
  MEXTI_voidSenseControl(1,1);

  // Enable external interrupt (INT1)
  MEXTI_voidEnable(1);

  // Initialize Timer 0 for time measurement (assuming Timer 0 is used)
  MTimer_voidTimerInit(0);

  return;
}

// Function to trigger the ultrasonic sensor for distance measurement
void HSNC_voidTrigger(void){
  if (!sensor_working){
    // Set the TRIGGER pin high for 15 microseconds
    TRIGGER_PORT |= (1 << TRIGGER);
    _delay_us(15);
    // Set the TRIGGER pin low again
    TRIGGER_PORT &= ~(1 << TRIGGER);
    sensor_working = 1;
  }
}

// Interrupt Service Routine (ISR) for external interrupt 1 (INT1)
ISR(INT1_vect){
  if (sensor_working == 1){
    if (rising_edge == 0){
      // On the first rising edge, reset the timer (TCNT0), set the rising edge flag, and reset the timer counter
      TCNT0 = 0x00;
      rising_edge = 1;
      timer_counter = 0;
    }
    else{
      // On the second rising edge, calculate the distance based on timer values
      distance = (timer_counter * 256 + TCNT0) / 466;

      // Display the distance on an LCD
      HLCD_voidGoTo(1, 0);
      itoa(distance, distance_str, 10);
      strcat(distance_str, " cm ");
      HLCD_voidSendString(distance_str);
      _delay_ms(40);

      // Reset timer, rising edge flag, and trigger servo motor rotation if the distance is 200 cm
      timer_counter = 0;
      rising_edge = 0;
      if (distance == DESIRED_DISTANCE) {
        HSER_voidInit();
        HSER_voidRotate90();
        _delay_ms (1000);

      }
    }
  }
}

// Interrupt Service Routine (ISR) for Timer 0 overflow
ISR(TIMER0_OVF_vect){
  timer_counter++;
  if (timer_counter >730){
    TCNT0 = 0x00;
    sensor_working = 0;
    rising_edge = 0;
    timer_counter = 0;
  }
}
