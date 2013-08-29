/* Saucer.cpp */

#include <stdlib.h>
#include "Saucer.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "EventOut.h"

/**
 * Creates a new saucer instance.
 */
Saucer::Saucer()
{
	// required dragonfly managers
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();
	
	// setup saucer sprite
	Sprite *p_temp_sprite = resourceManager.getSprite("saucer");
	if (!p_temp_sprite)
	{
		logManager.writeLog(
			"Saucer::Saucer(): Sprite %s not found",
			"saucer");
	}
	else
	{
		setSprite(p_temp_sprite);
		setSpriteSlowdown(4);
	}

	// set object type
	setType("Saucer");

	// set vertical speed
	setXVelocity(-0.25); // 1/4 space per frames

	// set starting location
	moveToStart();
}

/**
 * Moves the saucer.
 */
void Saucer::move(void)
{

}

/**
 * Handles the events.
 */
int Saucer::eventHandler(Event *p_e)
{
	if (p_e->getType() == OUT_EVENT)
	{
		out();
		return 1;
	}

	return 0;
}

/**
 * Checks and handles if the saucer is out of the left side of screen.
 */
void Saucer::out()
{
	if (getPosition().getX() >= 0)
		return;

	moveToStart();
}

/**
 * Moves the saucer back to the start position.
 */
void Saucer::moveToStart()
{
	WorldManager &worldManager = WorldManager::getInstance();

	int worldHorizontal = worldManager.getBoundary().getHorizontal();
	int worldVertical = worldManager.getBoundary().getVertical();
	Position tempPos(worldHorizontal + random() % worldHorizontal + 3,
		random() % (worldVertical - 1) + 1);
	setPosition(tempPos);

	worldManager.moveObject(this, tempPos);
}
