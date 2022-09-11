#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdint.h>

#define ODO_INDEX   0
#define TRIP_INDEX  1

uint32_t readConfig32(uint8_t index);
void writeConfig32(uint8_t index, uint32_t data);

#endif

