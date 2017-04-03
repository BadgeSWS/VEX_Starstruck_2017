#include "AutonMovement.h"
#include "PID.h"
#include "DriveTrain.h"
#include "Claw.h"

void drive(int dist, int range, float time) {
  long currentTime = millis();

  resetGyro();
  resetEncoders();

  int count = 0;
  bool finished = false;
  float leftDist, rightDist, gyroAngle;

  while(!finished && currentTime > millis() - time*1000) {

    leftDist = getLeftEncoder()*3.14;
    rightDist = getRightEncoder()*3.14;
    gyroAngle = getGyro();

    int rightBaseSpeed = getValue(&PID_rightDrive, rightDist, dist, 0.0);
    int leftBaseSpeed = getValue(&PID_leftDrive, leftDist, dist, 0.0);

    int gyroSpeed = getValue(&PID_gyro, gyroAngle, 0, 0.0);

    setRight(rightBaseSpeed + gyroSpeed);
    setLeft(leftBaseSpeed - gyroSpeed);

    if(abs(dist - leftDist) < range && abs(dist - rightDist) < range){
      count++;
    } else {
      count = 0;
    }

    if(count > 20){
      finished = true;
    }

    delay(20);

  }
  setLeft(0);
  setRight(0);
}

void turn(int angle, int range, float time) {
  long currentTime = millis();
  resetGyro();

  int count = 0;
  bool finished = false;
  int gyroAngle;

  while(!finished && currentTime > millis() - time*1000){
    gyroAngle = getGyro();
    int gyroSpeed = getValue(&PID_gyro, gyroAngle, 0, 0.0);

    setRight(gyroSpeed);
    setLeft(-gyroSpeed);

    if(abs(angle - gyroAngle) < range){
      count++;
    } else {
      count = 0;
    }

    if(count > 20){
      finished = true;
    }
    delay(20);
  }
  setLeft(0);
  setRight(0);
}
void manipClaw(int deg, int range, float time) {
  long currentTime = millis();

  int count = 0;
  bool finished = false;
  int leftPotValue, rightPotValue;

  while(!finished && currentTime > millis() - time*1000){

    leftPotValue = getLeftPot();
    rightPotValue = getRightPot();

    int rightSpeed = getValue(&PID_rightClaw, rightPotValue, -deg, 0.0);
    int leftSpeed = getValue(&PID_leftClaw, leftPotValue, deg, 0.0);

    setLeftClaw(leftSpeed);
    setRightClaw(rightSpeed);

    if(abs(deg - leftPotValue) < range && abs(deg + rightPotValue) < range){
      count++;
    } else {
      count = 0;
    }

    if(count > 20){
      finished = true;
    }

    delay(20);
  }
  setLeftClaw(0);
  setRightClaw(0);
}
