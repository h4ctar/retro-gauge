#include "eeprom.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void eepromWrite(uint8_t address, uint8_t data) {
    uint8_t old = eepromRead(address);
    if (old == data) {
        return;
    }

    /* Wait for completion of previous write */
    while (EECR & (1 << EEPE));
    /* Set up address and Data Registers */
    EEAR = address;
    EEDR = data;
    /* Write logical one to EEMPE */
    EECR |= (1 << EEMPE);
    /* Start eeprom write by setting EEPE */
    EECR |= (1 << EEPE);
}

uint8_t eepromRead(uint8_t address) {
    /* Wait for completion of previous write */
    while (EECR & (1 << EEPE));
    /* Set up address register */
    EEAR = address;
    /* Start eeprom read by writing EERE */
    EECR |= (1 << EERE);
    /* Return data from Data Register */
    return EEDR;
}

void eepromWrite16(uint8_t address, uint16_t data) {
    eepromWrite(address, data >> 8);
    eepromWrite(address + 1, data & 0xFF);
}

uint16_t eepromRead16(uint8_t address) {
    return (eepromRead(address) << 8) + eepromRead(address + 1);
}

void eepromWrite32(uint8_t address, uint32_t data) {
    eepromWrite(address, data >> 24);
    eepromWrite(address + 1, data >> 16 & 0xFF);
    eepromWrite(address + 2, data >> 8 & 0xFF);
    eepromWrite(address + 3, data & 0xFF);
}

uint32_t eepromRead32(uint8_t address) {
    return ((uint32_t) eepromRead(address) << 24) + (eepromRead(address + 1) << 15) + (eepromRead(address + 2) << 8) + eepromRead(address + 3);
}

