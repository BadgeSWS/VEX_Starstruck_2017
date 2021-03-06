#ifndef _PID_H_
#define _PID_H_

//Allows me to use multiple PIDs with the limitations of classes that C has
struct PID {
	float p;
	float d;
	float i;
	float max;
	float min;
	float curTarget;

	float e;
	float ePrev;
	float eDiff;
	float iCounter;

	float output;
};
//All PId variables
extern struct PID PID_tower, PID_gyro, PID_leftDrive, PID_rightDrive, PID_leftClaw, PID_rightClaw;

//PID functions stolen and converted from CharsLIB
void pid(struct PID *pid, float p, float i, float d, float min, float max);
void resetPID(struct PID *pid);
float getValue(struct PID *pid, float input, float target, float feedForward);
void updatePID(struct PID *pid, float p, float i, float d);
float getError(struct PID *pid);

#endif // _PID_H_
