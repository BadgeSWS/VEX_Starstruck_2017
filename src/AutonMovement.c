#include "AutonMovement.h"
#include "PID.h"
#include "DriveTrain.h"
#include "Claw.h"
#include "Tower.h"

void drive(int dist, int range, float time) {
  long currentTime = millis();

  //Converting distance in inches into encoder ticks
  dist = dist * (360/(3.14*4));

  resetEncoders();

  //Inits of variables
  int count = 0;
  bool finished = false;
  float leftDist, rightDist, gyroAngle;

  //Loops untill time is up or it is in the range for 20 iterations
  while(!finished && currentTime > millis() - time*1000) {

    leftDist = getLeftEncoder();
    rightDist = getRightEncoder();

    //PID speed values
    int rightBaseSpeed = getValue(&PID_rightDrive, rightDist, dist, 0.0);
    int leftBaseSpeed = getValue(&PID_leftDrive, leftDist, dist, 0.0);

    setRight(rightBaseSpeed);
    setLeft(leftBaseSpeed);

    //Checking to see if in the range or not
    if(abs(dist - leftDist) < range && abs(dist - rightDist) < range){
      count++;
    } else {
      count = 0;
    }

    if(count > 20){
      finished = true;
    }

    // Don't forget the 20 ms delay or robot fries
    delay(20);

  }
  //Set motors to zero. After it is done you do not want your robot to continue moving
  setLeft(0);
  setRight(0);
}

// WE NEVER USE TURN, THE CODE ISNT TESTED OR WORKING
void turn(int angle, int range, float time) {
  long currentTime = millis();
  resetGyro();

  int count = 0;
  bool finished = false;
  int gyroAngle;

  while(!finished && currentTime > millis() - time*1000){
    gyroAngle = getGyro();
    int gyroSpeed = getValue(&PID_gyro, gyroAngle, angle, 0.0);

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

void manipClaw(int leftDeg, int rightDeg, int range, float time) {
  long currentTime = millis();

  //Inits for variables
  int count = 0;
  bool finished = false;
  int leftPotValue, rightPotValue;

  //Loops untill time is up or it is in the range for 20 iterations
  while(!finished && currentTime > millis() - time*1000){

    leftPotValue = getLeftPot();
    rightPotValue = getRightPot();

    //PID speed values
    int rightSpeed = getValue(&PID_rightClaw, rightPotValue, rightDeg, 0.0);
    int leftSpeed = getValue(&PID_leftClaw, leftPotValue, leftDeg, 0.0);

    setLeftClaw(leftSpeed);
    setRightClaw(rightSpeed);

    //Checking to see if in the range or not
    if(abs(leftDeg - leftPotValue) < range && abs(rightDeg - rightPotValue) < range){
      count++;
    } else {
      count = 0;
    }

    if(count > 20){
      finished = true;
    }

    delay(20);
  }
  //Set motors to zero. After it is done you do not want your robot to continue moving
  setLeftClaw(0);
  setRightClaw(0);
}

void manipTower(int deg, int range, float time) {
  //Converting 12 tooth gear to 84 tooth gear in degrees
  deg *= 7;
  long currentTime = millis();

  //Inits for variables
  int count = 0;
  bool finished = false;
  int encoderValue;

  while(!finished && currentTime > millis() - time*1000){

    encoderValue = getTowerEncoderValue();

    //PID speed values
    int towerSpeed = getValue(&PID_tower, encoderValue, deg, 0.0);

    setTowerSpeed(towerSpeed);

    //Checking to see if in the range or not
    if(abs(deg - encoderValue) < range){
      count++;
    } else {
      count = 0;
    }

    if(count > 20){
      finished = true;
    }
    // Don't forget the 20 ms delay or robot fries
    delay(20);
  }
  //Set motors to zero. After it is done you do not want your robot to continue moving
  setTowerSpeed(0);
}
