#include "speedo.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdint.h>

#include "button.h"
#include "indicators.h"
#include "lcd.h"
#include "mode.h"
#include "motor.h"
#include "timer.h"
#include "eeprom.h"
#include "config.h"

#define SPEED_PORT PORTD
#define SPEED_DDR  DDRD
#define SPEED_PIN  PD7

#define WHEEL_DIAMETER          0.68                    // metres
#define WHEEL_CIRCUMFERENCE     (M_PI * WHEEL_DIAMETER) // metres
#define NUMBER_OF_MAGNETS       2.0
#define DISTANCE_PER_PULSE      (WHEEL_CIRCUMFERENCE / NUMBER_OF_MAGNETS) // metres
#define METERS_PER_KILOMETER    1000.0
#define MPS_TO_KPH              3.6
#define MIN_SPEED               5.0 // kilometres per hour
#define MIN_PULSE_PERIOD        (DISTANCE_PER_PULSE / (MIN_SPEED / MPS_TO_KPH) * MILLISECONDS_PER_SECOND)   // milliseconds

volatile uint32_t pulsePeriod = 0;
volatile uint32_t lastPulseTime = 0;

volatile double odo = 0;
volatile double trip = 0;

double speed = 0;

void initInterrupt();
void reset();
void readOdo();
void readTrip();
void writeOdo();
void writeTrip();

ISR(PCINT2_vect) {
    if (PIND & (1 << PD7)) {
        long pulseTime = millis();
        pulsePeriod = pulseTime - lastPulseTime;
        lastPulseTime = pulseTime;

        odo += DISTANCE_PER_PULSE;
        // This is needed because of a bug in the optimiser?
        // It should only put it out a percent or two
        trip += (DISTANCE_PER_PULSE + 0.01);
    }
}

void initSpeedo() {
    // Make the pin an input
    SPEED_DDR &= ~SPEED_PIN;

    initInterrupt();

    readOdo();
    readTrip();

    // Uncomment to reset
    // reset();
}

void initInterrupt() {
    cli();
    // Turn on the pin change interrupt for PORTD
    PCICR |= 0b00000100;

    // Enable it only for PD7
    PCMSK2 |= 0b10000000;
    sei();
}

void reset() {
    eepromWrite(ODO_INDEX, 16);
    eepromWrite32(16, 0);
    eepromWrite(TRIP_INDEX, 20);
    eepromWrite32(20, 0);
}

void updateSpeedo(Mode mode) {
    speed = DISTANCE_PER_PULSE / (pulsePeriod / MILLISECONDS_PER_SECOND) * MPS_TO_KPH;

    if (millis() - lastPulseTime > MIN_PULSE_PERIOD || speed < MIN_SPEED) {
        speed = 0;
    }

    setMotorTargetPosition(speed / 10);

    if (mode == TRIP && consumeLongButtonPress() == BUTTON_DOWN) {
        trip = 0;
    }

    writeOdo();
    writeTrip();
}

void readOdo() {
    odo = readConfig32(ODO_INDEX);
}

void readTrip() {
    trip = readConfig32(TRIP_INDEX);
}

void writeOdo() {
    writeConfig32(ODO_INDEX, odo);
}

void writeTrip() {
    writeConfig32(TRIP_INDEX, trip);
}

void displaySpeed() {
    lcdDisplayInteger(speed, "km/h");
}

void displayOdo() {
    lcdDisplayFloat(odo / METERS_PER_KILOMETER, 1, "km");
}

void displayTrip() {
    lcdDisplayFloat(trip / METERS_PER_KILOMETER, 1, "km");
}

