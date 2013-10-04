/* Rocket.h */

#ifndef ROCKET_H
#define ROCKET_H

#include "Projectile.h"

class Rocket : public Projectile
{
protected:
	/**
	 * Is called when the rocket is hitting something.
	 */
	void hit(EventCollision * p_collisionEvent);
	
public:
	/**
	 * Creates a new rocket instance.
	 */
	Rocket(Position heroPos);
};

#endif
