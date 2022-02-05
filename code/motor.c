#include <avr/io.h>
#include <stdint.h>

#include "motor.h"
#include "timer.h"

#define MOT_PORT    PORTC
#define MOT_DDR     DDRC
#define MOT_1_MASK  (1 << PC1)
#define MOT_2_MASK  (1 << PC0)
#define MOT_3_MASK  (1 << PC3)
#define MOT_4_MASK  (1 << PC2)

#define MOT_PATTERN_4 0b00000111
#define MOT_PATTERN_3 0b00011100
#define MOT_PATTERN_2 0b00011100
#define MOT_PATTERN_1 0b00110001

#define STEP_TIME 1000

uint32_t lastStepTime = 0;
uint16_t currentPosition = 0;
uint16_t targetPosition = 0;

void stepMotor();

void initMotor() {
    MOT_DDR |= MOT_1_MASK;
    MOT_DDR |= MOT_2_MASK;
    MOT_DDR |= MOT_3_MASK;
    MOT_DDR |= MOT_4_MASK;

    // Home the motor
    setMotorPosition(60 * 12);
    waitForMotor();
    setMotorPosition(0);
    waitForMotor();
}

void setMotorPosition(uint16_t position) {
    targetPosition = position;
}

uint16_t getMotorPosition() {
    return currentPosition;
}

void updateMotor() {
    uint32_t currentTime = micros();
    if (currentTime - lastStepTime >= STEP_TIME) {
        int16_t delta = targetPosition - currentPosition;
        int8_t direction = (delta > 0) - (delta < 0);

        currentPosition += direction;

        stepMotor();

        lastStepTime = currentTime;
    }
}

void waitForMotor() {
    while (currentPosition != targetPosition) {
        updateMotor();
    }
}

void stepMotor() {
    uint8_t step = currentPosition % 6;

    if ((MOT_PATTERN_1 >> step) & 1)
        MOT_PORT |= MOT_1_MASK;
    else
        MOT_PORT &= ~MOT_1_MASK;

    if ((MOT_PATTERN_2 >> step) & 1)
        MOT_PORT |= MOT_2_MASK;
    else
        MOT_PORT &= ~MOT_2_MASK;

    if ((MOT_PATTERN_3 >> step) & 1)
        MOT_PORT |= MOT_3_MASK;
    else
        MOT_PORT &= ~MOT_3_MASK;

    if ((MOT_PATTERN_4 >> step) & 1)
        MOT_PORT |= MOT_4_MASK;
    else
        MOT_PORT &= ~MOT_4_MASK;
}

