#ifndef _TOWER_H_
#define _TOWER_H_

void setTowerSpeed(int speed);
bool towerLogic();
int getTowerEncoderValue();

extern Encoder towerEncoder;

#endif
