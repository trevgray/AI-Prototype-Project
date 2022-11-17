#include "ConditionInRange.h"
#include "VMath.h"
#include "Character.h"

bool ConditionInRange::Test() {
    float thresholdDistance = 2.0f;
    if (MATH::VMath::distance(owner->GetPlayerPos(), owner->GetPos()) < thresholdDistance) {
        return true;
    }
    return false;
}
