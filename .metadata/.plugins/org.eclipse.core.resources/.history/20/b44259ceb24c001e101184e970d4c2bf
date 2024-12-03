//
//#include "../../LIB/STD_TYPES.h"
//#include "../../LIB/BIT_MATH.h"
//#ifndef MCAL_I2C_I2C_INTERFACE_H_
//#define MCAL_I2C_I2C_INTERFACE_H_
//
//typedef enum{
//	NoError,
//	StartConditionErr,
//	SlaveAdderssWithWriteErr,
//	MasterWriteDataErr,
//	SlaveAdderessRecievedErr,
//	SlaveDataRecievedErr,
//	SlaveAdderssWithReadErr,
//	MasterReadDataErr,
//
//}TWI_ErrStatus;
//
//void MTWI_voidMasterInit();
//
//void MTWI_voidSlaveInit(u8 A_u8SalveAddress);
//TWI_ErrStatus MTWI_SendSlaveAdderssWithRead(u8 A_u8SalveAddress);
//TWI_ErrStatus MTWI_MasterReadDataByte(uint8_t *A_pu8RecievedData, u8 A_u8AckState);
//TWI_ErrStatus MTWI_SendStartCondition();
//
//TWI_ErrStatus MTWI_SendSlaveAdderssWithWrite(u8 A_u8SalveAddress);
//TWI_ErrStatus MTWI_MasterWriteDataByte(u8 A_u8Data);
//
//TWI_ErrStatus MTWI_SLaveReading(u8 *A_pu8RecievedData);
//void MTWI_voidSendStopCondition();
//
//
//#endif /* MCAL_I2C_I2C_INTERFACE_H_ */

#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

// Define TWI error status codes
typedef enum {
    NoError = 0,
    StartConditionErr,
    SlaveAdderssWithWriteErr,
    SlaveAdderssWithReadErr,
    MasterReadDataErr,
    MasterWriteDataErr,
    SlaveAdderessRecievedErr,
    SlaveDataRecievedErr,
    NULLPointerErr
} TWI_ErrStatus;

// Function to initialize the TWI (I2C) module as a master
void MTWI_voidMasterInit();

// Function to initialize the TWI (I2C) module as a slave with a given address
void MTWI_voidSlaveInit(u8 A_u8SalveAddress);

// Function to send a start condition and check for errors
TWI_ErrStatus MTWI_SendStartCondition();

// Function to send the slave address with write operation and check for errors
TWI_ErrStatus MTWI_SendSlaveAdderssWithWrite(u8 A_u8SalveAddress);

// Function to send the slave address with read operation and check for errors
TWI_ErrStatus MTWI_SendSlaveAdderssWithRead(u8 A_u8SalveAddress);

// Function to read a byte of data during an I2C communication
TWI_ErrStatus MTWI_MasterReadDataByte(uint8_t *A_pu8RecievedData, u8 A_u8AckState);

// Function to write a byte of data during an I2C communication
TWI_ErrStatus MTWI_MasterWriteDataByte(u8 A_u8Data);

// Function to perform slave reading during an I2C communication
TWI_ErrStatus MTWI_SLaveReading(u8 *A_pu8RecievedData);

// Function to send a stop condition on the I2C bus
void MTWI_voidSendStopCondition();

#endif /* I2C_INTERFACE_H */
