/*******************************************************************************
* @file        EventDetonation.cpp
* @author      bsautermeister
* @description Detonation event, which is fired when a detonatoin occured.
******************************************************************************/

#include "EventDetonation.h"

/**
 * Creates a new detonation event.
 * @param circle The detonation circle.
 */
EventDetonation::EventDetonation(Circle circle, int damage)
{
	setType(DETONATION_EVENT);
	_circle = circle;
	_damage = damage;
}
/**
 * Gets the detonation circle.
 * @return The detonation circle.
 */
Circle EventDetonation::getCircle(void)
{
	return _circle;
}

/**
 * Gets the detonation damage.
 * @return The detonation damage.
 */
int EventDetonation::getDamage(void)
{
	return _damage;
}
