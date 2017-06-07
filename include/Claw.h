#ifndef _CLAW_H_
#define _CLAW_H_

//Pots and the functions to use them
void calibrateLeftPot();
void calibrateRightPot();
void calibratePots();
int getLeftPot();
int getRightPot();

//Setting the claws to cetain speeds and POT values
void setLeftClaw(int speed);
void setRightClaw(int speed);
void linkClaws();

// Booleans for the buttons the driver needs to press to make the robot do tasks
bool leftClaw();
bool righClaw();
bool openClaw();
bool closeClaw();
bool linkClaw();

//Command to spam during teleop to check if the claw should move
bool clawLogic();

#endif // _CLAW_H_
