#ifndef _AUTONMOVEMENT_H_
#define _AUTONMOVEMENT_H_

// The functions for each command I will need during the auton period
void drive(int dist, int range, float time);
void turn(int angle, int range, float time);
void manipTower(int deg, int range, float time);
void manipClaw(int leftdeg, int rightDeg, int range, float time);

#endif // _AUTONMOVEMENT_H_
