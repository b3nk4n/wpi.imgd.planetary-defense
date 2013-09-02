/* Rocket.h */

#ifndef ROCKET_H
#define ROCKET_H

#include "Projectile.h"

class Rocket : public Projectile
{
protected:
	void hit(EventCollision * p_collisionEvent);
	
public:
	Rocket(Position heroPos);
};

#endif