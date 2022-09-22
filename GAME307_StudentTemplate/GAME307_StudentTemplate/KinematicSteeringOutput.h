#pragma once
#include "Vector.h"
using namespace MATH;
class KinematicSteeringOutput {
public:
	Vec3 velocity;
	float rotation; //quaternion

	KinematicSteeringOutput();
	KinematicSteeringOutput(Vec3 velocity, float rotation);
};

