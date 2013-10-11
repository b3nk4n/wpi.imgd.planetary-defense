/*******************************************************************************
 * @file        FragmentationGrenade.h
 * @author      bsautermeister
 * @description Cannon bullet that releases a detonation
 *              on hot or reached target.
 ******************************************************************************/

#ifndef __FRAGMENTATION_GRENADE_H__
#define __FRAGMENTATION_GRENADE_H__

#include "Projectile.h"

#define DETONATION_RADIUS 10.0f

/**
 *Represents a frag fired bullet with detonation.
 */
class FragmentationGrenade : public Projectile
{
public:
 	/**
	 * Creates a new frag instance.
	 * @param origin The origin of the the shot.
	 * @param target The target where to shot.
     * @param firePower The fire power.
	 */
 	FragmentationGrenade(Position origin, Position target, int firePower);

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




