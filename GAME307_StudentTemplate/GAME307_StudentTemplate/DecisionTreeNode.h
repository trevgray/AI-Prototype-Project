#pragma once

//abstract class
//#include "Character.h"

class Character;

class DecisionTreeNode {
protected:
	Character* owner;
public:
	virtual void MakeDecision() = 0;
};