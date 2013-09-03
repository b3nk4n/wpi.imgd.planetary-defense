/* Rocket.cpp */

#include "Rocket.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Position.h"
#include "EventOut.h"
#include "EventCollision.h"
#include "EventDetonation.h"
#include "Circle.h"
#include "Explosion.h"

#define DETONATION_RADIUS 10

/**
 * Creates a new rocket instance.
 */
Rocket::Rocket(Position heroPos)
    : Projectile(heroPos, "rocket")
{
	// set object type
	setType("Rocket");

	// set vertical speed
	setXVelocity(0.75);

	// set starting location, based on hero position
	Position tempPos(heroPos.getX() + 4, heroPos.getY());
	setPosition(tempPos);
}

/**
 * Is called when the rocket is hitting something.
 */
 void Rocket::hit(EventCollision *p_collisionEvent)
 {
	if (p_collisionEvent->getObject1()->getType() == "Powerup" ||
 		p_collisionEvent->getObject2()->getType() == "Powerup")
 		return;

	WorldManager &worldManager = WorldManager::getInstance();
	Position tempPos(getPosition().getX() + 2, getPosition().getY());
	
	Circle detonationCircle(tempPos, DETONATION_RADIUS);
	EventDetonation detonationEvent(detonationCircle);
	worldManager.onEvent(&detonationEvent);
	
	Explosion *explosion = new Explosion(EXPLOSION_LARGE);
	explosion->setPosition(this->getPosition());
	
 	worldManager.markForDelete(this);
 }
 