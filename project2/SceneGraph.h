/*******************************************************************************
 * @file        SceneGraph.h
 * @author      bsautermeister
 * @description A simple scene graph to manage and organize game objects more
 *              efficiently.
 ******************************************************************************/

 #ifndef __SCENE_GRAPH_H__
 #define __SCENE_GRAPH_H__

#include "Object.h"
#include "ObjectList.h"

#define MIN_ALTITUDE 0
#define MAX_ALTITUDE 4

// NOTE: objects on level 0 are persistent
#define MAX_LEVEL 100

/**
 * Representing a scene graph.
 */
class SceneGraph
{
private:
	/**
	 * The games current level.
	 */
	int _level;

	/**
	 * All game objects.
	 */
	ObjectList _objects[MAX_LEVEL + 1];

	/**
	 * All solid game objects.
	 */
	ObjectList _solidObjects[MAX_LEVEL + 1];

	/**
	 * All visible game objects.
	 */
	ObjectList _visibleObjects[MAX_LEVEL + 1][MAX_ALTITUDE + 1];

public:
	/**
	 * Creates a new scene graph instance.
	 */
	SceneGraph(void);

	/**
	 * Cleans up the screne graph.
	 */
	~SceneGraph(void);

	/**
	 * Inserts an object into the scene graph.
	 * @param p_object The object to add.
	 * @return Returns 0 in case of success, else -1.
	 */
	int insertObject(Object *p_object);

	/**
	 * Removes an object from the scene graph.
	 * @param p_object The object to remove.
	 * @return Returns 0 in case of success, else -1.
	 */
	int removeObject(Object *p_object);

	/**
	 * Clears all objects from the screne graph.
	 */
	void clearAllObjects(void);

	/**
	 * Gets all game objects from the scene graph.
	 * @return All game objects or an empty list.
	 */
	ObjectList allObjects(void);

	/**
	 * Gets all solid game objects from the scene graph.
	 * @return All solid game objects or an empty list.
	 */
	ObjectList solidObjects(void);

	/**
	 * Gets all visible game objects from the scene graph.
	 * @param altitude The altitude of the objects.
	 * @return All visible game objects or an empty list.
	 */
	ObjectList visibleObjects(int altitude);

	/**
	 * Updates the the altitude of an game object and repositions
	 * the object appropriately in the scene graph.
	 * @param p_object The object to update.
	 * @param altitude The new altitude.
	 * @return Returns 0 in case of success, else -1.
	 */
	int updateAltitude(Object *p_object, int altitude);

	/**
	 * Updates the the solidness of an game object and repositions
	 * the object appropriately in the scene graph.
	 * @param p_object The object to update.
	 * @param solidness The new solidness.
	 * @return Returns 0 in case of success, else -1.
	 */
	int updateSolidness(Object *p_object, Solidness solidness);

	/**
	 * Sets the games current level.
	 * @param level The level to set.
	 * @return Returns 0 if ok, else -1.
	 */
	int setLevel(int level);

	/**
	 * Gets the games current level.
	 * @return The current level.
	 */
	int getLevel(void);
};

 #endif
