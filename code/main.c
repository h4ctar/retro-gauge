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

Mode mode = BATTERY;
uint32_t modeSwitchTime;

void init();
void update();
void display();

int main() {
    init();

    while (1) {
        update();
        display();
    }

    return 0;
}

void init() {
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
}

void update() {
    updateButton();
    updateMotor();

    updateIndicators();

    updateBatteryVoltage();
    updateSpeedo();

    if (consumeShortButtonPress() == BUTTON_DOWN) {
        mode = (mode + 1) % NUMBER_OF_MODES;
        modeSwitchTime = millis();
    }
}

void display() {
    if (millis() - modeSwitchTime < 1000) {
        switch (mode) {
            case BATTERY:
                lcdDisplayString("Battery ");
                break;
            case SPEED:
                lcdDisplayString("Speed   ");
                break;
            case ODO:
                lcdDisplayString("Odo     ");
                break;
            case TRIP:
                lcdDisplayString("Trip    ");
                break;
            default:
                break;
        }
    } else {
        switch (mode) {
            case BATTERY:
                displayBattery();
                break;
            case SPEED:
                displaySpeed();
                break;
            case ODO:
                displayOdo();
                break;
            case TRIP:
                displayTrip();
                break;
            default:
                break;
        }
    }
}

