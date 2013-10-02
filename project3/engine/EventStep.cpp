/*******************************************************************************
 * @file        EventStep.cpp
 * @author      bsautermeister
 * @description Step event class to notify other game objects to update their
 *              state for the next frame rendering.
 ******************************************************************************/

#include "EventStep.h"

/**
 * Creates a new step event instance.
 * @param delta the time delta of the last frame step in seconds.
 */
EventStep::EventStep(float delta)
{
	setType(STEP_EVENT);
	_delta = delta;
}

/**
 * Gets the delta of the last frame step in seconds.
 * @return Returns the last step delta in seconds.
 */

float EventStep::getDelta(void)
{
	return _delta;
}
