/*******************************************************************************
 * @file        EventSkipTime.h
 * @author      bsautermeister
 * @description User event, which sets the next wave timer to zero.
 ******************************************************************************/

#ifndef __EVENT_SKIP_TIME_H__
#define __EVENT_SKIP_TIME_H__

#include "Event.h"

#define SKIP_TIME_EVENT "skip_time"

/**
 * The skip time event class.
 */
class EventSkipTime : public Event
{
public:
	/**
	 * Creates a new skip time event instance.
	 */
	EventSkipTime(void);
};

#endif
