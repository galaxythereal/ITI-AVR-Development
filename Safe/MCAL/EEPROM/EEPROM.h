
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#ifndef EEPROM_DRIVER_H
#define EEPROM_DRIVER_H

#include "../I2C/I2C_Interface.h"

uint8_t EEPROM_read(uint16_t address);
void EEPROM_write(uint16_t address, uint8_t data);

#endif /* EEPROM_DRIVER_H */
