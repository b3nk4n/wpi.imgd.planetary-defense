/* Enemy.cpp */

#include <stdlib.h>
#include "Enemy.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "EventOut.h"
#include "EventCollision.h"
#include "EventNuke.h"
#include "EventView.h"
#include "EventDetonation.h"
#include "EventLevelCommand.h"
#include "Explosion.h"
#include "Points.h"
#include "utility.h"
#include "Circle.h"
#include "PowerupScore.h"
#include "PowerupLaser.h"
#include "PowerupRocket.h"
#include "PowerupNuke.h"
#include "PowerupDoubleBullet.h"

/**
 * Creates a new enemy instance.
 * Note: maxOutOfBoundsOffset == -1 --> auto
 */
Enemy::Enemy(string spriteName, int hitpoints, int killscore, float powerupSpawnChance, int explosionType, int maxOutOfBoundsOffset)
{
	// required dragonfly managers
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();
	
	// setup enemy sprite
	Sprite *p_tempSprite = resourceManager.getSprite(spriteName);
	if (!p_tempSprite)
	{
		logManager.writeLog(
			"Enemy::Enemy(): Sprite %s not found",
			spriteName.c_str());
	}
	else
	{
		setSprite(p_tempSprite);
		setSpriteSlowdown(4);
	}

	// register event handlers
	registerInterest(COLLISION_EVENT);
	registerInterest(NUKE_EVENT);
	registerInterest(DETONATION_EVENT);

	// set vertical speed
	setXVelocity(-0.25); // 1/4 space per frames

	this->hitpoints = hitpoints;
	this->killscore = killscore;
	this->powerupSpawnChance = powerupSpawnChance;
	this->explosionType = explosionType;

	this->canCreateEnemy = true;

	WorldManager &worldManager = WorldManager::getInstance();

	// set maximum out of bounds spawn distance from right side of screen
	if (maxOutOfBoundsOffset == AUTO_OUT_OF_BOUNDS)
		this->maxOutOfBoundsOffset = worldManager.getBoundary().getHorizontal();
	else
		this->maxOutOfBoundsOffset = maxOutOfBoundsOffset;

	// set starting location
	moveToStart();
}

/**
 * Destructs the enemy.
 */
Enemy::~Enemy(void)
{
	// all work is done by kill()
}

/**
 * Handles the events.
 */
int Enemy::eventHandler(Event *p_event)
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
		decreaseHitpoints(1);
		return 1;
	}
	
	if (p_event->getType() == DETONATION_EVENT)
	{
		EventDetonation *p_eventDetonation = static_cast<EventDetonation *>(p_event);
		Circle detonationCircle = p_eventDetonation->getCircle();
		
		// check if enemy is in detonation circle
		if (distance(detonationCircle.getCenter(), this->getPosition()) <= detonationCircle.getRadius())
		{
			decreaseHitpoints(1);
		}
		return 1;
	}

	return 0;
}

/**
 * Kills this object and releases an explosion.
 */
void Enemy::kill(bool powerup)
{
	Explosion *explosion = new Explosion(this->explosionType);
	explosion->setPosition(this->getPosition());
	
	if (powerup)
		probablySpawnPowerup();

	WorldManager &worldManager = WorldManager::getInstance();
	worldManager.markForDelete(this);

	// send "view" event with points interested ViewObjects
	EventView eventView(POINTS_STRING, this->killscore, true);
	worldManager.onEvent(&eventView);

	if (canCreateEnemy)
	{
		createEnemy();
	}
}

/**
 * Checks and handles if the enemy is out of the left side of screen.
 */
void Enemy::out(void)
{
	if (getPosition().getX() >= 0)
		return;

	// spawn a new enemy when one has passed by to make the game harder
	if (canCreateEnemy)
	{
		moveToStart();

		if (random() % 10 == 0)
		createEnemy();
	}
	else
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
	}
}

/**
 * Moves the enemy back to the start position.
 */
void Enemy::moveToStart(void)
{
	WorldManager &worldManager = WorldManager::getInstance();

	int worldHorizontal = worldManager.getBoundary().getHorizontal();
	int worldVertical = worldManager.getBoundary().getVertical();
	Position tempPos(worldHorizontal + random() % maxOutOfBoundsOffset + 15,
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
void Enemy::hit(EventCollision *p_collisionEvent)
{
	WorldManager &worldManager = WorldManager::getInstance();
	
	// ignore enemy to enemy collision
	if (p_collisionEvent->getObject1()->getType() == p_collisionEvent->getObject2()->getType())
	{
		if (p_collisionEvent->getObject1()->getType() == "Saucer" ||
			p_collisionEvent->getObject1()->getType() == "Ufo" ||
			p_collisionEvent->getObject1()->getType() == "Boss")
		return;
	}

	// enemy hits bullet
	if ((p_collisionEvent->getObject1()->getType() == "Bullet") ||
		(p_collisionEvent->getObject2()->getType() == "Bullet") ||
		(p_collisionEvent->getObject1()->getType() == "Laser") ||
		(p_collisionEvent->getObject2()->getType() == "Laser"))
	{
		decreaseHitpoints(1);
	}

	// enemy hits hero
	if ((p_collisionEvent->getObject1()->getType() == "Hero") ||
		(p_collisionEvent->getObject2()->getType() == "Hero"))
	{
		worldManager.markForDelete(this);
	}
}

/**
 * Decreases the hit points and kills the enemy, if neccessary.
 */
void Enemy::decreaseHitpoints(int value)
{
	this->hitpoints -= value;

	if (hitpoints <= 0)
		kill(true);
}

/**
 * Probably spawns a power up with given spawn chance.
 */
void Enemy::probablySpawnPowerup()
{
	if ((random() % 1000) + 1 <= this->powerupSpawnChance * 1000)
	{
		switch(random() % 7)
		{
		case 0:
		case 1:
		case 2:
			new PowerupScore(this->getPosition());
			break;
		case 3:
			new PowerupNuke(this->getPosition());
			break;
		case 4:
			new PowerupLaser(this->getPosition());
			break;
		case 5:
			new PowerupRocket(this->getPosition());
			break;
		case 6:
			new PowerupDoubleBullet(this->getPosition());
			break;
		}
	}
}
