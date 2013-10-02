/*******************************************************************************
 * @file        EventOut.h
 * @author      bsautermeister
 * @description Out event class to notify other game objects to that an object
 *              has left the viewable game field.
 ******************************************************************************/

#ifndef __EVENT_OUT_H__
#define __EVENT_OUT_H__

#include "Event.h"

#define OUT_EVENT "__out__"

/**
 * The out event class.
 */
class EventOut : public Event
{
public:
	/**
	 * Creates a new out event instance.
	 */
	EventOut(void);
};

#endif
