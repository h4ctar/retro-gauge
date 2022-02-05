#ifndef _BUTTON_H
#define _BUTTON_H

#include <avr/io.h>

#define BUTTON_UP 0
#define BUTTON_DOWN 1

void initButton();
void updateButton();
uint8_t consumeShortButtonPress();
uint8_t consumeLongButtonPress();

#endif

