#ifndef _LED_H
#define _LED_H

#include <stdint.h>

#define OFF 0x000000
#define WHITE 0x222222
#define RED 0xAA0000
#define GREEN 0x00AA00
#define BLUE 0x0000AA
#define YELLOW 0xAA4400

void initLed();

void writeLeds(long ledColors[], int size);

#endif

