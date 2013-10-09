/*******************************************************************************
 * @file        Laser.h
 * @author      bsautermeister
 * @description Laser that flies through enemies with slight damage.
 ******************************************************************************/

#ifndef __LASER_H__
#define __LASER_H__

#include "Projectile.h"

#define LASER_LIFE_TIME 15

/**
 * Represents a laser.
 */
class Laser : public Projectile
{
private:
    /**
     * The time in steps until the laser delete itself.
     */
    int _timeToLive;

public:
 	/**
	 * Creates a new laser instance.
	 * @param origin The origin of the the shot.
	 * @param target The target where to shot.
	 */
 	Laser(Position origin, Position target);

    /**
     * Handles the laser events.
     */
    virtual int eventHandler(Event *p_event);

 	/**
     * Is called when a collusion occured.
     * @param p_collisionEvent The collision event.
     */
	virtual void onHit(EventCollision *p_collisionEvent);

	/**
     * Is called when a laser reached the target positoin without
     * hitting an enemy.
     */
    virtual void onTargetReached(void);
};

#endif