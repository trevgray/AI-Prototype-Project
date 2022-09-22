#include "KinematicWander.h"
#include <random>

KinematicWander::KinematicWander(Body* character_, Body* target_, float maxRotation_) {
	character = character_;
	target = target_;
	result = new KinematicSteeringOutput();
	maxRotation = maxRotation_;
}

KinematicWander::~KinematicWander()
{
	if (result) { delete result; }
}

KinematicSteeringOutput* KinematicWander::GetSteering()
{
	//character->setVel(Vec3(character->getVel().x * RandomBinomial(), character->getVel().y * RandomBinomial(), 0.0f));

	return result;
}

//float KinematicWander::RandomBinomial() {
//	/*std::default_random_engine generator;
//	generator.seed((unsigned int)time(NULL));
//	std::binomial_distribution<int> distribution(10000, 0.5);
//	int number = (distribution(generator) / 0.0000001);
//	if (std::rand() <= 0.5) {
//		number = -number;
//	}
//	return number;*/
//
//	//return (distribution(generator) / 0.0000001);
//}