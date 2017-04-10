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
int getGyro() {
  return gyroGet(gyro);
}
void calibrateGyro() {
  analogCalibrate(GYRO);
}
void resetGyro() {
  gyroReset(gyro);
}
void resetEncoders() {
  encoderReset(leftEncoder);
  encoderReset(rightEncoder);
}
void driveLogic() {
  int y = joystickGetAnalog(1, 3);
  int x = joystickGetAnalog(1, 1);

  setLeft((y*3.5+x*2)/3);
  setRight((y*3.5-x*2)/3);
}
