#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor lift(21); 
inline pros::Rotation liftSensor(19);

void lift_reset(int inp, int velo);
void lift_no_reset(int inp, int velo);
void pulse();