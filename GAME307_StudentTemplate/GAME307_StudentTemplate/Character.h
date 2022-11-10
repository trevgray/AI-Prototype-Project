#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>

#include "Scene.h"
#include "KinematicBody.h"
#include "SteeringBehaviour.h"

#include "Decision.h" //which includes DecisionTreeNode.h
#include "InRangeDecision.h"
#include "Action.h"

using namespace std;

class Character
{
private:
	class KinematicBody* body;
	class Scene* scene;

	DecisionTreeNode* decider;

public:
	Character()
	{
		body = NULL;
		scene = NULL;
	};
	// TODO add constructor that takes parameters for the body
	~Character() 
	{
		if (body) delete body;
	};
	bool OnCreate(Scene* scene_);
	void OnDestroy() {};
	
	void setTexture(SDL_Texture* texture_) 
	{
		body->setTexture(texture_); 
	}

	void Update(float time);
	void SteerToSeekPlayer(SteeringOutput* steering);
	void HandleEvents(const SDL_Event& event);
	void render(float scale = 1.0f);

	KinematicBody* GetBody() { return body; }
	Vec3 GetPos() { return body->getPos(); }
	Vec3 GetPlayerPos() { return scene->game->getPlayer()->getPos(); }
};

#endif

