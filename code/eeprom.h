#ifndef _EEPROM_H
#define _EEPROM_H

#include <stdint.h>

void eepromWrite(uint8_t address, uint8_t data);
uint8_t eepromRead(uint8_t address);

void eepromWrite16(uint8_t address, uint16_t data);
uint16_t eepromRead16(uint8_t address);

void eepromWrite32(uint8_t address, uint32_t data);
uint32_t eepromRead32(uint8_t address);

#endif

