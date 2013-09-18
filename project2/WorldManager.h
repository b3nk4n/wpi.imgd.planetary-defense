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
#include "Box.h"

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
	 * The worlds boundary.
	 */
	Box _worldBoundary;

	/**
	 * The views boundary.
	 */
	Box _viewBoundary;

	/**
	 * The objected which is followed by the view camera.
	 */
	Object *_p_viewFollowing;

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
	 * Clears all game objects in the world.
	 */
	void clearAllObjects(void);

	/**
	 * Marks a game object to be deleted at the end of the current game update loop.
	 * @param p_object The game object to be deferred deleted.
	 * @return Return 0 if marking was successful, in case of error -1.
	 */
	int markForDelete(Object *p_object);

	/**
	 * Updates game world and deleted all marked objects.
	 * @param delta The elapsed game time is seconds.
	 */
	void update(float delta);

	/**
	 * Renders all game objects.
	 */
	void draw(void);

	/**
	 * Gets the list of objects colliding with an objects at the given position.
	 * @param p_object The object to check, no matter if its solid or not.
	 * @param box The box to check.
	 * @return Returns list of objects collided with at given position.
	 */
	ObjectList isCollision(Object *p_object, Box box);

	/**
	 * Tries to move the object to the designited position if possible.
	 * @param p_object The object to move (move OK if spectral)
	 * @param position The position to move to.
	 * @return Returns 0 if ok, else -1 for collision with solid object.
	 */
	int moveObject(Object *p_object, Position position);

	/**
	 * Validates if event is handles by this manager.
	 * @param eventType The event type name.
	 * @return Returns TRUE if event is handled, else FALSE.
	 */
	virtual bool isValid(string eventType);

	 /**
	  * Sets the view to center screen on position the specified position
	  * @note The view edge will not go bexound the world boundries
	  * @param position The view position to look to.
	  */
	void setViewPosition(Position position);

	/**
	 * Sets the view to center screen on object.
	 * @param p_viewFollowing The object to follow or NULL to stop following.
	 * @return Returns 0 if ok, else -1.
	 */
	int setViewFollowing(Object *p_viewFollowing);

	 /**
	  * Gets the world boundary.
	  * @return The world boundary.
	  */
	 Box getWorldBoundary(void);

	 /**
	  * Sets the world boundary.
	  * @param world The world boundary.
	  */
	 void setWorldBoundary(Box world);

	 /**
	  * Gets the view boundary.
	  * @return The view boundary.
	  */
	 Box getViewBoundary(void);

	 /**
	  * Sets the view boundary.
	  * @param view The view boundary.
	  */
	 void setViewBoundary(Box view);
};

#endif
