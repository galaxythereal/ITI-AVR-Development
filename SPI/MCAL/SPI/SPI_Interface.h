/*
 * SPI_Interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Mahmoud Ezzat
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
void MSPI_voidSlaveInit ();
void MSPI_voidMasterInit();
u8 MSPI_u8Transcieve(u8 A_u8Data);
#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
