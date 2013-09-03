/* Points.cpp */

#include <stdio.h>
#include "Points.h"
#include "EventStep.h"
#include "GraphicsManager.h"
#include "WorldManager.h"

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

/**
 * Render the score bar.
 */
void Points::draw(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	int startX = getPosition().getX();
	int startY = getPosition().getY();

	if (startX > worldManager.getBoundary().getHorizontal() - 17)
		startX = worldManager.getBoundary().getHorizontal() - 17;

	for (int i = 0; i < getViewString().length(); ++i)
	{
		graphicsManager.drawCh(Position(startX++, startY), getViewString().at(i), getColor());
	}

	graphicsManager.drawCh(Position(startX++, startY), ' ', getColor());
	graphicsManager.drawCh(Position(startX++, startY), ':', getColor());
	graphicsManager.drawCh(Position(startX++, startY), ' ', getColor());

	char buf[10];
	sprintf(buf, "%09d", getValue());
	string score = buf;

	for (int i = 0; i < score.length(); ++i)
	{
		graphicsManager.drawCh(Position(startX++, startY), score.at(i), getColor());
	}
}