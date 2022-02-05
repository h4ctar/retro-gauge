// https://embedds.com/programming-avr-i2c-interface/

#include "twi.h"

#include <avr/io.h>
#include <stdint.h>

#define TWI_FREQ 100000L

#define TWI_PORT PORTC
#define SDA_MASK (1 << PC4)
#define SCL_MASK (1 << PC5)

void initTwi() {
    TWI_PORT |= SDA_MASK;
    TWI_PORT |= SCL_MASK;
    
    // Set SCL to 400kHz
    TWSR &= ~TWPS0;
    TWSR &= ~TWPS1;
    TWBR = ((F_CPU / TWI_FREQ) - 16) / 2;

    // Enable TWI
    TWCR = 1 << TWEN;
}

void twiStart() {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while ((TWCR & (1 << TWINT)) == 0);
}

void twiStop() {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void twiWrite(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while ((TWCR & (1 << TWINT)) == 0);
}

uint8_t twiReadAck() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while ((TWCR & (1 << TWINT)) == 0);
    return TWDR;
}

uint8_t twiReadNack() {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while ((TWCR & (1 << TWINT)) == 0);
    return TWDR;
}

