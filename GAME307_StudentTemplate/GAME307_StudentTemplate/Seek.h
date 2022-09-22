#pragma once
#include "SteeringBehaviour.h"

class Seek : public SteeringBehaviour {
protected:
	Body* target;

public:
	Seek(Body* character_, Body* target_);
	virtual ~Seek();
	SteeringOutput* getSteering();
};

