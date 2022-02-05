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

#define WHEEL_DIAMETER      0.6477
#define WHEEL_CIRCUMFERENCE (M_PI * WHEEL_DIAMETER)
#define NUMBER_OF_MAGNETS   2
// If the period between two pulses excedes this threshold then the bike is considered stopped (microseconds)
#define STOPPED_THRESHOLD   1000000

#define NUMBER_OF_PERIODS 10

double kilometersPerHour = 0.0;

uint32_t lastPulseTime = 0;
uint32_t periods[NUMBER_OF_PERIODS];
uint32_t totalPeriod;
uint8_t periodIndex = 0;

ISR(PCINT2_vect) {
    uint32_t currentTime = micros();
    if (lastPulseTime) {
        totalPeriod -= periods[periodIndex];
        periods[periodIndex] = currentTime - lastPulseTime;
        totalPeriod += periods[periodIndex];
        periodIndex = (periodIndex + 1) % NUMBER_OF_PERIODS;
    }
    lastPulseTime = currentTime;
}

void initSpeedo() {
    // Make the pin an input
    SPEED_DDR &= ~SPEED_PIN;

    cli();
    // Turn on the pin change interrupt for PORTD
    PCICR |= 0b00000100;

    // Enable it only for PD7
    PCMSK2 |= 0b10000000;
    sei();
}

void updateSpeedo() {
    // The average period in micro seconds
    uint32_t averagePeriod = 0;

    cli();
    uint32_t timeSinceLastPulse = micros() - lastPulseTime;
    // Leave the period at zero if the time since last pulse exceeded the stopped threshold
    if (timeSinceLastPulse < STOPPED_THRESHOLD) {
        averagePeriod = totalPeriod / NUMBER_OF_PERIODS;
    }
    sei();

    float metersPerSecond = WHEEL_CIRCUMFERENCE / (averagePeriod / 1000000.f) / NUMBER_OF_MAGNETS; 
    kilometersPerHour = metersPerSecond / 3.6f;

    setMotorTargetPosition(kilometersPerHour / 10);
}

void displaySpeed() {
    lcdDisplayInteger(kilometersPerHour, "km/h");
}

void displayOdo() {
    lcdDisplayInteger(0, "km");
}

void displayTrip() {
    lcdDisplayInteger(0, "km");
}

// TODO: setMotorPosition should take double between 0.0 and 12.0
// TODO: motor should check > 0 and < max steps

