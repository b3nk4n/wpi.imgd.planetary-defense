/* BossBullet.h */

#ifndef BOSS_BULLET_H
#define BOSS_BULLET_H

#include "Projectile.h"

class BossBullet : public Projectile
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
	BossBullet(Position bossPos);
};

#endif