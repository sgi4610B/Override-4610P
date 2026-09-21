#include "main.h"
#include "lift.hpp"

void liftSet(int input, int velocity){

    liftSensor.reset_position();
    while(liftSensor.get_position() < input){
        lift.move(velocity);
    }

}

void pulse(){
    while(1){
        lift.move(3);
        pros::delay(50);
        lift.move(-3);
        pros::delay(50);
    }
}
