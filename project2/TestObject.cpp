/*******************************************************************************
 * @file        TestObject.cpp
 * @author      bsautermeister
 * @description Test object used by the simple unit test tool.
 ******************************************************************************/

#include <stdlib.h>
#include "TestObject.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "EventTest.h"
#include "LogManager.h"

#define ENDLESS_TIME 999999999

/**
 * Creates a new test object instance.
 */
TestObject::TestObject(void)
{
	_id = random();
	setType(TYPE_TEST_OBJECT);
	_stepsToGameOver = ENDLESS_TIME;
	_stl = ENDLESS_TIME;

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
		"TestObject::TestObject()",
		"Test object created with id=%d\n",
		_id);
}

/**
 * Updates the test object.
 */
void TestObject::step(void)
{
	LogManager &logManager = LogManager::getInstance();

	move();

	--_stepsToGameOver;
	if (_stepsToGameOver == 0)
	{
		logManager.writeLog(LOG_DEBUG,
			"TestObject::step()",
			"Object with id=%d sets game over flag\n",
			_id);
		GameManager &gameManager = GameManager::getInstance();
		gameManager.setGameOver(true);
		//WorldManager &worldManager = WorldManager::getInstance();
		//worldManager.markForDelete(this);
	}

	--_stl;
	if (_stl == 0)
	{
		logManager.writeLog(LOG_DEBUG,
			"TestObject::step()",
			"Object with id=%d marks itself for delete\n",
			_id);
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
	}
}

/**
 * Moves the test object.
 */
 void TestObject::move(void)
 {
 	setPosition(Position(getPosition().getX() + 1, getPosition().getY() + 1));

 	LogManager &logManager = LogManager::getInstance();
 	logManager.writeLog(LOG_DEBUG,
			"TestObject::move()",
			"Object with id=%d moved to position x=%d, y=%d\n",
			_id,
			getPosition().getX(),
			getPosition().getY());
 }

/**
 * Handles the events.
 */
int TestObject::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
		step();
	}

	if (p_event->getType() == TEST_EVENT)
	{
		// test event kills object to verify event was received
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
	}
}

/**
 * Sets the sets until the objects sets the game over flag.
 */
void TestObject::setStepsToGameOver(int value)
{
	_stepsToGameOver = value;
}

/**
 * Sets the steps to live.
 */
void TestObject::setSTL(int value)
{
	_stl = value;
}
