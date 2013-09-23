/*******************************************************************************
* @file        SceneGraph.cpp
* @author      bsautermeister
* @description A simple scene graph to manage and organize game objects more
*              efficiently.
******************************************************************************/

#include "SceneGraph.h"
#include "LogManager.h"

/**
 * Creates a new scene graph instance.
 */
SceneGraph::SceneGraph(void)
{

}

/**
 * Cleans up the screne graph.
 */
SceneGraph::~SceneGraph(void)
{
}

/**
 * Inserts an object into the scene graph.
 * @param p_object The object to add.
 * @return Returns 0 in case of success, else -1.
 */
int SceneGraph::insertObject(Object *p_object)
{
	LogManager &logManager = LogManager::getInstance();

	// add object to list
	if (_objects.insert(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::insertObject()",
			"Inserting of object failed.\n");
		return -1;
	}

	// check adding to solidness list
	if (p_object->isSolid())
	{
		if(_solidObjects.insert(p_object))
		{
			logManager.writeLog(LOG_ERROR,
				"SceneGraph::insertObject()",
				"Inserting of solid object failed.\n");
			return -1;
		}
	}

	// check adding to altitude list
	if (valueInRange(p_object->getAltitude(), MIN_ALTITUDE, MAX_ALTITUDE))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::insertObject()",
			"Altitude %d is out of range.\n",
			p_object->getAltitude());
		return -1;
	}
	if(_visibleObjects[p_object->getAltitude()].insert(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::insertObject()",
			"Inserting of visible object failed.\n");
		return -1;
	}

	return 0;
}

/**
 * Removes an object from the scene graph.
 * @param p_object The object to remove.
 * @return Returns 0 in case of success, else -1.
 */
int SceneGraph::removeObject(Object *p_object)
{
	LogManager &logManager = LogManager::getInstance();

	if (_objects.remove(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::removeObject()",
			"Removing of object failed.\n");
		return -1;
	}

	if (_solidObjects.remove(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::removeObject()",
			"Removing of solid object failed.\n");
		return -1;
	}

	// verify altitude
	if (valueInRange(p_object->getAltitude(), MIN_ALTITUDE, MAX_ALTITUDE))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::removeObject()",
			"Altitude %d is out of range.\n",
			p_object->getAltitude());
		return -1;
	}
	if (_visibleObjects[p_object->getAltitude()].remove(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::removeObject()",
			"Removing of visible object failed.\n");
		return -1;
	}

	return 0;
}

/**
 * Clears all objects from the scene graph.
 */
void SceneGraph::clearAllObjects(void)
{
	_objects.clear();
	_solidObjects.clear();
	for (int i = MIN_ALTITUDE; i <= MAX_ALTITUDE; ++i)
		_visibleObjects[i].clear();
}

/**
 * Gets all game objects from the scene graph.
 * @return All game objects or an empty list.
 */
ObjectList SceneGraph::allObjects(void)
{
	return _objects;
}

/**
 * Gets all solid game objects from the scene graph.
 * @return All solid game objects or an empty list.
 */
ObjectList SceneGraph::solidObjects(void)
{
	return _solidObjects;
}

/**
 * Gets all visible game objects from the scene graph.
 * @param altitude The altitude of the objects.
 * @return All visible game objects or an empty list.
 */
ObjectList SceneGraph::visibleObjects(int altitude)
{
	LogManager &logManager = LogManager::getInstance();

	if (valueInRange(altitude, MIN_ALTITUDE, MAX_ALTITUDE))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::visibleObjects()",
			"Altitude %d is out of range.\n",
			altitude);
		ObjectList empty;
		return empty;
	}
	return _visibleObjects[altitude];
}

/**
 * Updates the the altitude of an game object and repositions
 * the object appropriately in the scene graph.
 * @param p_object The object to update.
 * @param altitude The new altitude.
 * @return Returns 0 in case of success, else -1.
 */
int SceneGraph::updateAltitude(Object *p_object, int altitude)
{
	LogManager &logManager = LogManager::getInstance();

	// check if new altitude in valid range
	if (!valueInRange(altitude, MIN_ALTITUDE, MAX_ALTITUDE))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::updateAltitude()",
			"Altitude %d is out of range.\n",
			p_object->getAltitude());
		return -1;
	}

	// make sure old altitude in valid range
	if (!valueInRange(p_object->getAltitude(), MIN_ALTITUDE, MAX_ALTITUDE))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::updateAltitude()",
			"Old altitude %d is out of range.\n",
			p_object->getAltitude());
		return -1;
	}

	// remove from old altitude
	if (_visibleObjects[p_object->getAltitude()].remove(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::updateAltitude()",
			"Removing from visible object list failed.\n");
		return -1;
	}

	// add to new altitude
	if (_visibleObjects[altitude].insert(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::updateAltitude()",
			"Inserting into visible object list failed.\n");
		return -1;
	}

	return 0;
}

/**
 * Updates the the solidness of an game object and repositions
 * the object appropriately in the scene graph.
 * @param p_object The object to update.
 * @param solidness The new solidness.
 * @return Returns 0 in case of success, else -1.
 */
int SceneGraph::updateSolidness(Object *p_object, Solidness solidness)
{
	LogManager &logManager = LogManager::getInstance();

	// try remove it from the list if it was solid before
	if (p_object->isSolid())
	{
		_solidObjects.remove(p_object);
	}

	if (solidness == HARD || solidness == SOFT)
	{
		if (_solidObjects.insert(p_object))
		{
			logManager.writeLog(LOG_ERROR,
				"SceneGraph::updateSolidness()",
				"Inserting into solid list failed.\n");
			return -1;
		}
	}

	return 0;
}
