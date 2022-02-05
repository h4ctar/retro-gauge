#include "rtc.h"

#include "twi.h"

#define RTC_ADDRESS 0x68
#define TIME_REG 0
#define TIME_SIZE 7

uint8_t bcdToDec(uint8_t b);

void readTime(Time* time) {
    // Send start
    twiStart();
    // Select device and send write bit
    twiWrite(RTC_ADDRESS << 1);
    // Select the time register
    twiWrite(TIME_REG);

    // Send repeated start
    twiStart();
    // Select device and send read bit
    twiWrite((RTC_ADDRESS << 1) | 1);

    time->second = bcdToDec(twiReadAck() & 0x7f);
    time->minute = bcdToDec(twiReadAck() & 0x7f);
    time->hour = bcdToDec(twiReadNack() & 0x7f);

    twiStop();

}

uint8_t bcdToDec(uint8_t b) {
    return (b >> 4) * 10 + (b % 16);
}

