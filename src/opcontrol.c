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
// Wheels
  while (1) {
    motorSet(1, joystickGetAnalog(1,3));
    motorSet(2, joystickGetAnalog(1,3));
    motorSet(9, joystickGetAnalog(1,2));
    motorSet(10, joystickGetAnalog(1,2));
// End of Wheels

// Arms
  // Arms Up
    if (joystickGetDigital(1, 6, JOY_UP)){
      motorSet(3, 45);
      motorSet(8, -45);
    }

  // Down
    else if (joystickGetDigital(1, 6, JOY_DOWN)){
      motorSet(3, -45);
      motorSet(8, 45);
    }
  // Default
    else {
      motorSet(3, 0);
      motorSet(8, 0);
    }
// End of Arms

// Mobile Goal
  // Raise
    if (joystickGetDigital(1, 5, JOY_UP)){
      motorSet(6, 45);
      motorSet(7, -45);
    }

  // Lower
    else if (joystickGetDigital(1,5, JOY_DOWN)){
      motorSet(6, -45);
      motorSet(7, 45);
    }

  // Default
    else {
      motorSet(6, 0);
      motorSet(7, 0);
    }
//End of Mobile Goal

// Claw
    // Open
    if (joystickGetDigital(1, 8, JOY_LEFT)){
      motorSet(4, 40);
    }
    // CLose
    else if (joystickGetDigital(1, 8, JOY_DOWN)){
      motorSet(4, -40);
    }
    // Default
    else {
      motorSet(4, 0);
    }
// Claw End
         delay(20);
     }
 }
