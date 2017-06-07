#ifndef _TOWER_H_
#define _TOWER_H_

//Setting tower speed to all motors on the tower
void setTowerSpeed(int speed);

//Command to spam during teleop to check if the tower should move
bool towerLogic();

//Encoder on the tower to get the rotation of the tower
int getTowerEncoderValue();

//Variable for tower encoder
extern Encoder towerEncoder;

#endif
