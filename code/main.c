#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>
#include <stdint.h>
#include <stdio.h>

#include "analog.h"
#include "timer.h"
#include "led.h"
#include "lcd.h"
#include "motor.h"

#include "speedo.h"
#include "indicators.h"
#include "battery.h"

enum mode {
    BATTERY,
    SPEED,
};

void init();
void update();

int main() {
    init();

    while (1) {
        update();
    }

    return 0;
}

void init() {
    sei();

    initTimer();
    initAnalog();
    initLed();
    initLcd();
    initMotor();

    initIndicators();
    initSpeedo();
}

void update() {
    updateBatteryVoltage();
    updateIndicators();
    updateMotor();
    updateSpeedo();
}

