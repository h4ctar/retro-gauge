#ifndef _TIMER_H
#define _TIMER_H

#include <stdint.h>

#define MILLISECONDS_PER_SECOND 1000.
#define MICROSECONDS_PER_SECOND (1000. * MILLISECONDS_PER_SECOND)

void initTimer();
uint32_t millis();
uint32_t micros();

#endif

