#pragma once
//#include "Character.h"
class Character;
//abstract class (has a pure virtual function)
class Condition {
protected:
	Character* owner;
public:
	Condition(Character* owner_) { owner = owner_; }
	~Condition();
	virtual bool Test() = 0;
};