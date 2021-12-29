#include <avr/io.h>
#include <util/delay.h>
#include <malloc.h>

#include "lcd.h"

#define LCD_PORT PORTB
#define LCD_DDR DDRB
#define CS_PIN 0b00100000
#define WR_PIN 0b00010000
#define DATA_PIN 0b00001000

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

const int font[96] = {
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

const char addressMapping[8][4] = {
    { 1,31,30, 0},
    { 3,29,27, 2},
    { 5,28,26, 4},
    { 7,25,24, 6},
    { 9,23,22, 8},
    {11,21,20,10},
    {13,19,18,12},
    {15,17,16,14},
};

void writeAscii(char ascii, unsigned char digit);
void writeCommand(char command);
void writeData(char address, char data);
void writeBits(char bits, char numberOfBits);
void writeBit(char bit);

void initLcd() {
    LCD_DDR |= CS_PIN;
    LCD_DDR |= WR_PIN;
    LCD_DDR |= DATA_PIN;

    writeCommand(BIAS);
	writeCommand(RC_256K);
	writeCommand(SYS_DIS);
	writeCommand(WDT_DIS);
    writeCommand(SYS_EN);
    writeCommand(LCD_ON);
}

void writeString(char* string) {
    for (int i = 0; i < 8; i++) {
        writeAscii(string[i], i);
    }
}

void writeInteger(int integer) {
    for (int i = 0; i < 8; i++) {
        char ascii = (int) integer % 10 + 48;
        writeAscii(ascii, 7 - i);
        integer /= 10;
    }
}

void writeAscii(char ascii, unsigned char digit) {
    unsigned char code = ascii - 32;
    writeData(addressMapping[digit][0], (font[code] >> 12) & 0b1111);
    writeData(addressMapping[digit][1], (font[code] >> 8) & 0b1111);
    writeData(addressMapping[digit][2], (font[code] >> 4) & 0b1111);
    writeData(addressMapping[digit][3], font[code] & 0b1111);
}

void writeCommand(char command) {
    LCD_PORT &= ~CS_PIN;
    writeBits(COMMAND_MODE, 3);
    writeBits(command, 8);
    writeBit(0);
    LCD_PORT |= CS_PIN;
}

void writeData(char address, char data) {
    LCD_PORT &= ~CS_PIN;
    writeBits(DATA_MODE, 3);
    writeBits(address, 6);
    writeBits(data, 4);
    LCD_PORT |= CS_PIN;
}

void writeBits(char bits, char numberOfBits) {
    for (int i = numberOfBits - 1; i >= 0; i--) {
        writeBit(bits & (1 << i));
    }
}

void writeBit(char bit) {
    LCD_PORT &= ~WR_PIN;
    _delay_us(T_CLK);
    if (bit) {
        LCD_PORT |= DATA_PIN;
    } else {
        LCD_PORT &= ~DATA_PIN;
    }
    LCD_PORT |= WR_PIN;
    _delay_us(T_CLK);
}

