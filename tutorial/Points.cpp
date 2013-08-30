/* Points.cpp */

#include "Points.h"
#include "EventStep.h"
#include "GraphicsManager.h"

#define STEPS_FOR_ONE_SEC 30

/**
 * Creates a new points instance.
 */
Points::Points(void)
{
	// setup text
	setLocation(TOP_RIGHT);
	setViewString(POINTS_STRING);
	setColor(COLOR_YELLOW);

	// register event handlers
	registerInterest(STEP_EVENT);

	// setup members
	stepCount = 0;
}

/**
 * Handles the occured events.
 */
int Points::eventHandler(Event *p_event)
{
	// check for events of the base class
	if (ViewObject::eventHandler(p_event))
	{
		return 1;
	}

	// check for step events
	if (p_event->getType() == STEP_EVENT)
	{
		++stepCount;

		if (stepCount >= STEPS_FOR_ONE_SEC)
		{
			setValue(getValue() + 1);
			stepCount = 0;
		}
		return 1;
	}

	return 0;
}