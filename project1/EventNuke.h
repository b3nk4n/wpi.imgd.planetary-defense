/* EventNuke.h */

#ifndef EVENT_NUKE_H
#define EVENT_NUKE_H

#include "Event.h"

#define NUKE_EVENT "nuke"

class EventNuke : public Event
{
public:
	/**
	 * Creates a new nuke event.
	 */
	EventNuke(void);
};

#endif
