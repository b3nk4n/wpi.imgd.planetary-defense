/* Bullet.h */

#ifndef BULLET_H
#define BULLET_H

#include "Projectile.h"

class Bullet : public Projectile
{
protected:
	void hit(EventCollision * p_collisionEvent);
public:
	Bullet(Position heroPos);
};

#endif