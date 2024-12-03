//#include"../../LIB/STD_TYPES.h"
//#include"../../LIB/BIT_MATH.h"
//#include<avr/io.h>
//#include<stdio.h>
//#include "ultrasonic.h"
//#include "../LCD/LCD.h"
//
//
//u8 sensor_working=0;
//u8 rising_edge=0;
//u32 timer_counter=0;
//u32 distance;
//u8 distance_str[10];
//
//
//
//// Function to enable external interrupt for the sensor
//void HSNC_voidEnableInterrupt(void) {
//MCUCR |= (1 << ISC10);  // Trigger INT1 on any logic change.
//GICR |= (1 << INT1);    // Enable INT1 interrupts.
//return;
//}
//
//// Function to trigger the ultrasonic sensor measurement
//void HSNC_voidTrigger(void) {
//if (!sensor_working) {
//  TRIGGER_PORT |= (1 << TRIGGER);  // Set TRIGER pin high
//  _delay_us(15);                // Delay for 15 microseconds
//  TRIGGER_PORT &= ~(1 << TRIGGER); // Clear TRIGER pin
//  sensor_working = 1;           // Mark sensor as working
//}
//}
//
//// External interrupt service routine for the sensor
//ISR(INT1_vect) {
//if (sensor_working == 1) {
//  if (rising_edge == 0) {
//    TCNT0 = 0x00;       // Reset Timer0 counter
//    rising_edge = 1;    // Mark rising edge detected
//    timer_counter = 0;  // Reset timer counter
//  } else {
//    // Calculate distance and display it on the LCD
//    distance = (timer_counter * 256 + TCNT0) / 466;
//    HLCD_voidGoTo(1, 0);  // Set LCD cursor to the second line, first position
//    itoa(distance, distance_str, 10);  // Convert distance to string
//    strcat(distance_str, " cm ");      // Append unit
//    HLCD_voidSendString(distance_str); // Display the distance on LCD
//    _delay_ms(40);                     // Delay for stability
//    timer_counter = 0;                 // Reset timer counter
//    rising_edge = 0;                   // Clear rising edge flag
//  }
//}
//}
//
//// Timer0 overflow interrupt service routine
//ISR(TIMER0_OVF_vect) {
//timer_counter++;  // Increment timer counter
//if (timer_counter > 730) {
//  TCNT0 = 0x00;        // Reset Timer0 counter
//  sensor_working = 0;  // Mark sensor as not working
//  rising_edge = 0;     // Clear rising edge flag
//  timer_counter = 0;   // Reset timer counter
//}
//}
