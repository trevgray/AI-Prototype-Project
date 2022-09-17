#pragma once
#include "Body.h"
#include "KinematicSteeringOutput.h"
class StaticBody : public Body {
public:
	StaticBody() : Body {} {}
	StaticBody(Vec3 position_, float orientation_, float maxSpeed_, float maxRotation_) : Body{position_, Vec3(), Vec3(), 1.0f, 1.0f, orientation_, 0.0f, 0.0f, maxSpeed_, 0.0f, maxRotation_, 0.0f} {}
	void Update(float deltaTime, KinematicSteeringOutput* steering);
	void newOrientation();
};

