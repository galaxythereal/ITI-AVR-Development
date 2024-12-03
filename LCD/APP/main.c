#include "../HAL/LCD/LCD.h"
#include  "../HAL/ULTRASONIC/ultrasonic.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"

int main(){

	 HLCD_voidInit();
ultrasonic_init();
MGIE_voidEnable();

HLCD_voidSendString("Distance is ");
_delay_ms(10);
while(1){
ultra_triger();
_delay_ms(15);
}

  return 0;
}


