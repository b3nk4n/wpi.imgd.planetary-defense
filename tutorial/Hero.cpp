/* Hero.cpp */

#include "Hero.h"
#include "ResourceManager.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "EventKeyboard.h"
#include "EventStep.h"
#include "EventNuke.h"
#include "EventView.h"
#include "EventPowerup.h"
#include "PowerupScore.h"
#include "PowerupLaser.h"
#include "PowerupRocket.h"
#include "PowerupNuke.h"
#include "Position.h"
#include "Bullet.h"
#include "Laser.h"
#include "Rocket.h"
#include "GameOver.h"
#include "Explosion.h"
#include "Points.h"
#include "Hitpoints.h"

#define CUSTOM_KEY_SPACE ' '
#define CUSTOM_KEY_ENTER 13

Hero::Hero(void)
{
	// required dragonfly managers
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();
	
	// setup hero sprite
	Sprite *p_tempSprite = resourceManager.getSprite("ship");
	if (!p_tempSprite)
	{
		logManager.writeLog(
			"Hero::Hero(): Sprite %s not found",
			"ship");
	}
	else
	{
		setSprite(p_tempSprite);
		setSpriteSlowdown(3);
	}

	// register for events
	registerInterest(KEYBOARD_EVENT);
	registerInterest(STEP_EVENT);
	registerInterest(POWERUP_EVENT);
	registerInterest(COLLISION_EVENT);

	// set object type
	setType("Hero");

	// set starting location
	moveToStart();

	// init members counters
	fireSlowdown = 15;
	fireCountdown = fireSlowdown;
	nukeCount = 1;
	
	weaponType = DEFAULT;
	upgradedWeaponCounter = 0;

	setHitpoints(MAX_HITPOINTS);
}

/**
 * End game when hero is destroyed.
 */
Hero::~Hero(void)
{
	GameOver *p_gameOver = new GameOver();

	Explosion *explosion = new Explosion(EXPLOSION_LARGE);
	explosion->setPosition(getPosition());
}

/**
 * Handles all events.
 */
int Hero::eventHandler(Event *p_event)
{
	if (p_event->getType() == KEYBOARD_EVENT)
	{
		EventKeyboard *p_keyboard_event = static_cast<EventKeyboard *>(p_event);
		keyboard(p_keyboard_event);
		return 1; 
	}

	if (p_event->getType() == STEP_EVENT)
	{
		step();
		return 1; 
	}
	
	if (p_event->getType() == POWERUP_EVENT)
	{
		EventPowerup *p_powerup_event = static_cast<EventPowerup *>(p_event);
		powerupCollected(p_powerup_event);
		return 1; 
	}

	if (p_event->getType() == COLLISION_EVENT)
	{
		EventCollision *p_eventCollision = static_cast<EventCollision *>(p_event);
		hit(p_eventCollision);
		return 1;
	}

	return 0;
}

/**
 * Is called when a collision has happened.
 */
void Hero::hit(EventCollision *p_collisionEvent)
{
	WorldManager &worldManager = WorldManager::getInstance();
	
	// ignore enemy to enemy collision
	if ((p_collisionEvent->getObject1()->getType() == "Enemy") ||
		(p_collisionEvent->getObject2()->getType() == "Enemy"))
	{
		setHitpoints(hitpoints - 1);

		// Update view
		EventView eventView(HITPOINTS_STRING, hitpoints, false);
		worldManager.onEvent(&eventView);
	}
}

/**
 * Handles keyboard events.
 */
void Hero::keyboard(EventKeyboard *p_keyboardEvent)
{
	WorldManager &worldManager = WorldManager::getInstance();

	switch (p_keyboardEvent->getKey())
	{
	case KEY_UP:
		move(-1);
		break;
	case KEY_DOWN:
		move(1);
		break;
	case CUSTOM_KEY_SPACE:
		fire();
		break;
	case CUSTOM_KEY_ENTER:
		nuke();
		break;
	case 'q':
		worldManager.markForDelete(this);
		break;
	}
}

/**
 * Is called when a powerup was collected.
 */
void Hero::powerupCollected(EventPowerup *p_powerup_event)
{
	WorldManager &worldManager = WorldManager::getInstance();
	string powerupId = p_powerup_event->getPowerupId();
	
	if (powerupId == POWERUP_SCORE)
	{
		// send "view" event with points to interested ViewObjects
		EventView eventView(POINTS_STRING, 5, true);
		worldManager.onEvent(&eventView);
	}
	else if (powerupId == POWERUP_LASER)
	{
		weaponType = LASER;
		upgradedWeaponCounter = UPGRADED_WEAPON_STEPS;
	}
	else if (powerupId == POWERUP_ROCKET)
	{
		weaponType = ROCKET;
		upgradedWeaponCounter = UPGRADED_WEAPON_STEPS;
	}
	else if (powerupId == POWERUP_NUKE)
	{
		nukeCount++;

		EventView eventView("Nukes", nukeCount, false);
		worldManager.onEvent(&eventView);
	}
}

/**
 * Moves the hero vertically.
 */
void Hero::move(int dy)
{
	WorldManager &worldManager = WorldManager::getInstance();
	Position newPos(getPosition().getX(), getPosition().getY() + dy);

	if ((newPos.getY() > 3) && 
		(newPos.getY() < worldManager.getBoundary().getVertical()))
	{
		worldManager.moveObject(this, newPos);
	}
}

/**
 * Moves the hero back to the start position.
 */
void Hero::moveToStart(void)
{
	WorldManager &worldManager = WorldManager::getInstance();

	int worldVertical = worldManager.getBoundary().getVertical();
	Position tempPos(7, worldVertical / 2);
	setPosition(tempPos);

	worldManager.moveObject(this, tempPos);
}

/**
 * Fires a bullet.
 */
void Hero::fire(void)
{
	if (fireCountdown > 0)
		return;

	fireCountdown = fireSlowdown;
	
	if (weaponType == DEFAULT)
		new Bullet(getPosition());
	else if (weaponType == LASER)
		new Laser(getPosition());
	else if (weaponType == ROCKET)
		new Rocket(getPosition());
}

/**
 * Updates the hero every frame.
 */
void Hero::step(void)
{
	--fireCountdown;
	if (fireCountdown < 0)
		fireCountdown = 0;
	
	--upgradedWeaponCounter;
	if (upgradedWeaponCounter < 0)
	{
		upgradedWeaponCounter = 0;
		weaponType = DEFAULT;
	}
}

/**
 * Hero releases a nuke to destory all enemies.
 */
void Hero::nuke(void)
{
	if (!nukeCount)
		return;

	--nukeCount;

	WorldManager &worldManager = WorldManager::getInstance();
	EventNuke nuke;
	worldManager.onEvent(&nuke);

	// send "view" event with nukes
	EventView eventView("Nukes", -1, true);
	worldManager.onEvent(&eventView);
}

/**
 * Sets the hitpoints and updates the display view.
 */
void Hero::setHitpoints(int hp)
{
	WorldManager &worldManager = WorldManager::getInstance();

	if (hp > MAX_HITPOINTS)
		hp = MAX_HITPOINTS;

	this->hitpoints = hp;

	if (hitpoints <= 0)
	{
		hitpoints = 0;
		worldManager.markForDelete(this);
	}

	// Update view
	EventView eventView(HITPOINTS_STRING, hitpoints, false);
	worldManager.onEvent(&eventView);
}

