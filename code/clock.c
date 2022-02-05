#include "clock.h"

#include "lcd.h"
#include "rtc.h"
#include <stdint.h>

Time time;

void updateClock() {
    readTime(&time);
}

void displayClock() {
    char timeString[] = "  :  :  ";
    timeString[0] = time.hour / 10 + '0';
    timeString[1] = time.hour % 10 + '0';
    timeString[3] = time.minute / 10 + '0';
    timeString[4] = time.minute % 10 + '0';
    timeString[6] = time.second / 10 + '0';
    timeString[7] = time.second % 10 + '0';
    lcdDisplayString(timeString);
}

