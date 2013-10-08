/*******************************************************************************
* @file        EventDetonation.h
* @author      bsautermeister
* @description Detonation event, which is fired when a detonatoin occured.
******************************************************************************/

#ifndef EVENT_DETONATION_H
#define EVENT_DETONATION_H

#include "Event.h"
#include "Circle.h"

#define DETONATION_EVENT "detonation"

/**
 * The detonation event for splash damage.
 */
class EventDetonation : public Event
{
private:
	/**
	 * The detonation circle.
	 */
	Circle _circle;

	/**
	 * The detonation damage.
	 */
	int _damage;

public:
	/**
	 * Creates a new detonation event.
	 * @param circle The detonation circle.
	 * @param damage The damage of the detonation.
	 */
	EventDetonation(Circle circle, int damage);
	/**
	 * Gets the detonation circle.
	 * @return The detonation circle.
	 */
	Circle getCircle(void);

	/**
	 * Gets the detonation damage.
	 * @return The detonation damage.
	 */
	int getDamage(void);
};

#endif
