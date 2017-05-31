#ifndef _CLAW_H_
#define _CLAW_H_

void calibrateLeftPot();
void calibrateRightPot();
void calibratePots();
int getLeftPot();
int getRightPot();

void setLeftClaw(int speed);
void setRightClaw(int speed);
void linkClaws();

bool leftClaw();
bool righClaw();
bool openClaw();
bool closeClaw();
bool linkClaw();

bool clawLogic();

#endif // _CLAW_H_
