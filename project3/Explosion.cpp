/*******************************************************************************
 * @file        Explosion.cpp
 * @author      bsautermeister
 * @description The explosion sprite effect base class.
 ******************************************************************************/

#include "Explosion.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "EventStep.h"

/**
 * Creates a new explosion instance.
 * @param spriteName The name of the sprite resource.
 * @param slowdown The animation slowdown to adjust the effect speed.
 */
Explosion::Explosion(string spriteName, int slowdown)
{
	// required dragonfly managers
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	setType(TYPE_EXPLOSION);
	setSolidness(SPECTRAL);
	
	// setup explosion sprite
	Sprite *p_tempSprite = resourceManager.getSprite("explosion_large");
	if (!p_tempSprite)
	{
		logManager.writeLog(LOG_ERROR,
			"Explosion::Explosion()",
			"Sprite %s with type not found.\n",
			spriteName.c_str());
	}
	else
	{
		setSprite(p_tempSprite);
		setSpriteSlowdown(slowdown);
		_timeToLive = getSprite()->getFrameCount() * slowdown;
	}

	// register for events
	registerInterest(STEP_EVENT);
}

/**
 * Handles the explosions events.
 */
int Explosion::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
		--_timeToLive;

		if (_timeToLive <= 0)
		{
			WorldManager &worldManager = WorldManager::getInstance();
			worldManager.markForDelete(this);
		}

		return 1;
	}

	return 0;
}
