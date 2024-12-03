

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include"Timer_Interface.h"


/*
 *
 *
 * Timer Modes
 * A_u8TimerMode ------>>>  0  ----->>>> Normal
 *
 * A_u8TimerMode ------>>>  1  ----->>>> CTC
 * A_u8TimerMode ------>>>  2  ----->>>> Fast PWM
 *
 * */



void MTimer_voidTimerInit(u8 A_u8TimerMode){

	if(A_u8TimerMode == 0){
		/*Normal Mode*/
		CLR_BIT(TCCR0, 6);
		CLR_BIT(TCCR0,3);

		/*Set Timer Interrupt Enable*/
		SET_BIT(TIMSK, 0);
	}
	else if(A_u8TimerMode == 1){
		/*CTC Mode*/
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		/*SET CTC Interrupt Enable*/
		SET_BIT(TIMSK,1);
	}else if(A_u8TimerMode == 2){
		SET_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);

		/*Clear on compare set On Top*/
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0, 4);

	}
}


void MTimer_voidStart(){

	/*
	 * Choose Prescaller 8
	 * */
	CLR_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);

}

void MTimer_voidStop(){
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}

void MTimer_voidSetPreloadValue(u8 A_u8TimerMode, u8 A_u8PreloadValue){
	if(A_u8TimerMode == 0){
		TCNT0 = A_u8PreloadValue;

	}else{
		OCR0 = A_u8PreloadValue;
	}
}


/////////////////////////////////Timer1///////////////////////


void MTimer1_voidInit(){
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}


void MTimer1_voidSetTimer1Value(u16 A_u16Value){
	TCNT1 = A_u16Value;
}

u16 MTimer1_u16ReadTimer1Value(){
	return TCNT1;
}

