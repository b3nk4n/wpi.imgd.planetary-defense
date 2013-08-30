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
#include "Position.h"
#include "Bullet.h"

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

	// set object type
	setType("Hero");

	// set starting location
	moveToStart();

	// init members counters
	fireSlowdown = 15;
	fireCountdown = fireSlowdown;
	nukeCount = 1;
}

/**
 * End game when hero is destroyed.
 */
Hero::~Hero(void)
{
	GameManager &gameManager = GameManager::getInstance();
	gameManager.setGameOver();
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

	return 0;
}

/**
 * Handles keyboard events.
 */
void Hero::keyboard(EventKeyboard *p_keyboardEvent)
{
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
	}
}

/**
 * Moves the hero vertically.
 */
void Hero::move(int dy)
{
	WorldManager &worldManager = WorldManager::getInstance();
	Position newPos(getPosition().getX(), getPosition().getY() + dy);

	if ((newPos.getY() > 0) && 
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
	new Bullet(getPosition());
}

/**
 * Updates the hero every frame.
 */
void Hero::step(void)
{
	--fireCountdown;
	if (fireCountdown < 0)
		fireCountdown = 0;
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
}
