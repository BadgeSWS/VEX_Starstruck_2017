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
  return analogReadCalibratedHR(POT_LEFT);
}
int getRightPot(){
  return analogReadCalibratedHR(POT_RIGHT);
}

void setLeftClaw(int speed){
  motorSet(MOTOR_CLAW_LEFT, speed);
}
void setRightClaw(int speed){
  motorSet(MOTOR_CLAW_RIGHT, speed);
}
bool leftClaw(){
  return joystickGetDigital(1, 7, JOY_LEFT);
}
bool rightClaw(){
  return joystickGetDigital(1, 7, JOY_RIGHT);
}
bool openClaw() {
  return joystickGetDigital(1, 6, JOY_UP);
}
bool closeClaw() {
  return joystickGetDigital(1, 6, JOY_DOWN);
}
bool linkClaw() {
  return joystickGetDigital(1, 8, JOY_DOWN) || joystickGetDigital(1, 7, JOY_DOWN);
}

void linkClaws() {
  setLeftClaw(getValue(&PID_leftClaw, getLeftPot(), 57344, 0.0));
  setRightClaw(getValue(&PID_rightClaw, getRightPot(), 41424, 0.0));
}

bool clawLogic() {
  //TODO ADD CHECK TO NOT MOVE CLAW IF GOING TO BREAK POT
  if(openClaw()){//Claw
    setLeftClaw(127);
    setRightClaw(-127);
    return true;
  } else if (closeClaw()) {
    setLeftClaw(-127);
    setRightClaw(127);
    return true;
  } else if (linkClaw()){
    linkClaws();
    return true;
  } else {
    setLeftClaw(0);
    setRightClaw(0);
    return false;
  }
}
