/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "PID.h"
#include "DriveTrain.h"
#include "ElectricalConstants.h"
#include "Claw.h"
#include "Tower.h"
#include "AutonMovement.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

void operatorControl() {
	printf("%s\n", "STARTING OP CONTROL.");

	printf("%s\n", "START OF LOOP");
	int delayI = 0;



	while(1){
		//Moves the drive train
		driveLogic();
		//Moves the tower which holds the arm
		bool tl = towerLogic();
		//Moving the claw
		bool cl = clawLogic();

		if(!tl && delayI <= 8){
			/* Stops the claw from going all the way down with 1 tap of the down button.
			It jerks the claw up to stop downwards momentum. */
			setTowerSpeed(12);
			delayI++;
		}
		if(tl){
			delayI = 0;
		}

		//Updates 50 times a second 1sec/0.02sec
		delay(20);
  }

	printf("%s\n", "[WARNING] DONE OP CONTROL");
}
