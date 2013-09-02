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
	EventPowerup(string powerupId);
	string getPowerupId();
};

#endif