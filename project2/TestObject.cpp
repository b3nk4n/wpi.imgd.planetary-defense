/*******************************************************************************
 * @file        TestObject.cpp
 * @author      bsautermeister
 * @description Test object used by the simple unit test tool.
 ******************************************************************************/

#include <stdlib.h>
#include "TestObject.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "EventTest.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "EventOut.h"
#include "EventCollision.h"
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

	--_stepsToGameOver;
	if (_stepsToGameOver == 0)
	{
		logManager.writeLog(LOG_DEBUG,
			"TestObject::step()",
			"Object with id=%d sets game over flag\n",
			_id);
		GameManager &gameManager = GameManager::getInstance();
		gameManager.setGameOver(true);
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
 * Handles the events.
 */
int TestObject::eventHandler(Event *p_event)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	if (p_event->getType() == STEP_EVENT)
	{
		step();
	}

	if (p_event->getType() == TEST_EVENT)
	{
		logManager.writeLog(LOG_DEBUG,
			"TestObject::eventHandler()",
			"Object with id=%d got OUT\n",
			_id);

		// test event kills object to verify event was received
		worldManager.markForDelete(this);
	}

	if (p_event->getType() == KEYBOARD_EVENT)
	{
		EventKeyboard *p_keyboardEvent = static_cast<EventKeyboard *>(p_event);
		int key = p_keyboardEvent->getKey();
		logManager.writeLog(LOG_DEBUG,
			"TestObject::eventHandler()",
			"Object with id=%d got key event: %d\n",
			_id,
			key);

		if (key == UP_KEY || key == ENTER_KEY || key == SPACE_KEY)
		{
			GameManager &gameManager = GameManager::getInstance();
			gameManager.setGameOver(true);
		}
	}

	if (p_event->getType() == MOUSE_EVENT)
	{
		EventMouse *p_mouseEvent = static_cast<EventMouse *>(p_event);
		
		logManager.writeLog(LOG_DEBUG,
			"TestObject::eventHandler()",
			"Object with id=%d got mouse event in: (%d, %d)\n",
			_id,
			p_mouseEvent->getPosition().getX(),
			p_mouseEvent->getPosition().getY());

		if (p_mouseEvent->getPosition() == getPosition())
		{
			worldManager.markForDelete(this);
		}
	}

	if (p_event->getType() == COLLISION_EVENT)
	{
		EventCollision *p_eventCollision = static_cast<EventCollision *>(p_event);

		logManager.writeLog(LOG_DEBUG,
			"TestObject::eventHandler()",
			"Object with id=%d reports collision\n",
			_id);

		worldManager.markForDelete(this);
	}

	if (p_event->getType() == OUT_EVENT)
	{
		logManager.writeLog(LOG_DEBUG,
			"TestObject::eventHandler()",
			"Object with id=%d got OUT\n",
			_id);

		worldManager.markForDelete(this);
	}
}

/**
 * Renders the test game object.
 */
void TestObject::draw(void)
{
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	graphicsManager.drawChar(getPosition(), 'X', COLOR_RED);
	//graphicsManager.drawString(getPosition(), "Hallo", CENTER_JUSTIFIED, COLOR_RED);
	//graphicsManager.drawStringFormat(getPosition(), CENTER_JUSTIFIED, COLOR_RED,
	//	"Object ID: %d",
	//	_id);
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
