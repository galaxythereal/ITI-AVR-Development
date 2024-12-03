/*
 * SPI_Program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Mahmoud Ezzat
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<avr/io.h>
#include"SPI_Interface.h"

void MSPI_voidMasterInit()
{
	/*SPI Master Mode*/
	SET_BIT(SPCR,4);
	/*SPI Enable*/
	SET_BIT(SPCR,6);
	/*Master Clock Choosing (f/16)*/
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR, 1);
	CLR_BIT(SPSR, 0);
}

void MSPI_voidSlaveInit ()
{

	/*SPI Slave Mode */
	CLR_BIT(SPCR,4);
	/*SPI Enable*/
	SET_BIT(SPCR,6);
}
u8 MSPI_u8Transcieve(u8 A_u8Data)
{

	 // Load data into the SPI data register
	    SPDR = A_u8Data;

	    // Wait until transmission complete
	    while (!GET_BIT(SPSR, SPIF));

	    // Return the received data
	    return SPDR;

}
