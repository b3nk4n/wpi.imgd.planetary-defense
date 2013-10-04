/* Laser.h */

#ifndef LASER_H
#define LASER_H

#include "Projectile.h"

class Laser : public Projectile
{
protected:
	/**
	 * Is called when the laser is hitting something.
	 */
    void hit(EventCollision * p_collisionEvent);
public:
	/**
	 * Creates a new laser instance.
	 */
    Laser(Position heroPos);
};

#endif
