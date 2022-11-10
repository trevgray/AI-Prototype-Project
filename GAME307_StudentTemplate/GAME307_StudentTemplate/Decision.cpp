#include "Decision.h"

void Decision::MakeDecision() {
	DecisionTreeNode* branch = GetBranch();
	branch->MakeDecision();
}

bool Decision::TestValue() {
	return false;
}

DecisionTreeNode* Decision::GetBranch() {
	if (TestValue()) {
		return trueNode;
	}
	return falseNode;
}
