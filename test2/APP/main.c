


#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD.h"
#include"../HAL/KeyPad/KPD_Interface.h"

#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include"../MCAL/ADC/ADC_Interface.h"
#include<avr/interrupt.h>
#include<util/delay.h>
#include"../MCAL/Timer/Timer_Interface.h"


u16 G_counter, OnTicks, OffTicks;


int main()
{
	MDIO_voidSetPinDirection('B', 3, 1);
	MDIO_voidSetPinDirection('D', 2, 0);

	/*LCD Configrations*/

	MDIO_voidSetPortDirection('C', 0xff);
	MDIO_voidSetPortDirection('A', 0xff);


	MTimer_voidTimerInit(2);
	MTimer_voidSetPreloadValue(2, 64);

	MEXTI_voidSenseControl(0,3);
	MTimer_voidStart();
	MTimer1_voidInit();

	HLCD_voidInit();

	/*EXTI Enable*/
	MEXTI_voidEnable(0);

	/*Enable Global Interrupt*/
	MGIE_voidEnable();

	u8 *Str1 = "OnTicks= ";
	u8 *Str2 = "OffTicks= ";
	while(1){


		while(OnTicks == 0 && OffTicks==0);

		HLCD_voidGoTo(0,0);
		HLCD_voidSendString(Str1);
		HLCD_voidDisplayNumber(OnTicks);

		HLCD_voidGoTo(1,0);
		HLCD_voidSendString(Str2);
		HLCD_voidDisplayNumber(OffTicks);
		while(OnTicks && OffTicks);
	}

}

ISR(INT0_vect){

	G_counter++;
	/*Detect Rising Edge*/
	if(G_counter == 1){
		MTimer1_voidSetValue(0);
		MEXTI_voidSenseControl(0,2);
	}
	else if(G_counter == 2){
		/*Get Ton*/
		OnTicks = MTimer1_u16ReadTimer1Value();
		/*Detect next Rising Edge*/
		MEXTI_voidSenseControl(0,3);
		/*Set Timer1 == 0*/
		MTimer1_voidSetValue(0);
	}
	else if(G_counter == 3){
		/*Get Toff*/
		OffTicks = MTimer1_u16ReadTimer1Value();
		/*Disable INT0*/
		MEXTI_voidDisable(0);
	}
}







//
//
//ISR(TIMER1_CAPT_vect) {
//    if (captureFlag == 0) {
//        // Capture rising edge for on-time
//        onTimeCounter = ICR1;
//        captureFlag = 1;
//        TCCR1B &= ~(1 << ICES1); // Switch to capture falling edges next
//    } else {
//        // Capture falling edge for off-time
//        offTimeCounter = ICR1;
//        captureFlag = 0;
//        TCCR1B |= (1 << ICES1); // Switch to capture rising edges next
//    }
//}
