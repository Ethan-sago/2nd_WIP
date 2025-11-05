/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Alejandro                                                 */
/*    Created:      10/31/2025, 8:48:27 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "motor.h"
#include "autonomous.h"
#include "manual.h"


// A global instance of competition
competition Competition;

using namespace vex;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/



int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  //pre_auton();

  while (true) {
    wait(100, msec);
  }
}