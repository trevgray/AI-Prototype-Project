#include "Graph.h"

Graph::Graph() {
	
}

Graph::~Graph() {}

bool Graph::OnCreate(std::vector<Node*> nodes_) {
	//ASSUMPTION: node_ vector has the node with label "i" in the "i" position of the vector

	//given a list of nodes
	//initialize a matrix of costs
	//with 0.0 weights
	int numNodes = nodes_.size();
	cost.resize(numNodes);

	for (int i = 0; i < numNodes; i++) {
		//add the nodes to internal list
		if (i != nodes_[i]->GetLabel()) {
			return false;
		}

		node[i] = nodes_[i];

		//set up the connections
		cost[i].resize(numNodes);
		for (int j = 0; j < numNodes; j++) {
			//initialize connections to other nodes
			cost[i][j] = 0.0f;
		}
	}
	return true;
}

size_t Graph::NumNodes() {
	return node.size();
}

void Graph::addWeightConnection(int fromNode, int toNode, float weight) {
	cost[fromNode][toNode] = weight;
}

std::vector<int> Graph::neighbours(int fromNode) {
	std::vector<int> result = {};
	for (int x = 0; x < NumNodes()/*cost[fromNode] == node.size()*/; x++) {
		if (cost[fromNode][x] > 0.0f) {
			result.push_back(x);
		}
	}
	return result;
}

std::vector<int> Graph::Dijkstra(int startNode, int goalNode) {
	//declare helper variables
	float new_cost;
	int current;

	//declare current NodeAndPriority
	NodeAndPriority* currentNodeAndPriority; //missing node and priority
	currentNodeAndPriority = new NodeAndPriority(startNode, 0.0f);
	//set up priority queue for frontier of nodes
	std::priority_queue<NodeAndPriority, std::deque<NodeAndPriority> , ComparePriority> frontier;
	frontier.push(*currentNodeAndPriority);
	//track solution path
	std::vector<int> cameFrom;
	cameFrom.resize(NumNodes());
	//store cost so far to reach a node
	std::map<int, float> costSoFar;
	costSoFar[startNode] = 0.0f;

	//TODO implement the algorithm

	//start looping through the frontier

	{
		//get the node from the top of the frontier, put it in "current"
		//pop it off
		//if its the goal, then break of the loop
		//for the neighbors of current
		{
			//calculate newCost
			//if neightbor is not in costSoFar or newCost is lower
			{
				//found a better path so update structure (look at pseudocode algorithm)
			}
		}
	}
	return cameFrom;
}
