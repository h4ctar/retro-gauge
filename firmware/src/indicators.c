#include "indicators.h"

#include <avr/io.h>

#include "led.h"

#define INDICATOR_PIN       PIND
#define INDICATOR_DDR       DDRD
#define OIL_MASK            (1 << PD3)
#define TURN_SIGNAL_MASK    (1 << PD5)
#define HIGH_BEAM_MASK      (1 << PD4)
#define NEUTRAL_MASK        (1 << PD6)

#define OFF_COLOR           0x000000
#define LCD_BACKLIGHT_COLOR 0x111111
#define ALARM_COLOR         0xAA0000
#define NEUTRAL_COLOR       0x00AA00
#define HIGH_BEAM_COLOR     0x0000AA
#define TURN_SIGNAL_COLOR   0xAA4400

void initIndicators() {
    // Make the indicator pins inputs
    INDICATOR_DDR &= ~(OIL_MASK | TURN_SIGNAL_MASK | HIGH_BEAM_MASK | NEUTRAL_MASK);

    // Turn on all the LEDS
    long ledColors[] = {TURN_SIGNAL_COLOR, HIGH_BEAM_COLOR, LCD_BACKLIGHT_COLOR, LCD_BACKLIGHT_COLOR, NEUTRAL_COLOR, ALARM_COLOR};
    writeLeds(ledColors, 6);
}

void updateIndicators() {
    long oilLedColor = INDICATOR_PIN & OIL_MASK ? OFF_COLOR : ALARM_COLOR;
    long turnSignalLedColor = INDICATOR_PIN & TURN_SIGNAL_MASK ? OFF_COLOR : TURN_SIGNAL_COLOR;
    long highBeamLedColor = INDICATOR_PIN & HIGH_BEAM_MASK ? OFF_COLOR : HIGH_BEAM_COLOR;
    long neutralLedColor = INDICATOR_PIN & NEUTRAL_MASK ? OFF_COLOR : NEUTRAL_COLOR;
    long ledColors[] = {turnSignalLedColor, highBeamLedColor, LCD_BACKLIGHT_COLOR, LCD_BACKLIGHT_COLOR, neutralLedColor, oilLedColor};
    writeLeds(ledColors, 6);
}
