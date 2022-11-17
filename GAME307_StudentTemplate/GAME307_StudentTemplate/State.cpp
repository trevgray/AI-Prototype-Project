#include "State.h"

State::State() {

}

State::~State() {

}

void State::AddTransition(Transition* transition) {
	transitions.push_back(transition);
}
