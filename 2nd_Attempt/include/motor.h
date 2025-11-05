#include "vex.h"
using namespace vex;

#ifndef MOTOR_H
#define MOTOR_H


brain Brain;


motor LeftMotorGroupMotorA = motor(PORT1, ratio6_1, false); //front
motor LeftMotorGroupMotorB = motor(PORT2, ratio6_1, false); //mid
motor LeftMotorGroupMotorC = motor(PORT3, ratio6_1, false); //back

motor BottomIntake = motor(PORT11, ratio18_1, false); 
motor TopIntake = motor(PORT12, ratio18_1, false); 
motor MainIntake = motor(PORT13, ratio18_1, false); 

motor_group LeftMotorGroup = motor_group(LeftMotorGroupMotorA, LeftMotorGroupMotorB, LeftMotorGroupMotorC);

motor RightMotorGroupMotorA = motor(PORT4, ratio6_1, true); //front
motor RightMotorGroupMotorB = motor(PORT5, ratio6_1, true); //mid
motor RightMotorGroupMotorC = motor(PORT6, ratio6_1, true); //back

//motor Intake = motor(PORT14, ratio36_1, true);

motor_group Intakes = motor_group(TopIntake, BottomIntake, MainIntake);

motor_group RightMotorGroup = motor_group(RightMotorGroupMotorA, RightMotorGroupMotorB, RightMotorGroupMotorC);

controller Controller1 = controller(primary);

drivetrain Drive(LeftMotorGroup, RightMotorGroup, 319.19, 320, 40, mm, 1);

//smartdrive Drive(LeftMotorGroup, RightMotorGroup, inrt, 319.19, 320, 40, mm, 1.0);

//making assumption we'll have the intake, rootaional sensor, motion encoder, inertal sensor, light
// cant use the same class name for both drivetrain and smartdrive; or that they conflict with each other. FIgure it out later

#endif