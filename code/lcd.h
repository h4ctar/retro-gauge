#ifndef _LCD_H
#define _LCD_H

#include <stdint.h>

void initLcd();

void lcdDisplayString(char* string);
void lcdDisplayInteger(uint32_t value, char* units);
void lcdDisplayFloat(float value, uint8_t decimalPlaces, char* units);

#endif

