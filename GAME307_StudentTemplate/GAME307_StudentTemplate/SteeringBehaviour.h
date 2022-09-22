#pragma once

#include "VMath.h"
#include "KinematicBody.h"
#include "SteeringOutput.h"

//abstract class
//steering behaviour subclasses will inherit from here and
//must implement the getSteering function

class SteeringBehaviour {
protected:
	SteeringOutput* result;
	Body* character;
public:
	SteeringBehaviour();
	virtual SteeringOutput* getSteering() = 0;
	virtual ~SteeringBehaviour() {
		if (result) { delete result; }
	}
};

