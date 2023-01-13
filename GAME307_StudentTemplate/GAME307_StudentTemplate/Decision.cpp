#include "Decision.h"

DecisionTreeNode* Decision::MakeDecision() {
	DecisionTreeNode* branch = GetBranch();
	return branch->MakeDecision();
}

DecisionTreeNode* Decision::GetBranch() {
	if (TestValue()) {
		return trueNode;
	}
	return falseNode;
}
