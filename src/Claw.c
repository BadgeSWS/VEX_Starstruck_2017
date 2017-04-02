#include "main.h"
#include "PID.h"
#include "Claw.h"
#include "ElectricalConstants.h"

void calibrateLeftPot(){
    analogCalibrate(POT_LEFT);
}
void calibrateRightPot(){
  analogCalibrate(POT_RIGHT);
}
void calibratePots() {
  calibrateRightPot();
  calibrateLeftPot();
}
int getLeftPot(){
  return analogReadCalibrated(POT_LEFT);
}
int getRightPot(){
  return analogReadCalibrated(POT_RIGHT);
}

void setLeftClaw(int speed){
  motorSet(MOTOR_CLAW_LEFT, speed);
}
void setRightClaw(int speed){
  motorSet(MOTOR_CLAW_RIGHT, speed);
}

bool openClaw() {
  return joystickGetDigital(1, 6, JOY_UP);
}
bool closeClaw() {
  return joystickGetDigital(1, 5, JOY_UP);
}
bool linkClaw() {
  return joystickGetDigital(1, 7, JOY_LEFT);
}
void clawLogic() {
  if(openClaw()){//Claw
    setLeftClaw(127);
    setRightClaw(127);
  } else if (closeClaw()) {
    setLeftClaw(-127);
    setRightClaw(-127);
  } else if (linkClaw()){
    setLeftClaw(0);
    setRightClaw(getValue(&PID_rightClaw, getRightPot(), getLeftPot(), 0.0));
  } else {
    setLeftClaw(0);
    setRightClaw(0);
  }
}
