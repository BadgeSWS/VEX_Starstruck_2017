#include "API.h"
#include "ElectricalConstants.h"

Encoder towerEncoder;

void setTowerSpeed(int speed){
  motorSet(MOTOR_TOWER_LEFT_A, speed);
  motorSet(MOTOR_TOWER_LEFT_B, -speed);
  motorSet(MOTOR_TOWER_LEFT_C, -speed);

  motorSet(MOTOR_TOWER_RIGHT_A, -speed);
  motorSet(MOTOR_TOWER_RIGHT_B, speed);
  motorSet(MOTOR_TOWER_RIGHT_C, speed);
}

bool towerLogic(){
  bool goUp = joystickGetDigital(1, 5, JOY_UP);
  bool goDown = joystickGetDigital(1, 5, JOY_DOWN);

  if(goUp){
    setTowerSpeed(127);
    return false;
  } else if (goDown){
    setTowerSpeed(-127);
    return true;
  } else {
    setTowerSpeed(0);
    return false;
  }

}

int getTowerEncoderValue(){
  return encoderGet(towerEncoder);
}
