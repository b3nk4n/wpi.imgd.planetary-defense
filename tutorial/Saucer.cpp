/* Saucer.cpp */

#include <stdlib.h>
#include "Saucer.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "EventOut.h"
#include "EventCollision.h"
#include "EventNuke.h"
#include "EventView.h"
#include "Explosion.h"
#include "Points.h"

/**
 * Creates a new saucer instance.
 */
Saucer::Saucer(void)
{
	// required dragonfly managers
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();
	
	// setup saucer sprite
	Sprite *p_tempSprite = resourceManager.getSprite("saucer");
	if (!p_tempSprite)
	{
		logManager.writeLog(
			"Saucer::Saucer(): Sprite %s not found",
			"saucer");
	}
	else
	{
		setSprite(p_tempSprite);
		setSpriteSlowdown(4);
	}

	// register event handlers
	registerInterest(COLLISION_EVENT);
	registerInterest(NUKE_EVENT);

	// set object type
	setType("Saucer");

	// set vertical speed
	setXVelocity(-0.25); // 1/4 space per frames

	// set starting location
	moveToStart();
}

/**
 * Destructs the saucer.
 */
Saucer::~Saucer(void)
{
	WorldManager &worldManager = WorldManager::getInstance();

	// send "view" event with points interested ViewObjects
	EventView eventView(POINTS_STRING, 10, true);
	worldManager.onEvent(&eventView);
}

/**
 * Handles the events.
 */
int Saucer::eventHandler(Event *p_event)
{
	if (p_event->getType() == OUT_EVENT)
	{
		out();
		return 1;
	}

	if (p_event->getType() == COLLISION_EVENT)
	{
		EventCollision *p_eventCollision = static_cast<EventCollision *>(p_event);
		hit(p_eventCollision);
		return 1;
	}

	if (p_event->getType() == NUKE_EVENT)
	{
		Explosion *explosion = new Explosion();
		explosion->setPosition(this->getPosition());

		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);

		new Saucer();
	}

	return 0;
}

/**
 * Checks and handles if the saucer is out of the left side of screen.
 */
void Saucer::out(void)
{
	if (getPosition().getX() >= 0)
		return;

	moveToStart();

	// spawn a new saucer when one has passed by to make the game harder
	new Saucer();
}

/**
 * Moves the saucer back to the start position.
 */
void Saucer::moveToStart(void)
{
	WorldManager &worldManager = WorldManager::getInstance();

	int worldHorizontal = worldManager.getBoundary().getHorizontal();
	int worldVertical = worldManager.getBoundary().getVertical();
	Position tempPos(worldHorizontal + random() % worldHorizontal + 3,
		random() % (worldVertical - 4) + 4);
	setPosition(tempPos);

	// move slightly to the right until there is no collision
	ObjectList collisionList = worldManager.isCollision(this, tempPos);
	while (!collisionList.isEmpty())
	{
		tempPos.setX(tempPos.getX() + 1);
		collisionList = worldManager.isCollision(this, tempPos);
	}

	worldManager.moveObject(this, tempPos);
}

/**
 * Is called when a collision has happened.
 */
void Saucer::hit(EventCollision *p_collisionEvent)
{
	// ignore saucer to saucer collision
	if ((p_collisionEvent->getObject1()->getType() == "Saucer") &&
		(p_collisionEvent->getObject2()->getType() == "Saucer"))
		return;

	// saucer hits bullet
	if ((p_collisionEvent->getObject1()->getType() == "Bullet") ||
		(p_collisionEvent->getObject2()->getType() == "Bullet"))
	{
		// create explosion
		Explosion *p_explosion = new Explosion();
		p_explosion->setPosition(this->getPosition());

		// saucers appear stay around perpetually
		new Saucer();
	}

	// saucer hits hero
	if ((p_collisionEvent->getObject1()->getType() == "Hero") ||
		(p_collisionEvent->getObject2()->getType() == "Hero"))
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(p_collisionEvent->getObject1());
		worldManager.markForDelete(p_collisionEvent->getObject2());
	}
}
