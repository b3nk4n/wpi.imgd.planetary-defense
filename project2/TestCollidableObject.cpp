/*******************************************************************************
 * @file        TestCollidableObject.cpp
 * @author      bsautermeister
 * @description Test object used by the simple unit test tool.
 ******************************************************************************/

#include <stdlib.h>
#include "TestCollidableObject.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "EventCollision.h"
#include "LogManager.h"

/**
 * Creates a new collidable test object instance.
 */
TestCollidableObject::TestCollidableObject(void)
{
	setType(TYPE_TEST_COLLIDABLE_OBJECT);

	registerInterest(COLLISION_EVENT); // NOTE: registering for COLLISION/OUT not necessary !?

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
		"TestCollidableObject::TestCollidableObject()",
		"Test object created with id=%d\n",
		_id);
}

/**
 * Handles the events.
 */
int TestCollidableObject::eventHandler(Event *p_event)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	if (p_event->getType() == COLLISION_EVENT)
	{
		EventCollision *p_eventCollision = static_cast<EventCollision *>(p_event);

		logManager.writeLog(LOG_DEBUG,
			"TestCollidableObject::eventHandler()",
			"Object with id=%d reports collision\n",
			_id);

		setVelocityX(-1 * getVelocityX());
		setVelocityY(-1 * getVelocityY());
	}
}

/**
 * Renders the test game object.
 */
void TestCollidableObject::draw(void)
{
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	graphicsManager.drawChar(getPosition(), 'O', COLOR_BLUE);
	graphicsManager.drawString(Position(getPosition().getX() - 15, getPosition().getY()),
		"Collidable -->", CENTER_JUSTIFIED, COLOR_WHITE);
}
