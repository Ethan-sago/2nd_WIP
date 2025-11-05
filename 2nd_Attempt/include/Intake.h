#include "vex.h"
#include "motor.h"
//#include "manual.h"
//#include "autonomous.h"

#ifndef INTAKE_H
#define INTAKE_H


namespace intake {
    inline void buttonPressingIntake(vex::controller &ctrl, int speedPct);
    void FirstIfStatement(vex::controller &ctrl, int speedPct);
    inline void step(
        vex::controller &ctrl,
        vex::motor &top,
        vex::motor &bottom,
        vex::motor &main,
        int speedPct = 100)
    {
        using vex::directionType;
        using vex::percentUnits;
        using vex::brakeType;

        buttonPressingIntake(ctrl, speedPct);
    }

    void buttonPressingIntake(vex::controller &ctrl, int speedPct)
    {
        if (ctrl.ButtonL2.pressing()) { //Full Reverse
            TopIntake.spin(directionType::rev, speedPct, percentUnits::pct);
            BottomIntake.spin(directionType::rev, speedPct, percentUnits::pct);
            MainIntake.spin(directionType::rev, speedPct, percentUnits::pct);
        }
        else if (ctrl.ButtonR2.pressing()) //Full-Intake
        {
            TopIntake.spin(directionType::fwd, speedPct, percentUnits::pct);
            BottomIntake.spin(directionType::fwd, speedPct, percentUnits::pct);
            MainIntake.spin(directionType::fwd, speedPct, percentUnits::pct);
        }
        else if(ctrl.ButtonR1.pressing()){ //Half-Intake
            TopIntake.stop(brakeType::coast);
            BottomIntake.spin(directionType::fwd, speedPct, percentUnits::pct);
            MainIntake.spin(directionType::fwd, speedPct, percentUnits::pct);
        }
        else
        {
            TopIntake.stop(brakeType::coast);
            BottomIntake.stop(brakeType::coast);
            MainIntake.stop(brakeType::coast);
        }
    }
       
}


#endif