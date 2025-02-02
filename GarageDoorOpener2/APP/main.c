#include "../HAL/LCD/LCD.h"
#include  "../HAL/ULTRASONIC/ultrasonic.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include<avr/interrupt.h>


int main(){

	// Initialize system and components
	  HSNC_voidInit();

	  // Main loop
	  while (1) {
	    // Trigger ultrasonic sensor for distance measurement
	    HSNC_voidTrigger();

	    // Handle ultrasonic measurement and timeout
HSNC_voidHandleMeasurement();
HSNC_voidHandleTimeout();
	  }

	  return 0;
}


