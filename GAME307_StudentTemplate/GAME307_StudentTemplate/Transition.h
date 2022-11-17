#pragma once
#include "State.h"
#include "Condition.h"

class Transition {
private:
	//ignoring action for this demo
	State* targetState;
	Condition* condition;
public:
	Transition(Condition* condition_, State* targetState_);
	~Transition();
	bool IsTriggered();
	State* GetTargetState() { return targetState; }
};