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
Bullet::Bullet(Position hero_pos)
{
	// required dragonfly managers
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();
	
	// setup bullet sprite
	Sprite *p_temp_sprite = resourceManager.getSprite("bullet");
	if (!p_temp_sprite)
	{
		logManager.writeLog(
			"Bullet::Bullet(): Sprite %s not found",
			"bullet");
	}
	else
	{
		setSprite(p_temp_sprite);
		setSpriteSlowdown(5);
	}

	// set object type
	setType("Bullet");

	// set vertical speed
	setXVelocity(1);

	// set starting location, based on hero position
	Position tempPos(hero_pos.getX() + 3, hero_pos.getY());
	setPosition(tempPos);
}

/**
 * Handles the bullet events.
 */
int Bullet::eventHandler(Event *p_e)
{
	if (p_e->getType() == OUT_EVENT)
	{
		out();
		return 1;
	}

	if (p_e->getType() == COLLISION_EVENT)
	{
		EventCollision *p_collision_event = static_cast<EventCollision *>(p_e);
		hit(p_collision_event);
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
 void Bullet::hit(EventCollision *p_collision_event)
 {
 	WorldManager &worldManager = WorldManager::getInstance();
 	worldManager.markForDelete(p_collision_event->getObject1());
 	worldManager.markForDelete(p_collision_event->getObject2());
 }