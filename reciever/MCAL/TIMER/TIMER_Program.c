
#include<avr/io.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include"Timer_Interface.h"


/*
 * Timer Options
 *
 * A_u8TimerMode-----> 0 ------> NormalMode
 * A_u8TimerMode-----> 1 ------> Compare
 * A_u8TimerMode-----> 2 ------> Fast PWM
 * */

void MTimer_voidTimerInit(u8 A_u8TimerMode){
	/*Choose Timer Mode*/
	if(A_u8TimerMode == 0){
		CLR_BIT(TCCR0,6);
		CLR_BIT(TCCR0,3);

		/*Set Timer Interrupt Enalbe*/
		SET_BIT(TIMSK, 0);

	}
	else if (A_u8TimerMode == 1){

		CLR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

		/*Set Compare Interrupt Enalbe*/
		 SET_BIT(TIMSK, 1);
	}
	else if(A_u8TimerMode == 2){

		SET_BIT(TCCR0, 6);
		SET_BIT(TCCR0, 3);

		/*Set On Top Clear On compare
		 * */
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
	}


}


void MTimer_voidSetPreloadValue(u8 A_u8Preload, u8 A_u8TimerMode){
	if(A_u8TimerMode == 0){
		TCNT0 = A_u8Preload;
	}
	else{
		/*Set Compare Reg Value*/
		OCR0 = A_u8Preload;
	}
}



void MTimer_voidStart(){

	/*Choose Prescaller 8*/
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

}
void MTimer_voidStop(){
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

}




void MTimer1_voidInit(){
	/*Select Ps 8* */
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}


void MTimer1_voidSetValue(u16 A_u16Value){
	TCNT1 = A_u16Value;
}

u16 MTimer1_u16ReadTimer1Value(){
	return TCNT1;
}


