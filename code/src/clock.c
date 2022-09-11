#include "clock.h"

#include <stdint.h>

#include "button.h"
#include "lcd.h"
#include "rtc.h"
#include "mode.h"
#include "timer.h"

typedef enum {
    NORMAL,
    SET_HOUR,
    SET_MINUTE,
    SET_SECOND,
    NUMBER_OF_SUBMODES,
} SubMode;

Time time;
SubMode subMode = NORMAL;

void updateClock(Mode mode) {
    readTime(&time);

    if (mode == CLOCK) {
        if (consumeLongButtonPress() == BUTTON_DOWN) {
            subMode = (subMode + 1) % NUMBER_OF_SUBMODES;
        } else if (subMode != NORMAL && consumeShortButtonPress() == BUTTON_DOWN) {
            switch (subMode) {
                case SET_HOUR:
                    time.hour = (time.hour + 1) % 24;
                    setTime(time);
                    break;

                case SET_MINUTE:
                    time.minute = (time.minute + 1) % 60;
                    setTime(time);
                    break;

                case SET_SECOND:
                    time.second = 0;
                    setTime(time);
                    break;

                default:
                    break;
            }
        }
    } else {
        subMode = NORMAL;
    }
}

void displayClock() {
    uint8_t flash = millis() / 500 % 2;
    
    char timeString[] = "        ";
    if (flash) {
        timeString[2] = ':';
        timeString[5] = ':';
    }

    if (subMode != SET_HOUR || flash) {
        timeString[0] = time.hour / 10 + '0';
        timeString[1] = time.hour % 10 + '0';
    }
    if (subMode != SET_MINUTE || flash) {
        timeString[3] = time.minute / 10 + '0';
        timeString[4] = time.minute % 10 + '0';
    }
    if (subMode != SET_SECOND || flash) {
        timeString[6] = time.second / 10 + '0';
        timeString[7] = time.second % 10 + '0';
    }
    lcdDisplayString(timeString);
}

