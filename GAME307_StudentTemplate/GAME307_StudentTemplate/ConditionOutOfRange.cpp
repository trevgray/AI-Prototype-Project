#include "ConditionOutOfRange.h"
#include "VMath.h"
#include "Character.h"

bool ConditionOutOfRange::Test() {
    float thresholdDistance = 3.5f;
    if (MATH::VMath::distance(owner->GetPlayerPos(), owner->GetPos()) > thresholdDistance) {
        return true;
    }
    return false;
}
