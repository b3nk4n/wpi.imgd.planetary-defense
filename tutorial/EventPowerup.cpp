/* EventPowerup.cpp */

#include "EventPowerup.h"

/**
 * Creates a new powerup event.
 */
EventPowerup::EventPowerup(string powerupId)
{
	setType(POWERUP_EVENT);
	this->powerupId = powerupId;
}

/**
 * Gets the powerup id.
 */
string EventPowerup::getPowerupId()
{
	return this->powerupId;
}