#pragma once
#include "DecisionTreeNode.h"

enum class ACTION_SET { SEEK = 0, DO_NOTHING };

class Action : public DecisionTreeNode {
private:
	ACTION_SET value;
public:
	Action(ACTION_SET value_) { value = value_; }
	virtual DecisionTreeNode* MakeDecision();
	virtual ACTION_SET GetValue() { return value; }
};