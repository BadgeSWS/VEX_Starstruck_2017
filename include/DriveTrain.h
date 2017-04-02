#ifndef _DRIVETAIN_H_
#define _DRIVETAIN_H_

#include "API.h"

// Set motor speeds
void initDriveTrainEncoders();
void setLeft(int speed);
void setRight(int speed);
int getLeftEncoder();
int getRightEncoder();
void calibrateGyro();

extern Encoder leftEncoder, rightEncoder;
extern Gyro gyro;

#endif // _DRIVETAIN_H_
