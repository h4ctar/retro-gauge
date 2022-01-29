#include "indicators.h"

#include <avr/io.h>

#include "led.h"

#define INDICATOR_PORT  PORTD
#define INDICATOR_DDR   DDRD
#define OIL_PIN         0b00001000
#define TURN_SIGNAL_PIN 0b00100000
#define HIGH_BEAM_PIN   0b00010000
#define NEUTRAL_PIN     0b01000000

void initIndicators() {
    // Make the indicator pins inputs
    INDICATOR_DDR &= ~(OIL_PIN | TURN_SIGNAL_PIN | HIGH_BEAM_PIN | NEUTRAL_PIN);

    // Turn on all the LEDS
    long ledColors[] = {YELLOW, BLUE, WHITE, WHITE, GREEN, RED};
    writeLeds(ledColors, 6);
}

void updateIndicators() {
    long oilLedColor = PIND & OIL_PIN ? OFF : RED;
    long turnSignalLedColor = PIND & TURN_SIGNAL_PIN ? OFF : YELLOW;
    long highBeamLedColor = PIND & HIGH_BEAM_PIN ? OFF : BLUE;
    long neutralLedColor = PIND & NEUTRAL_PIN ? OFF : GREEN;
    long ledColors[] = {turnSignalLedColor, highBeamLedColor, WHITE, WHITE, neutralLedColor, oilLedColor};
    writeLeds(ledColors, 6);
}

