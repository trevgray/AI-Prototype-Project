#include "InRangeDecision.h"
#include "Character.h"

#include "VMath.h"

bool InRangeDecision::TestValue() {
	//distance to player is less than some value
	float thresholdDistance = 3.0f;
	
	//how to get player position
	owner->GetPos();

	if (VMath::distance(owner->GetPlayerPos(), owner->GetPos()) < thresholdDistance) {
		std::cout << "TRUE" << std::endl;
		return true;
	}
	std::cout << "FALSE" << std::endl;
	return false;
}
