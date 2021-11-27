#include <avr/io.h>
#include <util/delay.h>

#include "neopixel.h"

#define INDICATOR_DDR DDRD
#define INDICATOR_PIN PIND
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
        long pixels[] = {oilPixel, turnSignalPixel, highBeamPixel, neutralPixel};
        sendPixels(pixels, 4);
    }

    return 0;
}
