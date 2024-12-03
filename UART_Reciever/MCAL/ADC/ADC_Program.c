
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>

#include"ADC_Interface.h"


/*
 * AREF   ----- 0
 * AVCC  -------1
 * Internal     2
 *
 * */


void MADC_voidInit(u8 A_u8Vref){

	switch(A_u8Vref){
		case 0:
			CLR_BIT(ADMUX, 6);
			CLR_BIT(ADMUX, 7);
		break;

		case 1:
			SET_BIT(ADMUX, 6);
			CLR_BIT(ADMUX, 7);
		break;

		case 2:
			SET_BIT(ADMUX, 6);
			SET_BIT(ADMUX, 7);
		break;
	}
	/*Left|Right Adjust*/
	SET_BIT(ADMUX, 5);

	/*128 Prescaller*/
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);

	/*ADC Enable*/
	SET_BIT(ADCSRA, 7);
}


u8 MADC_u8GetChannelReading(u8 A_u8Channel){

	ADMUX = ADMUX & 0b11100000;
	ADMUX = ADMUX|A_u8Channel;

	/*Start Conversion*/
	SET_BIT(ADCSRA, 6);

	/*Wait Till Adc Flag Is Fired (1) */
	while(GET_BIT(ADCSRA, 4) == 0);
	/*Clear ADC FLAG*/
	SET_BIT(ADCSRA, 4);

	return ADCH;

}


