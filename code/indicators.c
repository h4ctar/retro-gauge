#include "indicators.h"

#include <avr/io.h>

#include "led.h"

#define INDICATOR_PIN       PIND
#define INDICATOR_DDR       DDRD
#define OIL_MASK            (1 << PD3)
#define TURN_SIGNAL_MASK    (1 << PD5)
#define HIGH_BEAM_MASK      (1 << PD4)
#define NEUTRAL_MASK        (1 << PD6)

void initIndicators() {
    // Make the indicator pins inputs
    INDICATOR_DDR &= ~(OIL_MASK | TURN_SIGNAL_MASK | HIGH_BEAM_MASK | NEUTRAL_MASK);

    // Turn on all the LEDS
    long ledColors[] = {YELLOW, BLUE, WHITE, WHITE, GREEN, RED};
    writeLeds(ledColors, 6);
}

void updateIndicators() {
    long oilLedColor = INDICATOR_PIN & OIL_MASK ? OFF : RED;
    long turnSignalLedColor = OFF; // INDICATOR_PIN & TURN_SIGNAL_MASK ? OFF : YELLOW;
    long highBeamLedColor = OFF; // INDICATOR_PIN & HIGH_BEAM_MASK ? OFF : BLUE;
    long neutralLedColor = INDICATOR_PIN & NEUTRAL_MASK ? OFF : GREEN;
    long ledColors[] = {turnSignalLedColor, highBeamLedColor, OFF, OFF, neutralLedColor, oilLedColor};
    writeLeds(ledColors, 6);
}

