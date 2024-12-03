#include "../HAL/LCD/LCD.h"
#include  "../HAL/ULTRASONIC/ultrasonic.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"


int main(){

HLCD_voidInit();
HSNC_voidInit();

MGIE_voidEnable();

HLCD_voidSendString("Distance is ");
_delay_ms(10);
while(1){
HSNC_voidTrigger();
_delay_ms(150);

}

  return 0;
}


