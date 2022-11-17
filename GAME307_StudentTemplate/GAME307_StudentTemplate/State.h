#pragma once
#include <list>

//#include "Transition.h";
class Transition;

enum class STATE { SEEK = 0, DO_NOTHING };

class State {
private:
	std::list<Transition*> transitions;
	//ignoring Actions for this simple example
	STATE name;
public:
	State(STATE name_) { name = name_; }
	State();
	~State();
	std::list<Transition*> GetTransitions() { return transitions; }
	void AddTransition(Transition* transition);
	STATE GetName() { return name; }
};

