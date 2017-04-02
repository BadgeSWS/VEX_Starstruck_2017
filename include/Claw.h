#ifndef _CLAW_H_
#define _CLAW_H_

void calibrateLeftPot();
void calibrateRightPot();
void calibratePots();
int getLeftPot();
int getRightPot();

void setLeftClaw(int speed);
void setRightClaw(int speed);

bool openClaw();
bool closeClaw();
bool linkClaw();

void clawLogic();

#endif // _CLAW_H_
