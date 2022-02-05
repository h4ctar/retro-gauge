#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>
#include <stdint.h>
#include <stdio.h>

#include "button.h"
#include "twi.h"
#include "rtc.h"
#include "analog.h"
#include "timer.h"
#include "led.h"
#include "lcd.h"
#include "motor.h"

#include "mode.h"

#include "speedo.h"
#include "indicators.h"
#include "battery.h"

Mode init();
void update(Mode* mode);

int main() {
    Mode mode = init();

    while (1) {
        update(&mode);
    }

    return 0;
}

Mode init() {
    sei();

    initTwi();
    initTimer();
    initAnalog();
    initLed();
    initLcd();
    initMotor();
    initButton();

    initIndicators();
    initSpeedo();

    return BATTERY;
}

void update(Mode* mode) {
    updateButton();
    updateMotor();

    updateIndicators();

    updateBatteryVoltage(*mode);
    updateSpeedo(*mode);

    if (consumeShortButtonPress() == BUTTON_DOWN) {
        *mode = (*mode + 1) % NUMBER_OF_MODES;
    }
}

