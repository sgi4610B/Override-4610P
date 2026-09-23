#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');

//inline pros::Motor lift(21);
inline pros::Motor toggleLeft(6);
inline pros::Motor toggleRight(5);
//inline pros::Rotation liftSensor(10);
inline ez::Piston claw('A');


// 20 -- Lift motor
//6 -- toggle left from back
//5 -- toggle right from back
//10 -- rotation sensor of height extended
