#pragma once
#include "Decision.h"

class InRangeDecision : public Decision {
public:
	InRangeDecision(Character* owner_, DecisionTreeNode* trueNode_, DecisionTreeNode* falseNode_) {
		owner = owner_;
		trueNode = trueNode_;
		falseNode = falseNode_;
	}
	bool TestValue() override;
};

