#include "API.h"
#include "ElectricalConstants.h"
#include "AutonMovement.h"

Encoder towerEncoder;

void setTowerSpeed(int speed){
  motorSet(MOTOR_TOWER_LEFT_A, speed);
  motorSet(MOTOR_TOWER_LEFT_B, -speed);
  motorSet(MOTOR_TOWER_LEFT_C, -speed);

  motorSet(MOTOR_TOWER_RIGHT_A, -speed);
  motorSet(MOTOR_TOWER_RIGHT_B, speed);
  motorSet(MOTOR_TOWER_RIGHT_C, speed);
}

int getTowerEncoderValue(){
  return encoderGet(towerEncoder);
}

bool towerLogic(){
  bool goUp = joystickGetDigital(1, 5, JOY_UP);
  bool goDown = joystickGetDigital(1, 5, JOY_DOWN);

  if(goUp){
    setTowerSpeed(127);
    return false;
  } else if (goDown){
    if(getTowerEncoderValue() <= 15)
      manipTower(15/7.0, 1, 0.2);
    else
      setTowerSpeed(-90);
    return true;
  } else {
    setTowerSpeed(0);
    return false;
  }

}
