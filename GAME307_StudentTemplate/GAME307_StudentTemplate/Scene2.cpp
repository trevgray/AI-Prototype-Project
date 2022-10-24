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
	int window_w;
	int window_h;
	SDL_GetWindowSize(window, &window_w, &window_h);

	//Matrix4 ndc = MMath::viewportNDC(window_w, window_h);
	//Matrix4 ortho = MMath::orthographic(0.0f, xAxis, 0.0f, yAxis, 0.0f, 1.0f);
	//projectionMatrix = ndc * ortho;
	//inverseProjection = MMath::inverse(projectionMatrix);

	////turn on SDL_imaging
	//IMG_Init(IMG_INIT_PNG);

	////create a tile with a node
	//int cols = ceil(xAxis / tileWidth);
	//int rows = ceil(yAxis / tileHeight);
	//CreateTiles(rows, cols);
	////this createTiles is also going to populate nodes list

	////create graph. an empty graph
	//graph = new Graph();
	//if (!graph->OnCreate(nodes)) {
	//	return false;
	//}

	//CalculateConnectionWeights();

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

	//create graph. an empty graph
	graph = new Graph();
	if (!graph->OnCreate(nodes)) {
		return false;
	}

	//since the nodes are created here, then the scene is responsible for deleting them later
	
	//connections from other nodes to 2
	graph->AddWeightConnection(nodes[0]->GetLabel(), nodes[2]->GetLabel(), 1.0f);
	graph->AddWeightConnection(nodes[1]->GetLabel(), nodes[2]->GetLabel(), 1.0f);
	graph->AddWeightConnection(nodes[3]->GetLabel(), nodes[2]->GetLabel(), 1.0f);
	graph->AddWeightConnection(nodes[4]->GetLabel(), nodes[2]->GetLabel(), 1.0f);
	//connections from 2
	graph->AddWeightConnection(nodes[2]->GetLabel(), nodes[0]->GetLabel(), 1.0f);
	graph->AddWeightConnection(nodes[2]->GetLabel(), nodes[1]->GetLabel(), 1.0f);
	graph->AddWeightConnection(nodes[2]->GetLabel(), nodes[3]->GetLabel(), 1.0f);
	graph->AddWeightConnection(nodes[2]->GetLabel(), nodes[4]->GetLabel(), 1.0f);

	std::vector<int> path;
	int current = 0;

	int goal = 4;

	std::vector<int> cameFrom = graph->AStar(goal, 0);
	while (current != goal) {
		path.push_back(current);
		current = cameFrom[current];
	}

	for (int loop : path) {
		std::cout << loop << std::endl;
	}

	return true;
}

void Scene2::CreateTiles(int rows, int cols) {
	tiles.resize(rows);
	for (int i = 0; i < rows; i++) {
		tiles[i].resize(cols);
	}

	Node* n;
	Tile* t;
	int i, j, label;

	i = 0;
	j = 0;
	label = 0;

	for (float y = 0.5f * tileHeight; y < yAxis; y += tileHeight) {
		//do stuff for a row, where y stays constant
		for (float x = 0.5f * tileWidth; x < xAxis; x += tileWidth) {
			n = new Node(label, Vec3(x, y, 0.0f));
			t = new Tile(n, tileWidth, tileHeight, this);
			n->SetTile(t);
			nodes.push_back(n);
			tiles[i][j] = t;

			label++;
			j++;
		}
		j = 0;
		i++;
	}
}

void Scene2::CalculateConnectionWeights() {
	int rows = tiles.size();
	int cols = tiles[0].size();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//                  i+1,j
			// i, j-1             i,j             i, j+1
			//                  i-1,j

			int fromNodeLabel = tiles[i][j]->GetNode()->GetLabel();

			//left is i,j-1
			if (j > 0) { //because j-1
				int toNodeLabel = tiles[i][j - 1]->GetNode()->GetLabel();
				graph->AddWeightConnection(fromNodeLabel, toNodeLabel, tileWidth);
			}
			//right is i,j+1
			if (j < cols - 1) {
				int toNodeLabel = tiles[i][j + 1]->GetNode()->GetLabel();
				graph->AddWeightConnection(fromNodeLabel, toNodeLabel, tileWidth);
			}
			//top is i+1,j
			if (i < rows - 1) {
				int toNodeLabel = tiles[i + 1][j]->GetNode()->GetLabel();
				graph->AddWeightConnection(fromNodeLabel, toNodeLabel, tileWidth);
			}
			//bottom is i-1,j
			if (i > 0) {
				int toNodeLabel = tiles[i - 1][j]->GetNode()->GetLabel();
				graph->AddWeightConnection(fromNodeLabel, toNodeLabel, tileWidth);
			}
		}
	}
}

void Scene2::OnDestroy() {

}

void Scene2::Update(const float time) {

}

void Scene2::Render() {
	//clear the frame
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	for (int i = 0; i < tiles.size(); i++) {
		for (int j = 0; j < tiles[i].size(); j++) {
			tiles[i][j]->Render();
		}
	}

	//renderer it all
	SDL_RenderPresent(renderer);
}

void Scene2::HandleEvents(const SDL_Event& event) {

}
