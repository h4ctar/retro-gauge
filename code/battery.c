#include "battery.h"

#include "analog.h"
#include "lcd.h"

#include "mode.h"
#include <stdint.h>

#define BATTERY_CHANNEL 7

#define NUM_READINGS 10

uint32_t readings[NUM_READINGS];
uint32_t total = 0;
uint8_t readIndex = 0;
float battVoltage = 0;

void updateBatteryVoltage() {
    total -= readings[readIndex];
    readings[readIndex] = readAnalog(BATTERY_CHANNEL);
    total += readings[readIndex];
    readIndex = (readIndex + 1) % NUM_READINGS;

    uint32_t average = total / NUM_READINGS;
    float pinVoltage = average * 5 / 1024.f;
    battVoltage = pinVoltage * 3.128f + 0.7f;
}

void displayBattery() {
    lcdDisplayFloat(battVoltage, 1);
}

