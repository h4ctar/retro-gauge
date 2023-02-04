#include "battery.h"

#include "analog.h"
#include "lcd.h"

#include "mode.h"
#include <stdint.h>

#define BATTERY_CHANNEL 6

#define NUM_READINGS 10

uint32_t readings[NUM_READINGS];
uint32_t totalReading = 0;
uint8_t readIndex = 0;
float battVoltage = 0;

void updateBatteryVoltage() {
    totalReading -= readings[readIndex];
    readings[readIndex] = readAnalog(BATTERY_CHANNEL);
    totalReading += readings[readIndex];
    readIndex = (readIndex + 1) % NUM_READINGS;

    uint32_t averageReading = totalReading / NUM_READINGS;
    float pinVoltage = averageReading * 5 / 1024.f;
    battVoltage = pinVoltage * 3.128f + 0.7f;
}

void displayBattery() {
    lcdDisplayFloat(battVoltage, 1, "V");
}

