#include "KinematicBody.h"

void KinematicBody::Update( float deltaTime, SteeringOutput *steering )
{
    // Update position, call Update from parent class
    // Note that would update velocity too, but the acceleration in the member object is 0.0!
    Body::Update( deltaTime );

    // TODO Body reaching edge of scene needs to be handled somewhere
    // especially if implementing the flee behaviour

    // Adjust velocity and rotation according to steering input
    if ( steering )
    {
        accel = steering->linear;
        angular = steering->angular ;
    }
    //clip accel to max
    if (VMath::mag(accel) > maxAcceleration) {
        accel = VMath::normalize(accel) * maxAcceleration;
    }

    //clip angular acceleration to max - angular = angular > maxAngular ? maxAngular : angular;
    if (angular > maxAngular) {
        angular = maxAngular;
    }
}
