#include "main.h"
#include "ElectricalConstants.h"
#include "DriveTrain.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

Encoder leftEncoder, rightEncoder;
Gyro gyro;

void setLeft(int speed) {
  motorSet(MOTOR_FRONT_LEFT, MAX(MIN(speed, 127),-127));
  motorSet(MOTOR_BACK_LEFT, -MAX(MIN(speed, 127),-127));
}
void setRight(int speed) {
  motorSet(MOTOR_FRONT_RIGHT, -MAX(MIN(speed, 127),-127));
  motorSet(MOTOR_BACK_RIGHT, -MAX(MIN(speed, 127),-127));
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
  setLeft(y+x);
  setRight(y-x);
}
