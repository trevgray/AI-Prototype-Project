#pragma once
#include "Condition.h"

class ConditionOutOfRange : public Condition {
private:

public:
	ConditionOutOfRange(Character* owner_) : Condition{ owner_ } {

	}
	bool Test();
};

