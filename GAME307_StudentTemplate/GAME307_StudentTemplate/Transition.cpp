#include "Transition.h"

Transition::Transition(Condition* condition_, State* targetState_) {
	condition = condition_;
	targetState = targetState_;
}

Transition::~Transition() {}

bool Transition::IsTriggered() {
	return condition->Test();
}
