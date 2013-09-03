/* BossBullet.cpp */

#include "BossBullet.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Position.h"
#include "EventOut.h"
#include "EventCollision.h"

/**
 * Creates a new bullet instance.
 */
BossBullet::BossBullet(Position bossPos)
    : Projectile(bossPos, "bossbullet")
{
	// set object type
	setType("BossBullet");

	// set vertical speed
	setXVelocity(-1.25);

	// set starting location, based on hero position
	Position tempPos(bossPos.getX() - 16, bossPos.getY());
	setPosition(tempPos);

	setSolidness(SOFT);
}

/**
 * Is called when the bullet is hitting something.
 */
 void BossBullet::hit(EventCollision *p_collisionEvent)
 {
 	if (p_collisionEvent->getObject1()->getType() == "Hero" ||
 		p_collisionEvent->getObject2()->getType() == "Hero")
 	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
	}
 }
 