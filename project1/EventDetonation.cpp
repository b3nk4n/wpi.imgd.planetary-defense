/* EventDetonation.cpp */

#include "EventDetonation.h"

/**
 * Creates a new detonation event.
 */
EventDetonation::EventDetonation(Circle circle)
{
	setType(DETONATION_EVENT);
	this->circle = circle;
}

/**
 * Gets the detonation circle.
 */
Circle EventDetonation::getCircle(void)
{
	return this->circle;
}
