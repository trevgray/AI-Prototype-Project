#include "Scene2.h"

Scene2::Scene2(SDL_Window* sdlWindow_, GameManager* game_) {
	window = sdlWindow_;
	game = game_;
	renderer = SDL_GetRenderer(window);
}

Scene2::~Scene2() {
	if (graph) { delete graph; }
}

bool Scene2::OnCreate() {
	//let's set up a graph and test it out
	//      0
	//      |
	// 1----2----3
	//      |
	//      4

	int count = 5;
	nodes.resize(count);

	//create nodes
	for (int x = 0; x < count; x++) {
		nodes[x] = new Node(x); //create 5 nodes labeled 1,2,3,4,5
	}
	//since the nodes are created here, then the scene is responsible for deleting them later

	//create graph. an empty graph
	graph = new Graph();
	if (!graph->OnCreate(nodes)) {
		return false;
	}

	//connections from other nodes to 2
	graph->addWeightConnection(nodes[0]->GetLabel(), nodes[2]->GetLabel(), 1.0f);
	graph->addWeightConnection(nodes[1]->GetLabel(), nodes[2]->GetLabel(), 1.0f);
	graph->addWeightConnection(nodes[3]->GetLabel(), nodes[2]->GetLabel(), 1.0f);
	graph->addWeightConnection(nodes[4]->GetLabel(), nodes[2]->GetLabel(), 1.0f);
	//connections from 2
	graph->addWeightConnection(nodes[2]->GetLabel(), nodes[0]->GetLabel(), 1.0f);
	graph->addWeightConnection(nodes[2]->GetLabel(), nodes[1]->GetLabel(), 1.0f);
	graph->addWeightConnection(nodes[2]->GetLabel(), nodes[3]->GetLabel(), 1.0f);
	graph->addWeightConnection(nodes[2]->GetLabel(), nodes[4]->GetLabel(), 1.0f);

	for (int n : graph->neighbours(2)) {
		std::cout << "node " << n << std::endl;
	}

	return true;
}

void Scene2::OnDestroy() {

}

void Scene2::Update(const float time) {

}

void Scene2::Render() {

}

void Scene2::HandleEvents(const SDL_Event& event) {

}
