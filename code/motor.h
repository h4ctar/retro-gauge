#ifndef _MOTOR_H
#define _MOTOR_H

#include <stdint.h>

void initMotor();
void setMotorPosition(uint16_t position);
void updateMotor();
void waitForMotor();

#endif

