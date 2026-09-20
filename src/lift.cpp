#include "main.h"
#include "lift.hpp"

void liftSet(int input, int velocity){

    liftSensor.reset_position();
    while(liftSensor.get_position() < input){
        lift.move(velocity);
    }

}
