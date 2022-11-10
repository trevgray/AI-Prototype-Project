#pragma once
#include "DecisionTreeNode.h"

class Action : public DecisionTreeNode {
public:
	void MakeDecision() override;
};