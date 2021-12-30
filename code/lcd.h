#ifndef _LCD_H
#define _LCD_H

#include <stdint.h>

void initLcd();

void writeString(uint8_t* string);
void writeInteger(uint64_t value);
void writeFloat(float value, uint8_t decimalPlaces);

#endif

