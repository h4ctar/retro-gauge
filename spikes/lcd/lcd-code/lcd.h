#ifndef _LCD_H
#define _LCD_H

#include <stdint.h>

typedef struct Lcd {
    volatile uint8_t* port;
    volatile uint8_t* ddr;
    char csPin;
    char wrPin;
    char dataPin;
} Lcd;

void initLcd(Lcd* lcd);

void writeString(Lcd* lcd, char* string);
void writeInteger(Lcd* lcd, int integer);

#endif

