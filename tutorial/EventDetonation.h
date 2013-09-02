/* EventDetonation.h */

#ifndef EVENT_DETONATION_H
#define EVENT_DETONATION_H

#include "Event.h"
#include "Circle.h"

#define DETONATION_EVENT "detonation"

class EventDetonation : public Event
{
private:
	Circle circle;
public:
	EventDetonation(Circle circle);
	Circle getCircle(void);
};

#endif