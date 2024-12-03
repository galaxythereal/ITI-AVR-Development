
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>

#include"EXTI_Interface.h"


/*
 * A_u8State
 * 0 -------> Low
 * 1--------> on change
 * 2--------> Falling
 * 3--------> Rising
 *
 * */


void MEXTI_voidSenseControl(u8 A_u8ExtiNumber, u8 A_u8State){


	switch(A_u8ExtiNumber){
		/*EXTI INT0*/
		case 0:
			switch(A_u8State){
				case 0:
					CLR_BIT(MCUCR,0);
					CLR_BIT(MCUCR,1);
				break;

				case 1:
					SET_BIT(MCUCR, 0);
					CLR_BIT(MCUCR, 1);
				break;

				case 2:
					CLR_BIT(MCUCR, 0);
					SET_BIT(MCUCR, 1);
				break;

				case 3:
					SET_BIT(MCUCR, 0);
					SET_BIT(MCUCR, 1);
				break;

			}
		break;
		/*EXTI INT1*/
		case 1:
			switch(A_u8State){
				case 0:
					CLR_BIT(MCUCR,2);
					CLR_BIT(MCUCR,3);
				break;

				case 1:
					SET_BIT(MCUCR, 2);
					CLR_BIT(MCUCR, 3);
				break;

				case 2:
					CLR_BIT(MCUCR, 2);
					SET_BIT(MCUCR, 3);
				break;

				case 3:
					SET_BIT(MCUCR, 2);
					SET_BIT(MCUCR, 3);
				break;

			}
		break;

		/*EXTI INT2*/
		case 2:
			switch(A_u8State){
			case 2: CLR_BIT(MCUCSR, 6);break;
			case 3: SET_BIT(MCUCSR, 6);break;
			}
		break;

	}
}


void MEXTI_voidEnable(u8 A_u8ExtiNumber){
	switch(A_u8ExtiNumber){
		case 0: SET_BIT( GICR, 6); break;
		case 1: SET_BIT( GICR, 7); break;
		case 2: SET_BIT(GICR, 5); break;
	}

}

void MEXTI_voidDisable(u8 A_u8ExtiNumber){
	switch(A_u8ExtiNumber){
		case 0: CLR_BIT( GICR, 6); break;
		case 1: CLR_BIT( GICR, 7); break;
		case 2: CLR_BIT(GICR, 5); break;
	}
}






