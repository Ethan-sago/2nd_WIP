#include "vex.h"
#include "motor.h"

using namespace vex;

#ifndef SENSORS_H
#define SENSORS_H

//rotaional sensor, motion encoder, inertal sensor
//autonomous layout code, dpi, odometry, inertial sensor


inertial inertial_sensor(PORT16);

rotation rotational_sensor1(PORT1, false);

encoder encoder1(Brain.ThreeWirePort.A);
encoder encoder2(Brain.ThreeWirePort.C);

void initSensors(){
    rotational_sensor1.resetPosition();
    encoder1.resetRotation();
    encoder2.resetRotation();

    inertial_sensor.calibrate();

    while (inertial_sensor.isCalibrating()) 
        this_thread::sleep_for(20);
    
}


#endif