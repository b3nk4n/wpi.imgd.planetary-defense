/* Star.cpp */

#include <stdlib.h>
#include "Star.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "EventStep.h"

/**
 * Creates a new start instance.
 */
Star::Star(void)
{
	setType("Star");
	setSolidness(SPECTRAL);

	// set stars in the background
	setAltitude(MIN_ALTITUDE);

	// set random position
	setPosition(Position(-1, -1));

	registerInterest(STEP_EVENT);
}

/**
 * Renders the star.
 */
void Star::draw(void)
{
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	if (getVelocityX() > -0.5)
		graphicsManager.drawChar(getPosition(), SLOW_STAR_CHAR, COLOR_YELLOW);
	else
		graphicsManager.drawChar(getPosition(), FAST_STAR_CHAR, COLOR_YELLOW);
}

/**
 * Handles the events of the star.
 */
int Star::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
		if (getPosition().getX() < _bounds.getCorner().getX())
			resetRight();
		return 1;
	}

	return 0;
}

/**
 * Is called when the star should reposition itself.
 */
void Star::resetRight()
{
	// set random position on the right side of the bounding box
	Position tempPos(_bounds.getCorner().getX() + _bounds.getHorizontal(),
		_bounds.getCorner().getY() + random() % (_bounds.getVertical()));
	setPosition(tempPos);

	// random speed
	setVelocityX(-0.5 / (random() % 10 + 1));
}

/**
 * Is called when the star should reposition itself.
 */
void Star::reset()
{
	// set random position on the right side of the bounding box
	Position tempPos(_bounds.getCorner().getX() + random() % (_bounds.getHorizontal()),
		_bounds.getCorner().getY() + random() % (_bounds.getVertical()));
	setPosition(tempPos);

	// random speed
	setVelocityX(-0.5 / (random() % 10 + 1));
}

/**
 * Sets the bounds of the star to move.
 */
void Star::setBounds(Box bounds)
{
	_bounds = bounds;

	reset();
}
