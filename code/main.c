#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>

#include "led.h"
#include "lcd.h"

#define INDICATOR_PORT  PORTD
#define INDICATOR_DDR   DDRD
#define OIL_PIN         0b00001000
#define TURN_SIGNAL_PIN 0b01000000
#define HIGH_BEAM_PIN   0b00010000
#define NEUTRAL_PIN     0b10000000

int main() {
    // connect led to pin PC0
    DDRC |= (1 << 0);
  
    initLed();
    initLcd();

    // Make the indicator pins inputs
    DDRD &= ~(OIL_PIN | TURN_SIGNAL_PIN | HIGH_BEAM_PIN | NEUTRAL_PIN);

    int count = 0;
    while (1) {
        long oilLedColor = PIND & OIL_PIN ? OFF : RED;
        long turnSignalLedColor = PIND & TURN_SIGNAL_PIN ? OFF : YELLOW;
        long highBeamLedColor = PIND & HIGH_BEAM_PIN ? OFF : BLUE;
        long neutralLedColor = PIND & NEUTRAL_PIN ? OFF : GREEN;
        long ledColors[] = {turnSignalLedColor, highBeamLedColor, WHITE, WHITE, neutralLedColor, oilLedColor};
        writeLeds(ledColors, 6);
        writeInteger(count++);
    }

    return 0;
}

