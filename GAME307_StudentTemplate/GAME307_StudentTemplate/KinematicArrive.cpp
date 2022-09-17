#include "KinematicArrive.h"

KinematicArrive::KinematicArrive(Body* character_, Body* target_, float radius_, float timeToTarget_) {
	character = character_;
	target = target_;
	result = new KinematicSteeringOutput();
	radius = radius_;
	timeToTarget = timeToTarget_;
}

KinematicArrive::~KinematicArrive()
{
	if (result) { delete result; }
}

KinematicSteeringOutput* KinematicArrive::GetSteering()
{
	result->velocity = target->getPos() - character->getPos();
	if (VMath::mag(result->velocity) <= 0) {
		result->velocity = Vec3();
	}
	else if (VMath::mag(result->velocity) < radius) {
		result->velocity /= timeToTarget;
		//std::cout << "inside circle\n";
	}
	else {
		result->velocity = VMath::normalize(result->velocity);
		result->velocity *= character->getMaxSpeed();
	}

	return result;
}

/*KinematicSteeringOutput* KinematicArrive::GetSteering()
{
	result->velocity = target->getPos() - character->getPos();
	if (VMath::mag(result->velocity) <= radius) {
		result->velocity = Vec3();
		return result;
	}

	// clip to max speed
	result->velocity /= timeToTarget;

	if (VMath::mag(result->velocity) > character->getMaxSpeed()) {
		result->velocity = VMath::normalize(result->velocity);
		result->velocity *= character->getMaxSpeed();
	}

	return result;
}*/