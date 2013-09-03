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
    : Projectile(heroPos, "bullet")
{
	// set object type
	setType("Bullet");

	// set vertical speed
	setXVelocity(1.25);

	// set starting location, based on hero position
	Position tempPos(heroPos.getX() + 3, heroPos.getY());
	setPosition(tempPos);
}

/**
 * Is called when the bullet is hitting something.
 */
 void Bullet::hit(EventCollision *p_collisionEvent)
 {
 	if (p_collisionEvent->getObject1()->getType() == "Powerup" ||
 		p_collisionEvent->getObject2()->getType() == "Powerup")
 		return;
 	
	WorldManager &worldManager = WorldManager::getInstance();
	worldManager.markForDelete(this);
 }
 