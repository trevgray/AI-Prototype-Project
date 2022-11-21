#include "State.h"

State::State() : action(ACTION_SET::DO_NOTHING) {

}

State::~State() {

}

void State::AddTransition(Transition* transition) {
	transitions.push_back(transition);
}
