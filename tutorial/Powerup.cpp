/* Powerup.cpp */

#include <string>
#include "Powerup.h"
#include "EventCollision.h"
#include "EventStep.h"
#include "EventOut.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Hero.h"
#include "ResourceManager.h"

using std::string;

/**
 * Creates a new powerup instance.
 */
Powerup::Powerup(string spriteName, string powerupId, Position spawnPosition)
{
	// required dragonfly managers
    LogManager &logManager = LogManager::getInstance();
    ResourceManager &resourceManager = ResourceManager::getInstance();
    
    // setup bullet sprite
    Sprite *p_tempSprite = resourceManager.getSprite(spriteName);
    if (!p_tempSprite)
    {
        logManager.writeLog(
            "Powerup::Powerup(): Sprite %s not found",
            spriteName.c_str());
    }
    else
    {
        setSprite(p_tempSprite);
        setSpriteSlowdown(5);
    }

    setType("Powerup");
    
    this->powerupId = powerupId;
    
    setXVelocity(-0.25);
	setSolidness(SOFT);
	setPosition(spawnPosition);
}

/**
 * Handles the powerup events.
 */
int Powerup::eventHandler(Event *p_event)
{
    if (p_event->getType() == OUT_EVENT)
    {
        out();
        return 1;
    }

    if (p_event->getType() == COLLISION_EVENT)
    {
        EventCollision *p_collisionEvent = static_cast<EventCollision *>(p_event);
        hit(p_collisionEvent);
        return 1;
    }

    return 0;
}

/**
 * Is called when a collision occured.
 */
void Powerup::hit(EventCollision *p_collisionEvent)
{
	if (p_collisionEvent->getObject1()->getType() == "Hero" ||
		p_collisionEvent->getObject2()->getType() == "Hero")
	{
		collect();
	}
}

/**
 * Is called when powerup has moved outside the world.
 */
void Powerup::out(void)
{
    WorldManager &worldManager = WorldManager::getInstance();
    worldManager.markForDelete(this);
}

/**
 * Raises the powerup event when player collected the power up.
 */
void Powerup::collect(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	
	EventPowerup eventPowerup(this->getPowerupId());
	worldManager.onEvent(&eventPowerup);
	
	worldManager.markForDelete(this);
}

/**
 * Gets the powerup id.
 */
string Powerup::getPowerupId()
{
	return this->powerupId;
}