/*******************************************************************************
 * @file        EventStep.cpp
 * @author      bsautermeister
 * @description Step event class to notify other game objects to update their
 *              state for the next frame rendering.
 ******************************************************************************/

#include "EventStep.h"

/**
 * Creates a new step event instance.
 */
EventStep::EventStep(void)
{
	setType(STEP_EVENT);
}
