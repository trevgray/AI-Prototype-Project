#pragma once
#include "DecisionTreeNode.h"

class Decision : public DecisionTreeNode {
protected:
	DecisionTreeNode* trueNode;
	DecisionTreeNode* falseNode;
public:
	virtual void MakeDecision();
	virtual bool TestValue();
	virtual DecisionTreeNode* GetBranch();
};

