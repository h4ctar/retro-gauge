#include "rtc.h"

#include "twi.h"
#include <stdint.h>

#define RTC_READ_ADDRESS 0xA3
#define RTC_WRITE_ADDRESS 0xA2
#define TIME_REG 2

uint8_t bcdToDec(uint8_t b);
uint8_t decToBcd(uint8_t d);

void readTime(Time* time) {
    // Send start
    twiStart();
    // Select device and send write bit
    twiWrite(RTC_WRITE_ADDRESS);
    // Select the time register
    twiWrite(TIME_REG);

    // Send repeated start
    twiStart();
    // Select device and send read bit
    twiWrite(RTC_READ_ADDRESS);

    time->second = bcdToDec(twiReadAck() & 0x7f);
    time->minute = bcdToDec(twiReadAck() & 0x7f);
    time->hour = bcdToDec(twiReadNack() & 0x3f);

    twiStop();
}

void setTime(Time time) {
    // Send start
    twiStart();
    // Select device and send write bit
    twiWrite(RTC_WRITE_ADDRESS);
    // Select the time register
    twiWrite(TIME_REG);

    twiWrite(decToBcd(time.second));
    twiWrite(decToBcd(time.minute));
    twiWrite(decToBcd(time.hour));

    twiStop();
}

uint8_t bcdToDec(uint8_t b) {
    return (b / 16 * 10) + (b % 16);
}

uint8_t decToBcd(uint8_t d) {
    return (d / 10 * 16) + (d % 10);
}

