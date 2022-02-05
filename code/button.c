#include "button.h"

#include "timer.h"
#include <avr/io.h>
#include <stdint.h>

#define BUTTON_PIN PIND
#define BUTTON_DDR DDRD
#define BUTTON_MASK 0b00000010

#define SHORT_PRESS_DURATION 1000

uint8_t lastState = BUTTON_UP;
uint8_t currentState;
uint32_t pressedTime = 0;
uint32_t releasedTime = 0;

uint8_t shortPress = 0;
uint8_t longPress = 0;

void initButton() {
    BUTTON_DDR &= ~BUTTON_MASK;
}

void updateButton() {
    currentState = (BUTTON_PIN & BUTTON_MASK) ? BUTTON_UP : BUTTON_DOWN;

    if (lastState == BUTTON_UP && currentState == BUTTON_DOWN) {
        pressedTime = millis();
    } else if (lastState == BUTTON_DOWN && currentState == BUTTON_UP) {
        releasedTime = millis();

        uint32_t pressDuration = releasedTime - pressedTime;

        if (pressDuration < SHORT_PRESS_DURATION) {
            shortPress = BUTTON_DOWN;
            longPress = BUTTON_UP;
        } else {
            shortPress = BUTTON_UP;
            longPress = BUTTON_DOWN;
        }
    }

    lastState = currentState;
}

uint8_t consumeShortButtonPress() {
    if (shortPress == BUTTON_DOWN) {
        shortPress = BUTTON_UP;
        return BUTTON_DOWN;
    } else {
        return BUTTON_UP;
    }
}

uint8_t consumeLongButtonPress() {
    if (longPress == BUTTON_DOWN) {
        longPress = BUTTON_UP;
        return BUTTON_DOWN;
    } else {
        return BUTTON_UP;
    }
}

