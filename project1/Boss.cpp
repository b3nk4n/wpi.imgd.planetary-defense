/* Boss.cpp */

#include <stdlib.h>
#include "Boss.h"
#include "EventStep.h"
#include "EventLevelCommand.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "BossBullet.h"

/**
 * Creates a new boss instance.
 */
Boss::Boss(void)
	: Enemy("boss", 15, 500, 0.0f, EXPLOSION_LARGE, 20)
{
	registerInterest(LEVEL_COMMAND_EVENT);
	registerInterest(STEP_EVENT);
	this->canCreateEnemy = false;

	this->setYVelocity(0.2);

	this->finished = false;

	this->fireTimer = FIRE_TICKS_MAX;

	// set object type
	setType("Boss");
}

/**
 * Creates a new Boss.
 */
void Boss::createEnemy(void)
{
	new Boss();
}

/**
 * Destructs the Boss.
 */
Boss::~Boss(void)
{
	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog("Boss::~Boss() called");

	WorldManager &worldManager = WorldManager::getInstance();
	EventLevelCommand eventLevelCommand(COMMAND_BOSS_KILLED);
	worldManager.onEvent(&eventLevelCommand);
}

/**
 * Handles the events.
 */
int Boss::eventHandler(Event *p_event)
{
	if (Enemy::eventHandler(p_event))
		return 1;

	if (p_event->getType() == LEVEL_COMMAND_EVENT)
	{
		EventLevelCommand *event_levelCommand = static_cast<EventLevelCommand *>(p_event);

		if (event_levelCommand->getCommand() == COMMAND_STOP_BOSS)
		{
			this->finished = true;
		}

		return 1;
	}

	if (p_event->getType() == STEP_EVENT)
	{
		WorldManager &worldManager = WorldManager::getInstance();

		if (this->getPosition().getY() < 3 + 3)
		{
			this->setYVelocity(0.2);
		}
		else if (this->getPosition().getY() > worldManager.getBoundary().getVertical() - 3)
		{
			this->setYVelocity(-0.2);
		}

		// if boss time is over, get faster
		if (this->finished)
		{
			this->setXVelocity(-2.5);
		}
		else
		{
			// if boss time is not over, verify that boss never goes more left than the screen center
			if (this->getPosition().getX() < worldManager.getBoundary().getHorizontal() / 2)
			{
				this->setXVelocity(0);
			}
		}

		tryFire();

		return 1;
	}

	return 0;
}

/**
 * Fires a bullet.
 */
 void Boss::tryFire(void)
 {
 	--fireTimer;
 	if (fireTimer <= 0)
 	{
 		new BossBullet(this->getPosition());

 		fireTimer = FIRE_TICKS_MIN + (random() % (FIRE_TICKS_MAX - FIRE_TICKS_MIN));
 	}
 }