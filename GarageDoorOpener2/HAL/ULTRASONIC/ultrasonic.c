#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include<stdio.h>
#include<stdlib.h>
#include "ultrasonic.h"
#include "../LCD/LCD.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../MCAL/TIMER/Timer_Interface.h"
#include "../Servo/servo.h"
u8 sensor_working=0;
u8 rising_edge=0;
u32 timer_counter=0;
u32 distance;
u8 distance_str[10];


// Function to initialize the ultrasonic sensor and related components
void HSNC_voidInit(void) {
  // Configure the TRIGGER pin as an output
  TRIGGER_DDR |= (1 << TRIGGER);

  // Configure the ECHO pin as an input with a pull-up resistor
  ECHO_DDR &= ~(1 << ECHO);
  ECHO_PULLUP |= (1 << ECHO);

  // Configure external interrupt (INT1) to trigger on rising edge
  MEXTI_voidSenseControl(1, 1);

  // Enable external interrupt (INT1)
  MEXTI_voidEnable(1);

  // Initialize Timer 0 for time measurement (assuming Timer 0 is used)
  MTimer_voidTimerInit(0);
}

// Function to trigger the ultrasonic sensor for distance measurement
void HSNC_voidTrigger(void) {
  if (!sensor_working) {
    // Set the TRIGGER pin high for 15 microseconds
    TRIGGER_PORT |= (1 << TRIGGER);
    _delay_us(15);
    // Set the TRIGGER pin low again
    TRIGGER_PORT &= ~(1 << TRIGGER);
    // Mark the sensor as working
    sensor_working = 1;
  }
}

// Function to handle ultrasonic measurement and display
void HSNC_voidHandleMeasurement(void) {
  if (sensor_working == 1) {
    if (rising_edge == 0) {
      // On the first rising edge, reset the timer (TCNT0), set the rising edge flag, and reset the timer counter
      TCNT0 = 0x00;
      rising_edge = 1;
      timer_counter = 0;
    } else {
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
      }
    }
  }
}

// Function to handle timeout when the timer counter exceeds a threshold
void HSNC_voidHandleTimeout(void) {
  if (timer_counter > TIMEOUT_THRESHOLD) {
    TCNT0 = 0x00;
    sensor_working = 0;
    rising_edge = 0;
    timer_counter = 0;
  }
}
