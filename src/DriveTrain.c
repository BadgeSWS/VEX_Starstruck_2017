#include "main.h"
#include "ElectricalConstants.h"
#include "DriveTrain.h"

Encoder leftEncoder, rightEncoder;
Gyro gyro;

void setLeft(int speed) {
  motorSet(MOTOR_FRONT_LEFT, speed);
  motorSet(MOTOR_BACK_LEFT, speed);
}
void setRight(int speed) {
  motorSet(MOTOR_FRONT_RIGHT, speed);
  motorSet(MOTOR_BACK_RIGHT, speed);
}
int getLeftEncoder() {
  return encoderGet(leftEncoder);
}
int getRightEncoder() {
  return encoderGet(rightEncoder);
}
int getGyro(){
  return gyroGet(gyro);
}
void calibrateGyro(){
  analogCalibrate(GYRO);
}
