#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Function to write a byte of data to EEPROM at a specific address
void EEPROM_write(uint16_t address, uint8_t data) {
    // Wait for completion of previous write
    while (GET_BIT(EECR, EEWE));

    // Set up address register
    EEAR = address;

    // Write data to data register
    EEDR = data;

    // Start EEPROM write by setting EEWE
    SET_BIT(EECR, EEMWE);
    SET_BIT(EECR, EEWE);
}

// Function to read a byte of data from EEPROM at a specific address
uint8_t EEPROM_read(uint16_t address) {
    // Wait for completion of previous write
    while (GET_BIT(EECR, EEWE));

    // Set up address register
    EEAR = address;

    // Start EEPROM read by setting EERE
    SET_BIT(EECR, EERE);

    // Return data from data register
    return EEDR;
}
