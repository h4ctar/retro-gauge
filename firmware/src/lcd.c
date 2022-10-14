#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include <malloc.h>

#include "lcd.h"

#define LCD_PORT    PORTB
#define LCD_DDR     DDRB
#define CS_MASK     (1 << PB5)
#define WR_MASK     (1 << PB4)
#define DATA_MASK   (1 << PB3)

#define T_CLK 5 // the clock time in micro seconds

// Modes
#define COMMAND_MODE    0b0100  // 1 0 0
#define DATA_MODE       0b0101  // 1 0 1

// Commands
#define BIAS    0b00101001  // 0010-10X1-X - 1/3 BIAS, 4 commons
#define RC_256K 0b00011000  // 0001-10XX-X - System clock source, on-chip RC oscillator
#define WDT_DIS 0b00000101  // 0000-0101-X - Disable WDT time-out flag output
#define WDT_EN  0b00000111
#define SYS_DIS 0b00000000
#define SYS_EN  0b000000001 // 0000-0001-X - Turn on system oscillator
#define LCD_ON  0b000000011 // 0000-0011-X - Turn on LCD bias generator
#define LCD_OFF 0b000000010 // 0000-0010-X - Turn off LCD bias generator

const uint16_t font[96] = {
    0b0000000000000000,
    0b0110000000000000,
    0b0010000000010000,
    0b0110100001011010,
    0b0101101001011010,
    0b0100001011111111,
    0b0001110010010011,
    0b0000000000010000,
    0b0000000010100000,
    0b0000000000000101,
    0b0000000011111111,
    0b0000000001011010,
    0b0000000000000100,
    0b0000000001000010,
    0b0000000000000000,
    0b0000000000100100,
    0b0111111000100100,
    0b0110000000100000,
    0b0011110001000010,
    0b0111100001000000,
    0b0110001001000010,
    0b0001101010000010,
    0b0101111001000010,
    0b0111000000000000,
    0b0111111001000010,
    0b0111101001000010,
    0b0000000000011000,
    0b0000000000010100,
    0b0000000010100010,
    0b0000100001000010,
    0b0000000001000101,
    0b0011000001001000,
    0b0011111001010000,
    0b0111011001000010,
    0b0111100001011000,
    0b0001111000000000,
    0b0111100000011000,
    0b0001111000000010,
    0b0001011000000010,
    0b0101111001000000,
    0b0110011001000010,
    0b0001100000011000,
    0b0110110000000000,
    0b0000011010100010,
    0b0000111000000000,
    0b0110011000100001,
    0b0110011010000001,
    0b0111111000000000,
    0b0011011001000010,
    0b0111111010000000,
    0b0011011011000010,
    0b0101101001000010,
    0b0001000000011000,
    0b0110111000000000,
    0b0000011000100100,
    0b0110011010000100,
    0b0000000010100101,
    0b0110101001000010,
    0b0001100000100100,
    0b0001111000000000,
    0b0000000010000001,
    0b0111100000000000,
    0b0000000010000100,
    0b0000100000000000,
    0b0000000000000001,
    0b0000110000001010,
    0b0000111010000010,
    0b0000110001000010,
    0b0110100001000100,
    0b0000110000000110,
    0b0000000001101010,
    0b0110100001100000,
    0b0000011000001010,
    0b0000000000001000,
    0b0000010000010100,
    0b0000000010111000,
    0b0000011000000000,
    0b0100010001001010,
    0b0000010000001010,
    0b0100110001000010,
    0b0000011000000011,
    0b0110000001100000,
    0b0000010000000010,
    0b0000100011000000,
    0b0000111000000010,
    0b0100110000000000,
    0b0000010000000100,
    0b0100010010000100,
    0b0000000010100101,
    0b0110100001010000,
    0b0000100000000110,
    0b0001100000000111,
    0b0000000000011000,
    0b0001100011100000,
    0b0000000001100110,
    0b0000000000000000,
};

const uint8_t addressMapping[8][4] = {
    { 1,31,30, 0},
    { 3,29,27, 2},
    { 5,28,26, 4},
    { 7,25,24, 6},
    { 9,23,22, 8},
    {11,21,20,10},
    {13,19,18,12},
    {15,17,16,14},
};

uint8_t lcdBuffer[32];

void writeAscii(uint8_t ascii, uint8_t dp, uint8_t digit);
void writeCommand(uint8_t command);
void writeData(uint8_t address, uint8_t data);
void writeBits(uint8_t bits, uint8_t numberOfBits);
void writeBit(uint8_t bit);

void initLcd() {
    LCD_DDR |= CS_MASK;
    LCD_DDR |= WR_MASK;
    LCD_DDR |= DATA_MASK;

    writeCommand(BIAS);
	writeCommand(RC_256K);
	writeCommand(SYS_DIS);
	writeCommand(WDT_DIS);
    writeCommand(SYS_EN);
    writeCommand(LCD_ON);

    for (uint8_t i = 0; i < 32; i++) {
        writeData(i, 0x0F);
        writeData(i, 0x00);
    }
}

void lcdDisplayString(char* string) {
    // TODO: length check
    for (uint8_t i = 0; i < 8; i++) {
        writeAscii(string[i], 0, i);
    }
}

void lcdDisplayInteger(uint32_t value, char* units) {
    // Loop through the characters of the units string
    uint8_t unitsLength = strlen(units);
    uint8_t offset = 8 - unitsLength;
    for (uint8_t i = 0; i < unitsLength; i++) {
        writeAscii(units[i], 0, offset + i);
    }

    // Loop through the remaining digits of the LCD starting from the right
    offset -= 1;
    for (uint8_t i = 0; i < 8 - unitsLength; i++) {
        if (value >= 1 || i == 0) {
            uint8_t ascii = value % 10 + 48;
            writeAscii(ascii, 0, offset - i);
            value /= 10;
        } else {
            writeAscii(0x00, 0, offset - i);
        }
    }
}

void lcdDisplayFloat(float value, uint8_t decimalPlaces, char* units) {
    // Loop through the characters of the units string
    uint8_t unitsLength = strlen(units);
    uint8_t offset = 8 - unitsLength;
    for (uint8_t i = 0; i < unitsLength; i++) {
        writeAscii(units[i], 0, offset + i);
    }

    // Display the digits on the right side of the decimal place
    offset -= decimalPlaces;
    float decimal = value;
    for (uint8_t i = 0; i < decimalPlaces; i++) {
        decimal *= 10;
        uint8_t ascii = (int) decimal % 10 + 48;
        writeAscii(ascii, 0, offset + i);
    }

    // Display the digits on the left side of the decimal place
    offset -= 1;
    for (uint8_t i = 0; i < 8 - unitsLength - decimalPlaces; i++) {
        uint8_t dp = i == 0;
        if (value > 1 || i == 0) {
            uint8_t ascii = (int) value % 10 + 48;
            writeAscii(ascii, dp, offset - i);
            value /= 10;
        } else {
            writeAscii(0x00, dp, offset - i);
        }
    }
}

void writeAscii(uint8_t ascii, uint8_t dp, uint8_t digit) {
    uint8_t code = ascii - 32;
    uint8_t dpCode = dp ? 0b1000 : 0b0000;
    writeData(addressMapping[digit][0], (font[code] >> 12 | dpCode) & 0b1111);
    writeData(addressMapping[digit][1], (font[code] >> 8) & 0b1111);
    writeData(addressMapping[digit][2], (font[code] >> 4) & 0b1111);
    writeData(addressMapping[digit][3], font[code] & 0b1111);
}

void writeCommand(uint8_t command) {
    LCD_PORT &= ~CS_MASK;
    writeBits(COMMAND_MODE, 3);
    writeBits(command, 8);
    writeBit(0);
    LCD_PORT |= CS_MASK;
}

void writeData(uint8_t address, uint8_t data) {
    if (lcdBuffer[address] != data) {
        LCD_PORT &= ~CS_MASK;
        writeBits(DATA_MODE, 3);
        writeBits(address, 6);
        writeBits(data, 4);
        LCD_PORT |= CS_MASK;
        
        lcdBuffer[address] = data;
    }
}

void writeBits(uint8_t bits, uint8_t numberOfBits) {
    for (int i = numberOfBits - 1; i >= 0; i--) {
        writeBit(bits & (1 << i));
    }
}

void writeBit(uint8_t bit) {
    LCD_PORT &= ~WR_MASK;
    _delay_us(T_CLK);
    if (bit) {
        LCD_PORT |= DATA_MASK;
    } else {
        LCD_PORT &= ~DATA_MASK;
    }
    LCD_PORT |= WR_MASK;
    _delay_us(T_CLK);
}

