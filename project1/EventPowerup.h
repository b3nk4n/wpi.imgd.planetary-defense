/* EventPowerup.h */

#ifndef EVENT_POWERUP_H
#define EVENT_POWERUP_H

#include <string>
#include "Event.h"

using std::string;

#define POWERUP_EVENT "powerup"

class EventPowerup : public Event
{
protected:
	string powerupId;
public:
	/**
	 * Creates a new powerup event.
	 */
	EventPowerup(string powerupId);
	/**
	 * Gets the powerup id.
	 */
	string getPowerupId();
};

#endif
