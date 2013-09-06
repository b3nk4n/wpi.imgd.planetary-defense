/*******************************************************************************
 * @file        Object.cpp
 * @author      bsautermeister
 * @description The bass class for all game objects representing an object in
 *              the game world.
 ******************************************************************************/

#include "Object.h"
#include "WorldManager.h"

/**
 * Creates a game object instance.
 */
Object::Object(void)
{
	setType(TYPE_OBJECT);

	// add itself to the world manager
	WorldManager &worldManager = WorldManager::getInstance();
	worldManager.insertObject(this);
}

/**
 * Cleans up the game object.
 */
Object::~Object(void)
{
	// remove itself from the world manager
	WorldManager &worldManager = WorldManager::getInstance();
	worldManager.removeObject(this);
}

/**
 * Handles events, while default is to ignore all events.
 * @param p_event Points to the current event to handle.
 * @return Return 0 if ignored, else 1 if event was handled.
 */
int Object::eventHandler(Event *p_event)
{
	// event was not handled
	return 0;
}

/**
 * Gets the game objects type.
 * @return The game object type.
 */
string Object::getType(void)
{
	return _type;
}

/**
 * Sets the game objects type.
 * @param type The new game object type.
 */
void Object::setType(string type)
{
	_type = type;
}

/**
 * Gets the game objects position in the game world.
 * @return The game object position.
 */
Position Object::getPosition(void)
{
	return _position;
}

/**
 * Sets the game objects position in the game world.
 * @param position The new game objects position.
 */
void Object::setPosition(Position position)
{
	_position = position;
}
