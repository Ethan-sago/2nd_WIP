#include "vex.h"
#include "motor.h"

using namespace vex;

#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

void driveFoward(double distance_mm, int speed_pct) {
    Drive.setDriveVelocity(speed_pct, percent);
    Drive.driveFor(forward, distance_mm, mm);
}


void turnRight(double angle_deg, int speed_pct) {
    Drive.setTurnVelocity(speed_pct, percent);
    Drive.turnFor(right, angle_deg, degrees);
}

void turnLeft(double angle_deg, int speed_pct) {
    Drive.setTurnVelocity(speed_pct, percent);
    Drive.turnFor(left, angle_deg, degrees);
}

void autonomous(void) {

    
}

#endif 
