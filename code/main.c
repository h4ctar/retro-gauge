#include <avr/io.h>
#include <util/delay.h>

#include "neopixel.h"

#define OIL_BIT 0b00001000
#define TURN_SIGNAL_BIT 0b01000000
#define HIGH_BEAM_BIT 0b00010000
#define NEUTRAL_BIT 0b10000000

int main()
{
    // Make the indicator pins inputs
    DDRD &= ~(OIL_BIT | TURN_SIGNAL_BIT | HIGH_BEAM_BIT | NEUTRAL_BIT);

    pixelSetup();

    while (1)
    {
        long oilPixel = PIND & OIL_BIT ? OFF : RED;
        long turnSignalPixel = PIND & TURN_SIGNAL_BIT ? OFF : YELLOW;
        long highBeamPixel = PIND & HIGH_BEAM_BIT ? OFF : BLUE;
        long neutralPixel = PIND & NEUTRAL_BIT ? OFF : GREEN;
        long pixels[] = {turnSignalPixel, highBeamPixel, WHITE, WHITE, neutralPixel, oilPixel};
        sendPixels(pixels, 6);
    }

    return 0;
}

