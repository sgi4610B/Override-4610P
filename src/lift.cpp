#include "main.h"
#include "lift.hpp"

void lift_reset(int inp, int velo){

    liftSensor.reset_position();
    while(liftSensor.get_position() < fabs(inp*100)){
        pros::screen::print(pros::E_TEXT_LARGE, 6, "Lift Sensor: %i", (inp*100 - liftSensor.get_position()));
        pros::delay(50);
        lift.move(velo);
    }

}

/*

MACRO VALUES (in terms of how many pins per stack):

 - 1 pin:
 - 2 pins:
 - 3 pins:
 - 4 pins:
 - 5 pins:
 - 6 pins (probably not advisable): 

*/

void lift_no_reset(int inp){ 
    lift.set_brake_mode(MOTOR_BRAKE_HOLD);
    double kp = 1;
    double kd = 1;
    //float targetHeading = wrapAngle(targetHeading);

    double derivative, speed;
    double currentHeading = liftSensor.get_position();
    double error = fabs(inp - (liftSensor.get_position())/100);
    double previousError = error; 

    while(fabs(error) > 2.0){
        pros::screen::print(pros::E_TEXT_LARGE,3,"Lift Sensor: %i",(liftSensor.get_position()));
        currentHeading = liftSensor.get_position();
        previousError = error;
        error = fabs(inp - (liftSensor.get_position())/100);
        derivative = error - previousError;
        speed = error * kp + derivative * kd;
        lift.move(speed);
        pros::delay(10);
    }
    lift.brake();

}

void lift_pid(){
    lift.set_brake_mode(MOTOR_BRAKE_HOLD);
    double kp = 1;
    double kd = 1;

    double currentPosition = liftSensor.get_position();

}

void pulse(){
    while(1){
        lift.move(3);
        pros::delay(50);
        lift.move(-3);
        pros::delay(50);
    }
}
