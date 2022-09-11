#ifndef _TWI_H
#define _TWI_H

#include <stdint.h>

void initTwi();
void twiStart();
void twiStop();
void twiWrite(uint8_t data);
uint8_t twiReadAck();
uint8_t twiReadNack();

#endif

