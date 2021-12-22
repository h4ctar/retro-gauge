#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <avr/io.h>

#include <util/delay.h>


#include "font.h"

#define LCD_PORT PORTB
#define LCD_PORT_DDR DDRB
#define CS_PIN 0b00100000
#define WR_PIN 0b00010000
#define DATA_PIN 0b00001000

#define T_CLK 5 // the clock time in micro seconds

// Modes
#define COMMAND_MODE 0b0100 // 1 0 0
#define DATA_MODE 0b0101    // 1 0 1

// Commands
#define BIAS 0b00101001 // 0010-10X1-X - 1/3 BIAS, 4 commons
#define SYS_DIS 0b00000000
#define RC_256K 0b00011000 // 0001-10XX-X - System clock source, on-chip RC oscillator
#define WDT_DIS 0b00000101 // 0000-0101-X - Disable WDT time-out flag output
#define WDT_EN 0b00000111
#define SYS_EN 0b000000001  // 0000-0001-X - Turn on system oscillator
#define LCD_ON 0b000000011  // 0000-0011-X - Turn on LCD bias generator
#define LCD_OFF 0b000000010 // 0000-0010-X - Turn off LCD bias generator

void writeCommand(unsigned char command);
void writeData(unsigned char address, unsigned char data);
void writeBits(unsigned char bits, unsigned char numberOfBits);
void writeBit(unsigned char bit);

const unsigned char addressMapping[8][4] = {
    { 1,31,30, 0},
    { 3,29,27, 2},
    { 5,28,26, 4},
    { 7,25,24, 6},
    { 9,23,22, 8},
    {11,21,20,10},
    {13,19,18,12},
    {15,17,16,14},
};

void writeAscii(char ascii, unsigned char digit) {
    int code = ascii - 32;
    writeData(addressMapping[digit][0], (font[code] >> 12) & 0b1111);
    writeData(addressMapping[digit][1], (font[code] >> 8) & 0b1111);
    writeData(addressMapping[digit][2], (font[code] >> 4) & 0b1111);
    writeData(addressMapping[digit][3], font[code] & 0b1111);
}

void writeString(char* string) {
    for (int i = 0; i < 8; i++) {
        writeAscii(string[i], i);
    }
}

int main() {
    LCD_PORT_DDR |= CS_PIN;
    LCD_PORT_DDR |= WR_PIN;
    LCD_PORT_DDR |= DATA_PIN;

    writeCommand(BIAS);
	writeCommand(RC_256K);
	writeCommand(SYS_DIS);
	writeCommand(WDT_DIS);
    writeCommand(SYS_EN);
    writeCommand(LCD_ON);

    int count = 0;

    while (1) {
        char str[8];
        sprintf(str, "%d", count++);
        writeString(str);
        _delay_us(1000000);
    }

    return 0;
}

void writeCommand(unsigned char command) {
    LCD_PORT &= ~CS_PIN;
    writeBits(COMMAND_MODE, 3);
    writeBits(command, 8);
    writeBit(0);
    LCD_PORT |= CS_PIN;
}

void writeData(unsigned char address, unsigned char data) {
    LCD_PORT &= ~CS_PIN;
    writeBits(DATA_MODE, 3);
    writeBits(address, 6);
    writeBits(data, 4);
    LCD_PORT |= CS_PIN;
}

void writeBits(unsigned char bits, unsigned char numberOfBits) {
    for (int i = numberOfBits - 1; i >= 0; i--) {
        writeBit(bits & (1 << i));
    }
}

void writeBit(unsigned char bit) {
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

