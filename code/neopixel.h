#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#define OFF 0x000000
#define WHITE 0xAAAAAA
#define RED 0xAA0000
#define GREEN 0x00AA00
#define BLUE 0x0000AA
#define YELLOW 0xAA4400

void pixelSetup();
void sendPixels(long pixels[], int size);

#endif
