#ifndef _DRIVETAIN_H_
#define _DRIVETAIN_H_

#include "API.h"


//Drive encoders
void initDriveTrainEncoders();
int getLeftEncoder();
int getRightEncoder();

//Setting speeds
void setLeft(int speed);
void setRight(int speed);

//Gyro calibration and values
void calibrateGyro();
int getGyro();

//Resets
void resetGyro();
void resetEncoders();

//Command to spam during teleop to check if the drive train should move
void driveLogic();

//Variables for encoders and gyro
extern Encoder leftEncoder, rightEncoder;
extern Gyro gyro;

#endif // _DRIVETAIN_H_
