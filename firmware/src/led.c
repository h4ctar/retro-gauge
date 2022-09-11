#include <avr/io.h>
#include <util/atomic.h>
#include <util/delay.h>

#include "led.h"

#define LED_PORT PORTB
#define LED_DDR DDRB
#define LED_BIT 2

#define T1H 900
#define T1L 600
#define T0H 400
#define T0L 900

#define NS_TO_CYCLES(n) (n / (1000000000L / F_CPU))

#define WRITE_BIT(timeHigh, timeLow) \
    asm volatile( \
        "sbi %[port], %[bit] \n\t" \
        ".rept %[onCycles] \n\t" \
        "nop \n\t" \
        ".endr \n\t" \
        "cbi %[port], %[bit] \n\t" \
        ".rept %[offCycles] \n\t" \
        "nop \n\t" \
        ".endr \n\t" :: \
        [port]      "I"(_SFR_IO_ADDR(LED_PORT)), \
        [bit]       "I"(LED_BIT), \
        [onCycles]  "I"(NS_TO_CYCLES(timeHigh) - 2), \
        [offCycles] "I"(NS_TO_CYCLES(timeLow) - 2) \
    )

inline void sendByte(unsigned char byte);
inline void sendBit(unsigned char bitVal);

void initLed() {
    LED_DDR |= 1 << LED_BIT;
}

void writeLeds(long ledColors[], int size) {
    cli();
    for (int i = 0; i < size; i++) {
        sendByte(ledColors[i] >> 8 & 0xFF);
        sendByte(ledColors[i] >> 16 & 0xFF);
        sendByte(ledColors[i] & 0xFF);
    }
    _delay_us(250);
    sei();
}

inline void sendByte(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        sendBit(byte & (1 << i));
    }
}

inline void sendBit(unsigned char bitVal) {
    if (bitVal) {
        WRITE_BIT(T1H, T1L);
    } else {
        WRITE_BIT(T0H, T0L);
    }
}

