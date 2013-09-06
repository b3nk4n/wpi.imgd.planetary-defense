/*******************************************************************************
 * @file        EventStep.h
 * @author      bsautermeister
 * @description Step event class to notify other game objects to update their
 *              state for the next frame rendering.
 ******************************************************************************/

#ifndef __EVENT_STEP_H__
#define __EVENT_STEP_H__

#include "Event.h"

#define STEP_EVENT "__step__"

/**
 * The step event class.
 */
class EventStep : public Event
{
public:
	/**
	 * Creates a new step event instance.
	 */
	EventStep(void);
};

#endif
