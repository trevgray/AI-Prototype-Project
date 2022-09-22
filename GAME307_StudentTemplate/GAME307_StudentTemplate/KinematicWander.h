#pragma once
#include "KinematicSteeringOutput.h"
#include <random>
#include "Body.h"


class KinematicWander {
private:
	KinematicSteeringOutput* result;
	Body* character;
	Body* target;
	float maxRotation;

	float RandomBinomial();
public:
	KinematicWander(Body* character_, Body* target_, float maxRotation_);
	~KinematicWander();
	KinematicSteeringOutput* GetSteering();
};

