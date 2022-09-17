#pragma once
#include "KinematicSteeringOutput.h"
#include "Body.h"

class KinematicArrive {
private:
	KinematicSteeringOutput* result;
	Body* character;
	Body* target;
	float radius;
	float timeToTarget;
public:
	KinematicArrive(Body* character_, Body* target_, float radius_, float timeToTarget);
	~KinematicArrive();
	KinematicSteeringOutput* GetSteering();
};

