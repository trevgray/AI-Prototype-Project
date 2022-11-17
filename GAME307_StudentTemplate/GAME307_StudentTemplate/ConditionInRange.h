#pragma once
#include "Condition.h"

class ConditionInRange : public Condition {
private:

public:
	ConditionInRange(Character* owner_) : Condition{ owner_ } {

	}

	bool Test();
};

