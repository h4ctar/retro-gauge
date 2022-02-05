#include "battery.h"

#include "analog.h"
#include "lcd.h"

#include "mode.h"

#define BATTERY_CHANNEL 7

float battVoltage = 0;

void updateBatteryVoltage() {
    float pinVoltage = readAnalog(BATTERY_CHANNEL) * 5 / 1024.f;
    battVoltage = 0.99 * battVoltage + 0.01 * (pinVoltage * 3.128 + 0.7);
}

void displayBattery() {
    lcdDisplayFloat(battVoltage, 2);
}

