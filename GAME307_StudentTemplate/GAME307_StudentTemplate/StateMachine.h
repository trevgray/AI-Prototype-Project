#pragma once
//#include "Character.h"
class Character;
#include "State.h"
#include "Transition.h"
#include "Condition.h"

#include "ConditionInRange.h"
#include "ConditionOutOfRange.h"

class StateMachine {
private:
	State* initialState;
	State* currentState;
	Character* owner;
public:
	StateMachine(Character* owner_) { owner = owner_; }
	~StateMachine();
	void SetInitialState(State* initial_);
	void Update();

	STATE GetCurrentStateName() { return currentState->GetName(); }
};