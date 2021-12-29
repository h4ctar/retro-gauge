#ifndef _LCD_H
#define _LCD_H

#include <stdint.h>

void initLcd();

void writeString(char* string);
void writeInteger(int integer);

#endif

