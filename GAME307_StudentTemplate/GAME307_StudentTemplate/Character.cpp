#include "Character.h"
#include "Seek.h"

bool Character::OnCreate(Scene* scene_)
{
	scene = scene_;

	// Configure and instantiate the body to use for the demo
	if (!body)
	{
		float radius = 0.2;
		float orientation = 0.0f;
		float rotation = 0.0f;
		float angular = 0.0f;
		float maxSpeed = 4.0f;
		float maxAcceleration = 10.0f;
		float maxRotation = 2.0f;
		float maxAngular = 10.0f;
		body = new KinematicBody(
			Vec3(10.0f, 5.0f, 0), Vec3(0, 0, 0), Vec3(0, 0, 0), 1.0f,
			radius,
			orientation,
			rotation,
			angular,
			maxSpeed,
			maxAcceleration,
			maxRotation,
			maxAngular
		);
	}

	if (!body)
	{
		return false;
	}

	return true;
}

bool Character::ReadStateMachineXML(std::string filename) {
	stateMachine = new StateMachine(this);

	State* seekPlayer = new State(STATE::SEEK, ACTION_SET::SEEK);
	State* doNothing = new State(STATE::DO_NOTHING, ACTION_SET::DO_NOTHING);

	Condition* ifInRange = new ConditionInRange(this);
	doNothing->AddTransition(new Transition(ifInRange, seekPlayer));

	Condition* ifOutOfRange = new ConditionOutOfRange(this);
	seekPlayer->AddTransition(new Transition(ifOutOfRange, doNothing));

	stateMachine->SetInitialState(doNothing);

	return true;
}

bool Character::ReadDecisionTreeXML(std::string filename) {
	//lets pretend the XML parsing produced these instances
	DecisionTreeNode* trueNode = new Action(ACTION_SET::SEEK);
	DecisionTreeNode* falseNode = new Action(ACTION_SET::DO_NOTHING);

	DecisionTreeNode* test2 = new InRangeDecision(this, trueNode, falseNode);

	decider = new InRangeDecision(this, test2, falseNode);

	return true;
}

void Character::Update(float deltaTime) 
{
	// create a new overall steering output
	SteeringOutput* steering; //probably do this in oncreate
	steering = new SteeringOutput();

	// set the target for steering; target is used by the steerTo... functions
	// (often the target is the Player)

	if (decider != nullptr) {
		DecisionTreeNode* action = decider->MakeDecision();
		Action* a = dynamic_cast<Action*>(action);
		switch (a->GetValue()) {
		case ACTION_SET::SEEK:
			SteerToSeekPlayer(steering);
			break;
		case ACTION_SET::DO_NOTHING:
			break;
		}
	}

	if (stateMachine != nullptr) {
		stateMachine->Update();
		switch (stateMachine->GetCurrentStateName()) {
		case STATE::SEEK:
			SteerToSeekPlayer(steering);
			break;
		case STATE::DO_NOTHING:
			break;
		}
	}

	// using the target, calculate and set values in the overall steering output

	//SteerToSeekPlayer(steering);

	// apply the steering to the equations of motion
	body->Update(deltaTime, steering); //just call the boy update - then do all the steering update stuff in the steering component update

	// clean up memory
	// (delete only those objects created in this function)
	if (steering) { delete steering; }
}

void Character::SteerToSeekPlayer(SteeringOutput* steering) {
	PlayerBody* target = scene->game->getPlayer(); //probably do this in oncreate

	std::vector<SteeringOutput*> steeringOutputs;
	SteeringBehaviour* steering_algorithm = new Seek(body, target); //probably make a vector of steering behaviours in the constructor
	steeringOutputs.push_back(steering_algorithm->getSteering());

	//add together all steering outputs
	for (unsigned i = 0; i < steeringOutputs.size(); i++) {
		if (steeringOutputs[i]) { //if exists
			*steering += *steeringOutputs[i]; //use the overload in the steering output to add them together - * dereferences a pointer
		}
	}
}

void Character::HandleEvents(const SDL_Event& event)
{
	// handle events here, if needed
}

void Character::render(float scale)
{
	SDL_Renderer* renderer = scene->game->getRenderer();
	Matrix4 projectionMatrix = scene->getProjectionMatrix();

	SDL_Rect square;
	Vec3 screenCoords;
	int    w, h;

	// notice use of "body" in the following
	SDL_QueryTexture(body->getTexture(), nullptr, nullptr, &w, &h);
	w = static_cast<int>(w * scale);
	h = static_cast<int>(h * scale);
	screenCoords = projectionMatrix * body->getPos();
	square.x = static_cast<int>(screenCoords.x - 0.5f * w);
	square.y = static_cast<int>(screenCoords.y - 0.5f * h);
	square.w = w;
	square.h = h;

	// Convert character orientation from radians to degrees.
	float orientation = body->getOrientation() * 180.0f / M_PI;

	SDL_RenderCopyEx(renderer, body->getTexture(), nullptr, &square,
		orientation, nullptr, SDL_FLIP_NONE);
}
