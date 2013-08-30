/* Bullet.cpp */

#include "Bullet.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Position.h"
#include "EventOut.h"
#include "EventCollision.h"

/**
 * Creates a new bullet instance.
 */
Bullet::Bullet(Position heroPos)
{
	// required dragonfly managers
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();
	
	// setup bullet sprite
	Sprite *p_tempSprite = resourceManager.getSprite("bullet");
	if (!p_tempSprite)
	{
		logManager.writeLog(
			"Bullet::Bullet(): Sprite %s not found",
			"bullet");
	}
	else
	{
		setSprite(p_tempSprite);
		setSpriteSlowdown(5);
	}

	// set object type
	setType("Bullet");

	// set vertical speed
	setXVelocity(1);

	// set starting location, based on hero position
	Position tempPos(heroPos.getX() + 3, heroPos.getY());
	setPosition(tempPos);
}

/**
 * Handles the bullet events.
 */
int Bullet::eventHandler(Event *p_event)
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
 * Is called when bullet has moved outside the world.
 */
void Bullet::out()
{
	WorldManager &worldManager = WorldManager::getInstance();
	worldManager.markForDelete(this);
}

/**
 * Is called when the bullet is hitting something.
 */
 void Bullet::hit(EventCollision *p_collisionEvent)
 {
 	WorldManager &worldManager = WorldManager::getInstance();
 	worldManager.markForDelete(p_collisionEvent->getObject1());
 	worldManager.markForDelete(p_collisionEvent->getObject2());
 }