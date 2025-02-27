#pragma once
#include "DecisionTreeNode.h"

class Decision : public DecisionTreeNode {
protected:
	DecisionTreeNode* trueNode;
	DecisionTreeNode* falseNode;
public:
	virtual DecisionTreeNode* MakeDecision();
	virtual bool TestValue() = 0;
	virtual DecisionTreeNode* GetBranch();
};

