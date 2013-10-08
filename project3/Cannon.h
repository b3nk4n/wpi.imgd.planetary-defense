/*******************************************************************************
 * @file        Cannon.h
 * @author      bsautermeister
 * @description Cannon bullet that releases a detonation
 *              on hot or reached target.
 ******************************************************************************/

#ifndef __CANNON_H__
#define __CANNON_H__

#include "Projectile.h"

#define DETONATION_DAMAGE 10
#define DETONATION_RADIUS 5.0f

/**
 *Represents a cannon fired bullet with detonation.
 */
class Cannon : public Projectile
{
public:
 	/**
	 * Creates a new cannon instance.
	 * @param origin The origin of the the shot.
	 * @param target The target where to shot.
	 */
 	Cannon(Position origin, Position target);

 	/**
     * Is called when a collusion occured.
     * @param p_collisionEvent The collision event.
     */
	virtual void onHit(EventCollision *p_collisionEvent);

	/**
     * Is called when a projectile reached the target position without
     * hitting an enemy.
     */
    virtual void onTargetReached(void);
};

#endif