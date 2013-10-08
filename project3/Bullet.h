/*******************************************************************************
 * @file        Bullet.h
 * @author      kcbryant
 * @description Machinegun bullet that hits the enemies with slight damage.
 ******************************************************************************/

#ifndef __BULLET_H__
#define __BULLET_H__

#include "Projectile.h"

/**
 *Represents a machinge gun fired bullet.
 */
class Bullet : public Projectile
{
public:
 	/**
	 * Creates a new bullet instance.
	 * @param origin The origin of the the shot.
	 * @param target The target where to shot.
	 */
 	Bullet(Position origin, Position target);


 	/**
     * Is called when a collusion occured.
     * @param p_collisionEvent The collision event.
     */
	virtual void onHit(EventCollision *p_collisionEvent);

	/**
     * Is called when a projectile reached the target positoin without
     * hitting an enemy.
     */
    virtual void onTargetReached(void);
};

#endif