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

#define STEP_PERIOD 1000

#define MAX_POSITION        12
#define STEPS_PER_POSITION  60.
#define MAX_STEPS           (STEPS_PER_POSITION * MAX_POSITION)

uint32_t lastStepTime = 0;
uint16_t currentSteps = 0;
uint16_t targetSteps = 0;

void waitForMotor();
void stepMotor();

void initMotor() {
    MOT_DDR |= MOT_1_MASK;
    MOT_DDR |= MOT_2_MASK;
    MOT_DDR |= MOT_3_MASK;
    MOT_DDR |= MOT_4_MASK;

    // Home the motor
    setMotorTargetPosition(MAX_POSITION);
    waitForMotor();
    setMotorTargetPosition(0);
    waitForMotor();
}

void setMotorTargetPosition(float position) {
    targetSteps = position * STEPS_PER_POSITION;
    if (targetSteps > MAX_STEPS) {
        targetSteps = MAX_STEPS;
    }
    if (targetSteps < 0) {
        targetSteps = 0;
    }
}

float getMotorCurrentPosition() {
    return currentSteps / STEPS_PER_POSITION;
}

void updateMotor() {
    uint32_t currentTime = micros();
    if (currentTime - lastStepTime >= STEP_PERIOD) {
        int16_t delta = targetSteps - currentSteps;
        int8_t direction = (delta > 0) - (delta < 0);

        currentSteps += direction;

        stepMotor();

        lastStepTime = currentTime;
    }
}

void waitForMotor() {
    while (currentSteps != targetSteps) {
        updateMotor();
    }
}

void stepMotor() {
    uint8_t step = currentSteps % 6;

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

