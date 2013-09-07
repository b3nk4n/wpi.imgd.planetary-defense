/*******************************************************************************
 * @file        WorldManager.h
 * @author      bsautermeister
 * @description Manages the game world by efficiently organising all active and
 *              deletable game objects.
 ******************************************************************************/

#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include "Manager.h"
#include "ObjectList.h"

/**
 * Class representing a manager to organize the game world.
 */
class WorldManager : public Manager
{
private:
	/**
	 * List of all world objects to be updated.
	 */
	ObjectList _updates;

	/**
	 * List of all world objects to be deferred deleted.
	 */
	ObjectList _deletions;

	/**
	 * Creates a world manager instance.
	 */
	WorldManager(void);

	/**
	 * Hides the copy constructor.
	 */
	WorldManager(WorldManager const&);

	/**
	 * Hides the assignment operator.
	 */
	void operator=(WorldManager const&);

public:
	/**
	 * Gets the singleton game world manager instance.
	 * @return The singleton game manager instance.
	 */
	static WorldManager& getInstance(void);

	/**
	 * Starts up the world manager and initializes all to empty.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	virtual int startUp(void);

	/**
	 * Shuts down the world manager.
	 */
	virtual void shutDown(void);

	/**
	 * Adds a new object to the game world.
	 * @parem p_object The game object to add.
	 * @return Return 0 if insertion was successful, in case of error -1.
	 */
	int insertObject(Object *p_object);

	/**
	 * Removes an object from the game world.
	 * @parem p_object The game object to remove.
	 * @return Return 0 if removing was successful, in case of error -1.
	 */
	int removeObject(Object *p_object);

	/**
	 * Gets all game objects of the game world.
	 * @return The list of all game objects.
	 */
	ObjectList getAllObjects(void);

	/**
	 * Updates game world and deleted all marked objects.
	 */
	void update(void);

	/**
	 * Marks a game object to be deleted at the end of the current game update loop.
	 * @param p_object The game object to be deferred deleted.
	 * @return Return 0 if marking was successful, in case of error -1.
	 */
	int markForDelete(Object *p_object);
};

#endif
