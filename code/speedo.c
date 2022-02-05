#include "speedo.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdint.h>

#include "lcd.h"
#include "mode.h"
#include "motor.h"
#include "timer.h"

#define SPEED_PORT PORTD
#define SPEED_DDR  DDRD
#define SPEED_PIN  PD7

#define WHEEL_DIAMETER 0.6477
#define WHEEL_CIRCUMFERENCE (M_PI * WHEEL_DIAMETER)
#define NUMBER_OF_MAGNETS 2

uint32_t lastPulseTime = 0;
uint32_t lastPeriod = 0;
double speed = 0.0;

ISR(PCINT2_vect) {
    uint32_t currentTime = micros();
    if (lastPulseTime) {
        lastPeriod = currentTime - lastPulseTime;
    }
    lastPulseTime = currentTime;
}

void initSpeedo() {
    // Make the pin an input
    SPEED_DDR &= ~SPEED_PIN;

    cli();
    // Turn on the pin change interrupt for PORTD
    // TODO: is there a macro for this?
    PCICR |= 0b00000100;

    // Enable it only for PD7
    PCMSK2 |= 0b10000000;
    sei();
}

void updateSpeedo() {
    double mps = 0;

    cli();
    uint32_t timeSinceLastPulse = micros() - lastPulseTime;
    if (lastPeriod > 0 && timeSinceLastPulse < 1000000) {
        mps = WHEEL_CIRCUMFERENCE / (lastPeriod / 1000000.0) / NUMBER_OF_MAGNETS; 
    }
    sei();

    double kph = mps / 3.6;
    speed = 0.999 * speed + 0.001 * kph;

    setMotorPosition(speed * 6);
}

void displaySpeed() {
    lcdDisplayString("    0k/h");
    // lcdDisplayInteger(speed);
}

void displayOdo() {
    lcdDisplayString("     0km");
}

void displayTrip() {
    lcdDisplayString("     0km");
}

// TODO: setMotorPosition should take double between 0.0 and 12.0
// TODO: motor should check > 0 and < max steps

