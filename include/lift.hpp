#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor lift(9); 
inline pros::Rotation liftSensor(10);

void liftSet(int input, int velocity);
void pulse();