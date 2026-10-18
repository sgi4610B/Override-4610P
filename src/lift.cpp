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

void lift_no_reset(int inp, int velo){

    while(liftSensor.get_position() != inp*100){
        while (liftSensor.get_position() > inp*100){
            lift.move(-velo);
        }
        while (liftSensor.get_position() < inp*100){
            lift.move(velo);
        }
    }
    lift.set_brake_mode(MOTOR_BRAKE_HOLD);
    lift.brake();

}

void pulse(){
    while(1){
        lift.move(3);
        pros::delay(50);
        lift.move(-3);
        pros::delay(50);
    }
}
