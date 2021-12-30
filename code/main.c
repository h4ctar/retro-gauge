#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <util/atomic.h>
#include <stdio.h>

#include "analog.h"
#include "led.h"
#include "lcd.h"
#include "motor.h"
#include "timer.h"

#define INDICATOR_PORT  PORTD
#define INDICATOR_DDR   DDRD
#define OIL_PIN         0b00001000
#define TURN_SIGNAL_PIN 0b01000000
#define HIGH_BEAM_PIN   0b00010000
#define NEUTRAL_PIN     0b10000000

int main() {
    sei();

    initTimer();
    initAnalog();
    initLed();
    initLcd();
    initMotor();

    setMotorPosition(60 * 12);
    waitForMotor();
    setMotorPosition(0);
    waitForMotor();

    // Make the indicator pins inputs
    DDRD &= ~(OIL_PIN | TURN_SIGNAL_PIN | HIGH_BEAM_PIN | NEUTRAL_PIN);

    float battVoltage = 0;

    while (1) {
        long oilLedColor = PIND & OIL_PIN ? OFF : RED;
        long turnSignalLedColor = PIND & TURN_SIGNAL_PIN ? OFF : YELLOW;
        long highBeamLedColor = PIND & HIGH_BEAM_PIN ? OFF : BLUE;
        long neutralLedColor = PIND & NEUTRAL_PIN ? OFF : GREEN;
        long ledColors[] = {turnSignalLedColor, highBeamLedColor, WHITE, WHITE, neutralLedColor, oilLedColor};
        writeLeds(ledColors, 6);
    
        float pinVoltage = readAnalog(7) * 5 / 1024.f;
        battVoltage = battVoltage * 0.99 + 0.01 * (pinVoltage * 3.128 + 0.7);
        writeFloat(battVoltage, 2);

        updateMotor();
    }

    return 0;
}

