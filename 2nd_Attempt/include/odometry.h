#ifndef ODOMETRY_H
#define ODOMETRY_H  

//#include "robot_config.h"
#include "vex.h"
#include "sensors.h"

#include <stack> 
#include <utility>
#include <cmath>

using namespace vex; 
using namespace std; 

class Odometry {
    private: 
        double last_angle_rotational_1 = 0; 
        double last_angle_rotational_2 = 0; 
        double last_angle_rotational_3 = 0; 
        double last_angle_inertial = 0; 
        double sl = 0.0762; // 3 inches
        double sr = 0.0762; // 3 inches
        double ss = 0.0762; // 3 inches
        double wheel_diameter = 0.3362;  
        double t0; 
        double v_lin; 
        double w_yaw; 

        stack<pair<double, double>> positions; 

        double deg_to_rad(double deg) {
            return deg * M_PI / 180; 
        }

    public: 
        Odometry(double inertial, double rotational_1, double rotational_2, double rotational_3) 
            :  last_angle_inertial{inertial}, last_angle_rotational_1{rotational_1}, last_angle_rotational_2{rotational_2}, last_angle_rotational_3{rotational_3} {
                positions.push({0, 0});
                t0 = 0; 
        }

        void update() {
            double angle_rot_1 = rotational_sensor1.position(degrees);
            double angle_rot_2 = encoder1.position(degrees);
            double angle_rot_3 = encoder2.position(degrees);
            double angle_inertial = inertial_sensor.rotation(degrees);

            double delta_rot_1 = angle_rot_1 - last_angle_rotational_1;
            double delta_rot_2 = angle_rot_2 - last_angle_rotational_2;
            double delta_rot_3 = angle_rot_3 - last_angle_rotational_3;
            double delta_angle_inertial = angle_inertial - last_angle_inertial; 

            last_angle_rotational_1 = angle_rot_1; 
            last_angle_rotational_2 = angle_rot_2;
            last_angle_rotational_3 = angle_rot_3;
            last_angle_inertial = angle_inertial; 

            double delta_L = delta_rot_1 * wheel_diameter;
            double delta_R = delta_rot_2 * wheel_diameter; 
            double delta_S = delta_rot_3 * wheel_diameter;
    
            double delta_theta = deg_to_rad(delta_angle_inertial);

            double delta_x = 0, delta_y = 0; 
            if (delta_theta == 0) {
                delta_y = delta_R; 
                delta_x = delta_S; 
            } else {
                delta_x = 2 * sin(delta_theta / 2) * (delta_S / delta_theta + ss);
                delta_y = 2 * sin(delta_theta / 2) * (delta_R / delta_theta + sr);

            }
            const auto& last_pos = positions.top(); 
            pair<double, double> pos = make_pair(delta_x+ last_pos.first, delta_y+ last_pos.second); 
            positions.push(pos);

        }

        double getX() const{
            return positions.top().first; 
        }

        double getY() const{
            return positions.top().second; 
        }

        double get_headings() const {
            return inertial_sensor.rotation(degrees);
        }
};
#endif 