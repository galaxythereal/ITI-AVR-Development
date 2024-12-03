/*
 * GIE_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mahmoud Ezzat
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include <avr/io.h>

#include "../DIO/DIO_Interface.h"
#include"GIE_Interface.h"

void MGIE_voidEnable()
{
	SET_BIT(SREG,7);


}
void MGIE_voidDisable()
{

	CLR_BIT(SREG,7);

}
