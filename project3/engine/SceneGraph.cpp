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
	_level = DEFAULT_LEVEL;
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
	if (_objects[_level].insert(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::insertObject()",
			"Inserting of object failed.\n");
		return -1;
	}

	// check adding to solidness list
	if (p_object->isSolid())
	{
		if(_solidObjects[_level].insert(p_object))
		{
			logManager.writeLog(LOG_ERROR,
				"SceneGraph::insertObject()",
				"Inserting of solid object failed.\n");
			return -1;
		}
	}

	// check adding to altitude list
	if (!valueInRange(p_object->getAltitude(), MIN_ALTITUDE, MAX_ALTITUDE))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::insertObject()",
			"Altitude %d is out of range.\n",
			p_object->getAltitude());
		return -1;
	}
	if(p_object->isVisible())
	{
		if(_visibleObjects[_level][p_object->getAltitude()].insert(p_object))
		{
			logManager.writeLog(LOG_ERROR,
				"SceneGraph::insertObject()",
				"Inserting of visible object failed.\n");
			return -1;
		}
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

	if (_objects[_level].remove(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::removeObject()",
			"Removing of object failed.\n");
		return -1;
	}

	// try delete, if object was solid
	if (p_object->isSolid())
	{
		if (_solidObjects[_level].remove(p_object))
		{
			logManager.writeLog(LOG_ERROR,
				"SceneGraph::removeObject()",
				"Removing of solid object failed.\n");
			return -1;
		}
	}

	// verify altitude
	if (!valueInRange(p_object->getAltitude(), MIN_ALTITUDE, MAX_ALTITUDE))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::removeObject()",
			"Altitude %d is out of range.\n",
			p_object->getAltitude());
		return -1;
	}
	// try delete, if object was visible
	if (_visibleObjects[_level][p_object->getAltitude()].remove(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::removeObject()",
			"Removing of visible object failed.\n");
		return -1;
	}

	return 0;
}

/**
 * Clears all objects from the scene graph of the current level.
 */
void SceneGraph::clearAllObjects(void)
{
	_objects[_level].clear();
	_solidObjects[_level].clear();
	for (int i = MIN_ALTITUDE; i <= MAX_ALTITUDE; ++i)
	{
		_visibleObjects[_level][i].clear();
	}
}

/**
 * Gets all game objects from the scene graph of ALL levels.
 * @return All game objects or an empty list.
 */
ObjectList SceneGraph::allObjectsOfAllLevels(void)
{
	ObjectList _total;
	for (int i = 0; i <= MAX_LEVEL; ++i)
		_total + _objects[i];

	return _total;
}

/**
 * Gets all game objects from the scene graph of the current level.
 * @return All game objects or an empty list.
 */
ObjectList SceneGraph::allObjects(void)
{
	// return all objects and all persistent objects
	return _objects[_level] + _objects[0];
}

/**
 * Gets all solid game objects from the scene graph of the current level.
 * @return All solid game objects or an empty list.
 */
ObjectList SceneGraph::solidObjects(void)
{
	// return all solid objects and all persistent objects
	return _solidObjects[_level] + _objects[0];
}

/**
 * Gets all visible game objects from the scene graph of the current level.
 * @param altitude The altitude of the objects.
 * @return All visible game objects or an empty list.
 */
ObjectList SceneGraph::visibleObjects(int altitude)
{
	LogManager &logManager = LogManager::getInstance();

	if (!valueInRange(altitude, MIN_ALTITUDE, MAX_ALTITUDE))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::visibleObjects()",
			"Altitude %d is out of range.\n",
			altitude);
		ObjectList empty;
		return empty;
	}
	return _visibleObjects[_level][altitude] + _objects[0];
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

	// verify altitude has changed
	if (p_object->getAltitude() == altitude)
		return 0;

	// remove from old altitude
	if (_visibleObjects[_level][p_object->getAltitude()].remove(p_object))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::updateAltitude()",
			"Removing from visible object list failed.\n");
		return -1;
	}

	// add to new altitude
	if (_visibleObjects[_level][altitude].insert(p_object))
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
		_solidObjects[_level].remove(p_object);
	}

	if (solidness == HARD || solidness == SOFT)
	{
		if (_solidObjects[_level].insert(p_object))
		{
			logManager.writeLog(LOG_ERROR,
				"SceneGraph::updateSolidness()",
				"Inserting into solid list failed.\n");
			return -1;
		}
	}

	return 0;
}

/**
 * Reposition game object in scene graph based on its persistence.
 * @param p_object The object to update.
 * @param persistent The game objects new persistence.
 * @return Returns 0 if succeeded, else -1.
 */
int SceneGraph::updatePersistence(Object *p_object, bool persistent)
{
	LogManager &logManager = LogManager::getInstance();
	int oldLevel;
	int newLevel;

	// verify persitence changed
	if (persistent == p_object->isPersistent())
		return 0;

	// figure out if moving from persistent to
	// not persistent, or vice versa
	if (p_object->isPersistent())
	{
		oldLevel = 0;
		newLevel = _level;
	}
	else
	{
		oldLevel = _level;
		newLevel = 0;
	}

	// do neccessary upkeep
	if (_objects[oldLevel].remove(p_object))
	{
		logManager.writeLog(LOG_ERROR,
				"SceneGraph::updatePersistence()",
				"Removing from list failed.\n");
		return -1;
	}
	if (_objects[newLevel].insert(p_object))
	{
		logManager.writeLog(LOG_ERROR,
				"SceneGraph::updatePersistence()",
				"Inserting into list failed.\n");
		return -1;
	}
	if (p_object->isVisible())
	{
		if (_visibleObjects[oldLevel][p_object->getAltitude()].remove(p_object))
		{
			logManager.writeLog(LOG_ERROR,
					"SceneGraph::updatePersistence()",
					"Removing from visible list failed.\n");
			return -1;
		}
		if (_visibleObjects[newLevel][p_object->getAltitude()].insert(p_object))
		{
			logManager.writeLog(LOG_ERROR,
					"SceneGraph::updatePersistence()",
					"Inserting into visible list failed.\n");
			return -1;
		}
	}

	return 0;
}

/**
 * Reposition game object in scene graph based on its visibility.
 * @param p_object The object to update.
 * @param visibility The game objects new visibility.
 * @return Returns 0 if succeeded, else -1.
 */
int SceneGraph::updateVisibility(Object *p_object, bool visibility)
{
	LogManager &logManager = LogManager::getInstance();
	// verify visibility has changed
	if (p_object->isVisible() == visibility)
		return 0;

	// figure out right level
	int onLevel = _level;
	if (p_object->isPersistent())
		onLevel = 0;

	// if was visible then now invisible, so remove from list
	if (p_object->isVisible())
	{
		if (_visibleObjects[onLevel][p_object->getAltitude()].remove(p_object))
		{
			logManager.writeLog(LOG_ERROR,
				"SceneGraph::updateVisibility()",
				"Removing from visible list failed.\n");
			return -1;
		}
	}
	else // was invisible, so add to list
	{
		if (_visibleObjects[onLevel][p_object->getAltitude()].insert(p_object))
		{
			logManager.writeLog(LOG_ERROR,
				"SceneGraph::updateVisibility()",
				"Inserting to visible list failed.\n");
			return -1;
		}
	}

	return 0;
}

/**
 * Sets the games current level.
 * @param level The level to set.
 * @return Returns 0 if ok, else -1.
 */
int SceneGraph::setLevel(int level)
{
	LogManager &logManager = LogManager::getInstance();
	
	if (!valueInRange(level, 0, MAX_LEVEL))
	{
		logManager.writeLog(LOG_ERROR,
			"SceneGraph::setLevel()",
			"Level value %d is not in the allowed range.\n",
			level);
		return -1;
	}

	_level = level;
	return 0;
}

/**
 * Gets the games current level.
 * @return The current level.
 */
int SceneGraph::getLevel(void)
{
	return _level;
}
