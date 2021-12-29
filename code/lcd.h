#ifndef _LCD_H
#define _LCD_H

#include <stdint.h>

void initLcd();

void writeString(char* string);
void writeInteger(uint64_t integer);

#endif

