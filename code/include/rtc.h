#ifndef _RTC_H
#define _RTC_H

#include <stdint.h>

typedef struct {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} Time;

void readTime(Time* time);
void setTime(Time time);

#endif

