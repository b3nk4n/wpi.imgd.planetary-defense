/*******************************************************************************
 * @file        WorldManager.cpp
 * @author      bsautermeister
 * @description Manages the game world by efficiently organising all active and
 *              deletabble game objects.
 ******************************************************************************/

#include "WorldManager.h"
#include "LogManager.h"

/**
 * Creates a world manager instance.
 */
WorldManager::WorldManager(void)
{

}

/**
 * Hides the copy constructor.
 */
WorldManager::WorldManager(WorldManager const&)
{
}

/**
 * Hides the assignment operator.
 */
void WorldManager::operator=(WorldManager const&)
{
}

/**
 * Gets the singleton game world manager instance.
 * @return The singleton game manager instance.
 */
WorldManager& WorldManager::getInstance(void)
{
	static WorldManager worldManager;
	return worldManager;
}

/**
 * Starts up the world manager and initializes all to empty.
 * @return Returns 0 if start up was successfull, else negative.
 */
int WorldManager::startUp(void)
{
	_isStarted = true;
	return 0;
}

/**
 * Shuts down the world manager.
 */
void WorldManager::shutDown(void)
{
	// cleanup world objects
	clearAllObjects();

	_isStarted = false;
}

/**
 * Adds a new object to the game world.
 * @parem p_object The game object to add.
 * @return Return 0 if insertion was successful, in case of error -1.
 */
int WorldManager::insertObject(Object *p_object)
{
	return _updates.insert(p_object);
}

/**
 * Removes an object from the game world.
 * @parem p_object The game object to remove.
 * @return Return 0 if removing was successful, in case of error -1.
 */
int WorldManager::removeObject(Object *p_object)
{
	return _updates.remove(p_object);
}

/**
 * Gets all game objects of the game world.
 * @return The list of all game objects.
 */
ObjectList WorldManager::getAllObjects(void)
{
	return _updates;
}

/**
 * Clears all game objects in the world.
 */
void WorldManager::clearAllObjects(void)
{
	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
		"WorldManager::clearAllObjects()",
		"_updates list count: %d\n",
		_updates.getCount());

	ObjectListIterator it(&_updates);
	for (it.first(); !it.isDone(); it.next())
	{
		//delete it.currentObject(); // TODO: ask TA/Prof. why this does not work!?
	}

	_updates.clear();
	_deletions.clear();
}

/**
 * Updates game world and deleted all marked objects.
 */
void WorldManager::update(void)
{
	// delete all marked objects
	ObjectListIterator it(&_deletions);
	for (it.first(); !it.isDone(); it.next())
	{
		Object *p_object = it.currentObject();
		_updates.remove(p_object);
		delete p_object;
	}

	// clear deletion list for next update
	_deletions.clear();
}

/**
 * Marks a game object to be deleted at the end of the current game update loop.
 * @param p_object The game object to be deferred deleted.
 * @return Return 0 if marking was successful, in case of error -1.
 */
int WorldManager::markForDelete(Object *p_object)
{
	// verify object
	if (p_object == NULL)
		return -1;

	// verify game object not no mark twice
	ObjectListIterator it(&_deletions);
	for (it.first(); !it.isDone(); it.next())
	{
		if (p_object == it.currentObject())
			return 0;
	}

	// insert to delitions/marked list
	_deletions.insert(p_object);
	return 0;
}
