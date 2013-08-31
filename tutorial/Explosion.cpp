/* Explosion.cpp */

#include "Explosion.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "EventStep.h"

/**
 * Creates a new explosion instance.
 */
Explosion::Explosion(void)
{
	// required dragonfly managers
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();
	
	// setup hero sprite
	Sprite *p_tempSprite = resourceManager.getSprite("explosion");
	if (!p_tempSprite)
	{
		logManager.writeLog(
			"Explosion::Explosion(): Sprite %s not found",
			"explosion");
	}
	else
	{
		setSprite(p_tempSprite);
	}

	// register for events
	registerInterest(STEP_EVENT);

	// set object type
	setType("Explosion");

	timeToLive = getSprite()->getFrameCount();

	// disable collision detection
	setSolidness(SPECTRAL);
}

/**
 * Handles the explosions events.
 */
int Explosion::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
		step();
		return 1;
	}

	return 0;
}

/**
 * Updtates the explosion.
 */
void Explosion::step(void)
{
	--timeToLive;

	if (timeToLive <= 0)
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
	}
}