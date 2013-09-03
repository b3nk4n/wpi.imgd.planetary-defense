/* Bullet.h */

#ifndef BULLET_H
#define BULLET_H

#include "Projectile.h"

class Bullet : public Projectile
{
protected:
	/**
	 * Is called when the bullet is hitting something.
	 */
	void hit(EventCollision * p_collisionEvent);
public:
	/**
	 * Creates a new bullet instance.
	 */
	Bullet(Position heroPos);
};

#endif
