#include "Seek.h"

Seek::Seek(Body* character_, Body* target_) {
	character = character_;
	target = target_;
}

Seek::~Seek() {
	if (character) { delete character; }
	if (target) { delete target; }
}

SteeringOutput* Seek::getSteering() {
	//get direction to target
	result->linear = target->getPos() - character->getPos();

	//accelerate along this direction
	result->linear = VMath::normalize(result->linear) * character->getMaxAcceleration();

	result->angular = 0.0f;

	return result;
}
