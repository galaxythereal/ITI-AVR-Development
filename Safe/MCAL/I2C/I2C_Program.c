#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "I2C_Interface.h"
#include<stdio.h>

// Function to initialize the TWI (I2C) module as a master
void MTWI_voidMasterInit() {
    // SET clock frequency 200Kbps
    TWBR = 72;

    // Clear 2 bits of TWPS
    CLR_BIT(TWSR, 0);
    CLR_BIT(TWSR, 1);

    // Enable TWI
    SET_BIT(TWCR, 2);
}

// Function to initialize the TWI (I2C) module as a slave with a given address
void MTWI_voidSlaveInit(u8 A_u8SalveAddress) {
    // Initialize slave address
    TWAR = (A_u8SalveAddress << 1);

    // Enable TWI
    SET_BIT(TWCR, 2);
}

// Function to send a start condition and check for errors
TWI_ErrStatus MTWI_SendStartCondition() {
    TWI_ErrStatus Local_ErrorState = NoError;

    // Send Start Condition
    SET_BIT(TWCR, 5);

    // Clear The Interrupt Flag to start the previous operation
    SET_BIT(TWCR, 7);

    // Wait until the interrupt flag is fired and the previous operation is complete
    while (GET_BIT(TWCR, 7) == 0);

    if ((TWSR & 0xF8) != 0x08) {
        Local_ErrorState = StartConditionErr;
    }

    return Local_ErrorState;
}

// Function to send the slave address with write operation and check for errors
TWI_ErrStatus MTWI_SendSlaveAdderssWithWrite(u8 A_u8SalveAddress) {
    TWI_ErrStatus Local_ErrorState = NoError;

    // Set slave address in MSB in Data Reg
    TWDR = (A_u8SalveAddress << 1);

    // Clear bit for write operation
    CLR_BIT(TWDR, 0);

    // Clear The Interrupt Flag to start the previous operation
    TWCR = (1 << 7) | (1 << 2);

    // Wait until the interrupt flag is fired and the previous operation is complete
    while (GET_BIT(TWCR, 7) == 0);

    if ((TWSR & 0xF8) != 0x18) {
        Local_ErrorState = SlaveAdderssWithWriteErr;
    }

    return Local_ErrorState;
}

// Function to send the slave address with read operation and check for errors
TWI_ErrStatus MTWI_SendSlaveAdderssWithRead(u8 A_u8SalveAddress) {
    TWI_ErrStatus Local_ErrorState = NoError;

    // Set slave address in MSB in Data Reg and set the read bit (LSB) to 1 for a read operation
    TWDR = (A_u8SalveAddress << 1) | 0x01;

    // Clear The Interrupt Flag to start the previous operation
    TWCR = (1 << 7) | (1 << 2);

    // Wait until the interrupt flag is fired and the previous operation is complete
    while (GET_BIT(TWCR, 7) == 0);

    if ((TWSR & 0xF8) != 0x40) {
        Local_ErrorState = SlaveAdderssWithReadErr;
    }

    return Local_ErrorState;
}

// Function to read a byte of data during an I2C communication
TWI_ErrStatus MTWI_MasterReadDataByte(uint8_t *A_pu8RecievedData, u8 A_u8AckState) {
    TWI_ErrStatus Local_ErrorState = NoError;

    if (A_pu8RecievedData == NULL) {
        return NULLPointerErr; // Check for a NULL pointer
    }

    // Set Ack Bit if A_u8AckState is 1, otherwise clear it
    if (A_u8AckState == 1) {
        SET_BIT(TWCR, 6);
    } else {
        CLR_BIT(TWCR, 6);
    }

    // Clear The Interrupt Flag to start the previous operation
    SET_BIT(TWCR, 7);

    // Wait until the interrupt flag is fired and the previous operation is complete
    while (GET_BIT(TWCR, 7) == 0);

    if ((TWSR & 0xF8) != ((A_u8AckState == 1) ? 0x50 : 0x58)) {
        Local_ErrorState = MasterReadDataErr;
    } else {
        *A_pu8RecievedData = TWDR;
    }

    return Local_ErrorState;
}

// Function to write a byte of data during an I2C communication
TWI_ErrStatus MTWI_MasterWriteDataByte(u8 A_u8Data) {
    TWI_ErrStatus Local_ErrorState = NoError;

    // Write Data on Data reg
    TWDR = A_u8Data;

    // Clear The Interrupt Flag to start the previous operation
    SET_BIT(TWCR, 7);

    // Wait until the interrupt flag is fired and the previous operation is complete
    while (GET_BIT(TWCR, 7) == 0);

    if ((TWSR & 0xF8) != 0x28) {
        Local_ErrorState = MasterWriteDataErr;
    }

    return Local_ErrorState;
}

// Function to perform slave reading during an I2C communication
TWI_ErrStatus MTWI_SLaveReading(u8 *A_pu8RecievedData) {
    TWI_ErrStatus Local_ErrorState = NoError;

    // Set Ack Bit
    SET_BIT(TWCR, 6);

    // Clear The Interrupt Flag to start the previous operation
    SET_BIT(TWCR, 7);

    // Wait until the interrupt flag is fired and the previous operation is complete
    while (GET_BIT(TWCR, 7) == 0);

    if ((TWSR & 0xF8) != 0x60) {
        Local_ErrorState = SlaveAdderessRecievedErr;
    }

    // Set Ack Bit
    SET_BIT(TWCR, 6);

    // Clear The Interrupt Flag to start the previous operation
    SET_BIT(TWCR, 7);

    // Wait until the interrupt flag is fired and the previous operation is complete
    while (GET_BIT(TWCR, 7) == 0);

    if ((TWSR & 0xF8) != 0x80) {
        Local_ErrorState = SlaveDataRecievedErr;
    } else {
        *A_pu8RecievedData = TWDR;
    }

    return Local_ErrorState;
}

// Function to send a stop condition on the I2C bus
void MTWI_voidSendStopCondition() {
    // Stop Condition on the bus
    SET_BIT(TWCR, 4);

    // Clear Interrupt Flag
    SET_BIT(TWCR, 7);
}
