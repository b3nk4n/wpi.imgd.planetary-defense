/* Projectile.h */

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <string>
#include "Object.h"
#include "EventCollision.h"

using std::string;

class Projectile : public Object
{
protected:
	/**
	 * Is called when bullet has moved outside the world.
	 */
    void out(void);
    /**
     * Is called when a collusion occured.
     */
    virtual void hit(EventCollision * p_collisionEvent) = 0;
public:
	/**
	 * Creates a new bullet instance.
	 */
    Projectile(Position heroPos, string spriteName);
    /**
	 * Handles the bullet events.
	 */
    int eventHandler(Event *p_event);
};

#endif
