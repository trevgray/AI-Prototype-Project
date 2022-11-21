#include "StateMachine.h"
#include <iostream>

StateMachine::~StateMachine() {}

void StateMachine::SetInitialState(State* initial_) {
	initialState = initial_;
	currentState = initialState;
}

void StateMachine::Update() {
	Transition* triggered = nullptr;

	//store first transition that triggers
	for (auto transition : currentState->GetTransitions()) {
		if (transition->IsTriggered()) {
			triggered = transition;
			break;
		}
	}
	if (triggered) {
		State* targetState = triggered->GetTargetState();
		//TODO collect exit actions, transition action, add target state actions
		currentState = targetState;
	}
	currentState->GetAction().MakeDecision();
	//TODO return any actions
	//but simple demo rn
	return;
}
