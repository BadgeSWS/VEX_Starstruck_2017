/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "DriveTrain.h"
#include "ElectricalConstants.h"
#include "Claw.h"
#include "PID.h"
#include "Tower.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
void initialize() {
  printf("%s\n", "STARTING INIT");

  printf("%s\n", "INITIALIZING PID STRUCTS");
  pid(&PID_leftDrive, 0.9, 0.0, 0.0 , -127, 127);
  pid(&PID_rightDrive, 0.9, 0.0, 0.0 , -127, 127);
  pid(&PID_leftClaw, -0.04, 0.0, 0.0 , -127, 127);
  pid(&PID_rightClaw, 0.018, 0.0, 0.0 , -127, 127);
  pid(&PID_gyro, 1.0, 0.0, 0.0, -127, 127);
  pid(&PID_tower, 1.0, 0.0, 0.0, -127, 127);

  printf("%s\n", "SETTING ENCODERS");
  leftEncoder = encoderInit(ENCODER_LEFT_TOP, ENCODER_LEFT_BOT, true);
  rightEncoder = encoderInit(ENCODER_RIGHT_TOP, ENCODER_RIGHT_BOT, false);
  towerEncoder = encoderInit(ENCODER_TOWER_TOP, ENCODER_TOWER_BOT, true);

  printf("%s\n", "SETTING GYRO");
  gyro = gyroInit(GYRO, 1);

  printf("%s\n", "RESET GYRO");
  resetGyro();

  printf("%s\n", "CALIBRATING SENSORS");
  //calibrateGyro();
  //calibratePots();

  //P.S. do not calibrate pots its a bad idea

  printf("%s\n", "DONE INIT");
}
