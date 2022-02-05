#include "rtc.h"

#include "twi.h"

#define RTC_READ_ADDRESS 0xA3
#define RTC_WRITE_ADDRESS 0xA2
#define TIME_REG 2

uint8_t bcdToDec(uint8_t b);

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

uint8_t bcdToDec(uint8_t b) {
    return (b >> 4) * 10 + (b % 16);
}

