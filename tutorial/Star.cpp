/* Star.cpp */

#include <stdlib.h>
#include "Star.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "EventOut.h"

/**
 * Creates a new start instance.
 */
Star::Star(void)
{
	setType("Star");
	setSolidness(SPECTRAL);

	randomXVelocity();

	// set stars in the background
	setAltitude(0);

	// set starts persistent to stay alive after changing level
	setPersistence(true);

	// set random position
	WorldManager &worldManager = WorldManager::getInstance();
	Position tempPos(random() % worldManager.getBoundary().getHorizontal(),
		random() % worldManager.getBoundary().getVertical());
	setPosition(tempPos);
}

/**
 * Renders the star.
 */
void Star::draw(void)
{
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	if (getXVelocity() < 0.5)
		graphicsManager.drawCh(getPosition(), SLOW_STAR_CHAR);
	else
		graphicsManager.drawCh(getPosition(), FAST_STAR_CHAR);
}

/**
 * Handles the events of the star.
 */
int Star::eventHandler(Event *p_event)
{
	if (p_event->getType() == OUT_EVENT)
	{
		out();
		return 1;
	}

	return 0;
}

/**
 * Is called when the star leaves the game world.
 */
void Star::out()
{
	// set random position on the right side of the screen
	WorldManager &worldManager = WorldManager::getInstance();
	Position tempPos(worldManager.getBoundary().getHorizontal() + random() % 20,
		random() % worldManager.getBoundary().getVertical());
	setPosition(tempPos);

	randomXVelocity();
}

/**
 * Sets up a random velocity.
 */
void Star::randomXVelocity(void)
{
	setXVelocity(-1.0 / (random() % 10 + 1));
}