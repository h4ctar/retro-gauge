// TODO: add the licence 

#include "timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )

// the prescaler is set so that timer0 ticks every 64 clock cycles, and the
// the overflow handler is called every 256 ticks.
#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(64 * 256))
 
// the whole number of milliseconds per timer0 overflow
#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)
 
// the fractional number of milliseconds per timer0 overflow. we shift right
// by three to fit these numbers into a byte. (for the clock speeds we care
// about - 8 and 16 MHz - this doesn't lose precision.)
#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)
 
volatile unsigned long timer0_overflow_count = 0;
volatile unsigned long timer0_millis = 0;
static unsigned char timer0_fract = 0;
 
ISR(TIMER0_OVF_vect) {
    // copy these to local variables so they can be stored in registers
    // (volatile variables must be read from memory on every access)
    unsigned long m = timer0_millis;
    unsigned char f = timer0_fract;
 
    m += MILLIS_INC;
    f += FRACT_INC;
    if (f >= FRACT_MAX) {
        f -= FRACT_MAX;
        m += 1;
    }
 
    timer0_fract = f;
    timer0_millis = m;
    timer0_overflow_count++;
}

void initTimer() {
    // on the ATmega168, timer 0 is also used for fast hardware pwm
    // (using phase-correct PWM would mean that timer 0 overflowed half as often
    // resulting in different millis() behavior on the ATmega8 and ATmega168)
    sbi(TCCR0A, WGM01);
    sbi(TCCR0A, WGM00);

    // set timer 0 prescale factor to 64
    // this combination is for the standard 168/328/1280/2560
    sbi(TCCR0B, CS01);
    sbi(TCCR0B, CS00);

    // enable timer 0 overflow interrupt
    sbi(TIMSK0, TOIE0);
}

unsigned long millis() {
    unsigned long m;
    uint8_t oldSREG = SREG;
 
    cli();
    m = timer0_millis;
    SREG = oldSREG;
 
    return m;
}

unsigned long micros() {
    unsigned long m;
    uint8_t oldSREG = SREG, t;
     
    cli();
    m = timer0_overflow_count;
    t = TCNT0;
 
    if ((TIFR0 & _BV(TOV0)) && (t < 255))
        m++;
 
    SREG = oldSREG;
     
    return ((m << 8) + t) * (64 / clockCyclesPerMicrosecond());
}

