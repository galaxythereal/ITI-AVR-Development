#include  "LCD.h"
#include  "ultrasonic.h"

int main(){

HLCD_voidInit();
ultrasonic_init();
sei();

HLCD_voidSendString("Distance is ");
_delay_ms(10);
while(1){
  ultra_triger();
  _delay_ms(15);
}

  return 0;
}
