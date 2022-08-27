#ifndef _MOTOR_H
#define _MOTOR_H

#include <stdint.h>

void initMotor();
void setMotorTargetPosition(float position);
void updateMotor();

#endif

