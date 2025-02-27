#pragma once

#include "Scene.h"
#include "Graph.h"
#include "Tile.h"

class Scene2 : public Scene {
private:
	SDL_Window* window;
	float xAxis = 25.0f;
	float yAxis = 15.0f;
	SDL_Renderer* renderer;
	Matrix4 projectionMatrix;
	Matrix4     inverseProjection;

	Graph* graph;
	std::vector<Node*> nodes;

	std::vector<std::vector<Tile*>> tiles;
	float tileWidth = 2.5f;
	float tileHeight = 1.5f;

	void CreateTiles(int rows, int cols);
	void CalculateConnectionWeights();
public:
	Scene2(SDL_Window* sdlWindow, GameManager* game_);
	~Scene2();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
	float getxAxis() { return xAxis; }
	float getyAxis() { return yAxis; }
	SDL_Window* getWindow() { return window; }
	Matrix4 getProjectionMatrix() { return projectionMatrix; }
	Matrix4 getInverseMatrix() { return inverseProjection; }
};

