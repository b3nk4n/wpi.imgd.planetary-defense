/* Powerup.h */

#ifndef POWERUP_H
#define POWERUP_H

#include <string>
#include "Object.h"
#include "EventCollision.h"

using std::string;

class Powerup : public Object
{
private:
	string powerupId;
	
protected:
	/**
	 * Raises the powerup event when player collected the power up.
	 */
	void collect();
	/**
	 * Is called when a collision occured.
	 */
	void hit(EventCollision * p_collisionEvent);
	/**
	 * Is called when powerup has moved outside the world.
	 */
	void out(void);
	
public:
	/**
	 * Creates a new powerup instance.
	 */
	Powerup(string spriteName, string powerupId, Position spawnPosition);
	/**
	 * Handles the powerup events.
	 */
	int eventHandler(Event *p_event);
	/**
	 * Gets the powerup id.
	 */
	string getPowerupId(void);
};

#endif
