#include "config.h"

#include <stdint.h>

#include "eeprom.h"

#define NEXT_ADDRESS 15

uint32_t readConfig32(uint8_t index) {
    uint8_t address = eepromRead(index);
    return eepromRead32(address);
}

void writeConfig32(uint8_t index, uint32_t data) {
    uint8_t address = eepromRead(index);
    eepromWrite32(address, data);
    uint32_t written = eepromRead32(address);
    if (written != data) {
        address = eepromRead(NEXT_ADDRESS);
        eepromWrite(NEXT_ADDRESS, address + 4);
        writeConfig32(index, data);
    }
}

