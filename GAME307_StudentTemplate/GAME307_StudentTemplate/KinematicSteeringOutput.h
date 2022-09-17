#pragma once
#include "Vector.h"
using namespace MATH;
class KinematicSteeringOutput {
public:
	Vec3 velocity;
	float rotation;

	KinematicSteeringOutput();
	KinematicSteeringOutput(Vec3 velocity, float rotation);
};

