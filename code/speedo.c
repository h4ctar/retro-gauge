#include "speedo.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdint.h>

#include "button.h"
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

#define NUMBER_OF_PERIODS 20

double kilometersPerHour = 0.0;
volatile double odo = 0.0;
double tripReset = 0.0;

volatile uint32_t lastPulseTime = 0;
volatile uint32_t periods[NUMBER_OF_PERIODS];
volatile uint32_t totalPeriod;
volatile uint8_t periodIndex = 0;

ISR(PCINT2_vect) {
    uint32_t currentTime = micros();
    if (lastPulseTime) {
        totalPeriod -= periods[periodIndex];
        periods[periodIndex] = currentTime - lastPulseTime;
        totalPeriod += periods[periodIndex];
        periodIndex = (periodIndex + 1) % NUMBER_OF_PERIODS;

        odo += WHEEL_CIRCUMFERENCE / NUMBER_OF_MAGNETS;
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

void updateSpeedo(Mode mode) {
    // The average period in micro seconds
    double averagePeriod = 0;

    cli();
    uint32_t timeSinceLastPulse = micros() - lastPulseTime;
    // Leave the period at zero if the time since last pulse exceeded the stopped threshold
    if (timeSinceLastPulse < STOPPED_THRESHOLD) {
        averagePeriod = (double) totalPeriod / NUMBER_OF_PERIODS;
    }
    sei();

    if (averagePeriod) {
        double metersPerSecond = WHEEL_CIRCUMFERENCE / (averagePeriod / 1000000.) / NUMBER_OF_MAGNETS; 
        kilometersPerHour = metersPerSecond / 3.6;
    } else {
        kilometersPerHour = 0;
    }

    setMotorTargetPosition(kilometersPerHour / 10);

    if (mode == TRIP && consumeLongButtonPress() == BUTTON_DOWN) {
        tripReset = odo;
    }
}

void displaySpeed() {
    lcdDisplayInteger(kilometersPerHour, "km/h");
}

void displayOdo() {
    // lcdDisplayInteger(odo / 1000, "km");
    lcdDisplayFloat(odo / 1000, 1, "km");
}

void displayTrip() {
    lcdDisplayFloat((odo - tripReset) / 1000, 1, "km");
}

