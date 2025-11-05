#include "vex.h"
#include "motor.h"
#include "intake.h"

using namespace vex;

#ifndef MANUAL_H
#define MANUAL_H

#define STRATEGY_A true // tank
#define STRATEGY_B false //arcade


//bool driveMode = false;

static inline int clampPct(int v) {
    if (v > 100) return 100;
    if (v < -100) return -100;
    return v;
}

   

void arcadeDriveStep(controller& ctrl, motor_group& left, motor_group& right, int deadband = 5) {
    int fwd = ctrl.Axis3.position(percent);
    int turn = ctrl.Axis1.position(percent);

    if (abs(fwd) < deadband) fwd = 0;
    if (abs(turn) < deadband) turn = 0;

    int l = clampPct(fwd + turn);
    int r = clampPct(fwd - turn);

    left.setVelocity(l, percent);
    right.setVelocity(r, percent);

    left.spin(vex::forward);
    right.spin(vex::forward);
}


void tankDriveStep(controller& ctrl, motor_group& left, motor_group& right, int deadband = 5) {
    int l = ctrl.Axis3.position(percent);
    int r = ctrl.Axis2.position(percent);

    if (abs(l) < deadband) l = 0;
    if (abs(r) < deadband) r = 0;

    left.setVelocity(clampPct(l), percent);
    right.setVelocity(clampPct(r), percent);

    left.spin(vex::forward);
    right.spin(vex::forward);
    

}

//Figure out how to switch between arcade and tank through strategies 

void usercontrol(void) {
  while (true) {
    if (Controller1.ButtonA.pressing()) {
        tankDriveStep(Controller1, LeftMotorGroup, RightMotorGroup);
        wait(300, msec);
    }   
    else
        arcadeDriveStep(Controller1, LeftMotorGroup, RightMotorGroup);
        intake::step(Controller1, TopIntake, BottomIntake, MainIntake, 100);
        wait(20, msec);
  }
}




#endif