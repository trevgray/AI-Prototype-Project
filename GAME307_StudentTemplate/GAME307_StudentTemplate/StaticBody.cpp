#include "StaticBody.h"

void StaticBody::Update(float deltaTime, KinematicSteeringOutput* steering) {
    Body::Update(deltaTime);
    newOrientation();


    // TODO Body reaching edge of scene needs to be handled somewhere
    // especially if implementing the flee behaviour

    // Adjust velocity and rotation according to steering input
    if (steering)
    {
        vel = steering->velocity;
        
        rotation = steering->rotation;

        if (VMath::mag(vel) > maxSpeed) {
            vel = VMath::normalize(vel) * maxSpeed;
        }

        if (rotation > maxRotation) {
            rotation = maxRotation;
        }
    }
}

void StaticBody::newOrientation() {
    if (VMath::mag(vel) > 0.0f) {
        orientation = atan2(-vel.y, vel.x);
    }
}