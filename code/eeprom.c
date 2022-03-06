#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void eepromWrite(uint8_t address, uint8_t data) {
    cli();
    /* Wait for completion of previous write */
    while (EECR & (1 << EEPE));
    /* Set up address and Data Registers */
    EEAR = address;
    EEDR = data;
    /* Write logical one to EEMPE */
    EECR |= (1 << EEMPE);
    /* Start eeprom write by setting EEPE */
    EECR |= (1 << EEPE);
    sei();
}

uint8_t eepromRead(uint8_t address) {
    cli();
    /* Wait for completion of previous write */
    while (EECR & (1 << EEPE));
    /* Set up address register */
    EEAR = address;
    /* Start eeprom read by writing EERE */
    EECR |= (1 << EERE);
    /* Return data from Data Register */
    sei();
    return EEDR;
}

void eepromWrite16(uint8_t address, uint16_t data) {
    eepromWrite(address, data >> 8);
    eepromWrite(address + 1, data & 0xFF);
}

uint16_t eepromRead16(uint16_t address) {
    return (eepromRead(address) << 8) + eepromRead(address + 1);
}

