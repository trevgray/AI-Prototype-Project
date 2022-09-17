#include "KinematicSeek.h"

KinematicSeek::KinematicSeek(Body* character_, Body* target_) {
	character = character_;
	target = target_;
	result = new KinematicSteeringOutput();
}

KinematicSeek::~KinematicSeek() {
	if (result) { delete result; }
}

KinematicSteeringOutput* KinematicSeek::GetSteering() {
	result->velocity = target->getPos() - character->getPos();
	
	result->velocity = VMath::normalize(result->velocity);
	result->velocity *= character->getMaxSpeed();

	return result;
}
