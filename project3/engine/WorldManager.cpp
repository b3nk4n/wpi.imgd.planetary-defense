/*******************************************************************************
 * @file        WorldManager.cpp
 * @author      bsautermeister
 * @description Manages the game world by efficiently organising all active and
 *              deletabble game objects.
 ******************************************************************************/

#include "WorldManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "utility.h"
#include "ViewObject.h"

/**
 * Creates a world manager instance.
 */
WorldManager::WorldManager(void)
{
	// default world and view is empty
	_worldBoundary.setHorizontal(0);
	_worldBoundary.setVertical(0);
	_viewBoundary.setHorizontal(0);
	_viewBoundary.setVertical(0);

	_nextLevel = 0;
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
	// verify manager is started;
	if (!_isStarted)
		return;
	
	// cleanup world objects
	clearAllObjects(); // TODO: reinclude code

	_isStarted = false;
}

/**
 * Adds a new object to the game world.
 * @parem p_object The game object to add.
 * @return Return 0 if insertion was successful, in case of error -1.
 */
int WorldManager::insertObject(Object *p_object)
{
	return _sceneGraph.insertObject(p_object);
}

/**
 * Removes an object from the game world.
 * @parem p_object The game object to remove.
 * @return Return 0 if removing was successful, in case of error -1.
 */
int WorldManager::removeObject(Object *p_object)
{
	return _sceneGraph.removeObject(p_object);
}

/**
 * Gets all game objects of the game world.
 * @return The list of all game objects.
 */
ObjectList WorldManager::getAllObjects(void)
{
	return _sceneGraph.allObjects();
}

/**
 * Clears all game objects in the world of all levels.
 */
void WorldManager::clearAllObjects(void)
{
	// NOTE: create a copy of the  list here, because each time 'delete obj'
	//       is called in the game objects desctructor the original list 
	//       will be manipulated (causes iterator problems)
	ObjectList updatesListCopy = _sceneGraph.allObjectsOfAllLevels();
	
	ObjectListIterator it(&updatesListCopy);
	for (it.first(); !it.isDone(); it.next())
	{
		delete it.currentObject();
	}

	// clear all levels
	int oldLevel = _sceneGraph.getLevel();
	for (int i = 0; i <= MAX_LEVEL; ++i)
	{
		_sceneGraph.setLevel(i);
		_sceneGraph.clearAllObjects();
	}
	_sceneGraph.setLevel(oldLevel);

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

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
		"WorldManager::markForDelete()",
		"One object marked for delete\n");

	return 0;
}

/**
 * Updates game world and deleted all marked objects.
 * @param delta The elapsed game time in seconds.
 */
void WorldManager::update(float delta)
{
	LogManager &logManager = LogManager::getInstance();

	// update positions based on their velocities
	ObjectList allObjects = _sceneGraph.allObjects();
	ObjectListIterator itVelocity(&allObjects);
	for (itVelocity.first(); !itVelocity.isDone(); itVelocity.next())
	{
		Object *p_currentObject = itVelocity.currentObject();
		int x = p_currentObject->getVelocityXStep();
		int y = p_currentObject->getVelocityYStep();

		// move object if necessary
		if (x != 0 || y != 0)
		{
			Position oldPosition = p_currentObject->getPosition();
			Position newPosition = Position(oldPosition.getX() + x, oldPosition.getY() + y);

			moveObject(p_currentObject, newPosition);
		}
	}

	// delete all marked objects
	ObjectListIterator itDelete(&_deletions);
	for (itDelete.first(); !itDelete.isDone(); itDelete.next())
	{
		// NOTE: game object removes itself from the _updates list
		//       via removeObject() in its desctructor
		delete itDelete.currentObject();
	}

	// clear deletion list for next update
	_deletions.clear();

	// change level if it was requested
	if (_nextLevel)
	{
		_sceneGraph.setLevel(_nextLevel);
		_nextLevel = 0;
	}
}

/**
 * Renders all game objects.
 */
void WorldManager::draw(void)
{
	// draw view layer by view layer
	for (int a = MIN_ALTITUDE; a <= MAX_ALTITUDE; ++a)
	{
		ObjectList visibleObjects = _sceneGraph.visibleObjects(a);

		ObjectListIterator it(&visibleObjects);
		for (it.first(); !it.isDone(); it.next())
		{
			Object *p_object = it.currentObject();
			
			// convert bounding box to world coordinates
			Box worldBox = getWorldBox(p_object);

			// only draw if object is visible on screen
			if (boxIntersectsBox(worldBox, _viewBoundary) ||
				dynamic_cast<ViewObject *>(p_object))
				p_object->draw();
		}
	}
}

/**
 * Gets the list of objects colliding with an objects at the given position.
 * @param p_object The object to check, no matter if its solid or not.
 * @param box The box to check.
 * @return Returns list of objects collided with at given position.
 */
ObjectList WorldManager::isCollision(Object *p_object, Box box)
{
	// create an empty list for collisions
	ObjectList collisionList;

	// check all objects for collision
	ObjectList solidObjects = _sceneGraph.solidObjects();
	ObjectListIterator it(&solidObjects);
	for (it.first(); !it.isDone(); it.next())
	{
		Object *p_currentObject = it.currentObject();

		// do not consider self
		if (p_currentObject != p_object)
		{
			// verify same position and same solidness
			if (boxIntersectsBox(getWorldBox(p_currentObject), box) &&
				p_currentObject->isSolid())
			{
				collisionList.insert(p_currentObject);
			}
		}
	}

	return collisionList;
}

/**
 * Tries to move the object to the designited position if possible.
 * @param p_object The object to move (move OK if spectral)
 * @param position The position to move to.
 * @return Returns 0 if ok, else -1 for collision with solid object.
 */
int WorldManager::moveObject(Object *p_object, Position position)
{
	LogManager &logManager = LogManager::getInstance();

	// objct must be solid for collision
	if (p_object->isSolid())
	{
		// calculate bounding box of probable next position
		 Box nextBox = getWorldBox(p_object);
		 int dx = position.getX() - p_object->getPosition().getX();
		 int dy = position.getY() - p_object->getPosition().getY();
		 nextBox.setCorner(Position(
		 	nextBox.getCorner().getX() + dx,
		 	nextBox.getCorner().getY() + dy));

		// get collisions
		ObjectList collisionList = isCollision(p_object, nextBox);

		if (!collisionList.isEmpty())
		{
			bool canMove = true;

			logManager.writeLog(LOG_DEBUG,
				"WorldManager::moveObject()",
				"box: x=%d, y=%d, h=%d, v=%d\n",
				nextBox.getCorner().getX(),
				nextBox.getCorner().getY(),
				nextBox.getHorizontal(),
				nextBox.getVertical());
			logManager.writeLog(LOG_DEBUG,
				"WorldManager::moveObject()",
				"list count: %d\n",
				collisionList.getCount());

			ObjectListIterator it(&collisionList);
			for (it.first(); !it.isDone(); it.next())
			{
				Object *p_currentObject = it.currentObject();

				logManager.writeLog(LOG_DEBUG,
				"WorldManager::moveObject()",
				"coll list iterating\n");
				logManager.writeLog(LOG_DEBUG,
				"WorldManager::moveObject()",
				"is solid: %s\n",
				p_currentObject->isSolid() ? "true" : "false");
				logManager.writeLog(LOG_DEBUG,
				"WorldManager::moveObject()",
				"type: %s\n",
				p_currentObject->getType().c_str());

				// send collision event to both
				EventCollision eventCollision(p_object, p_currentObject, position);
				if (p_object->isInterestedInEvent(eventCollision.getType()))
				{
					logManager.writeLog(LOG_DEBUG,
						"WorldManager::moveObject()",
						"Fireing first collision event\n");
					p_object->eventHandler(&eventCollision);
				}
				if (p_currentObject->isInterestedInEvent(eventCollision.getType()))
				{
					logManager.writeLog(LOG_DEBUG,
						"WorldManager::moveObject()",
						"Fireing second collision event\n");
					p_currentObject->eventHandler(&eventCollision);
				}

				// verify not moving when hard objects are colliding
				if (p_object->getSolidness() == HARD &&
					p_currentObject->getSolidness() == HARD)
					canMove = false;

				// verify not moving when no soft objects are allowed to move
				if (p_object->getNoSoft() &&
					p_currentObject->getSolidness() == SOFT)
					canMove = false;
			}

			if (!canMove)
				return -1;
		}
	}

	GraphicsManager &graphicsManager = GraphicsManager::getInstance();

	// check if object was inside screen before move
	bool insideBeforeMove = boxIntersectsBox(
		Box(Position(),
			graphicsManager.getHorizontal(),
			graphicsManager.getVertical()),
		getWorldBox(p_object));

	// if here, no collision occued to move is allowed
	p_object->setPosition(position);

	// verify the object has left the screen.
	if (insideBeforeMove &&
		!boxIntersectsBox(
			Box(Position(),
				graphicsManager.getHorizontal(),
				graphicsManager.getVertical()),
			getWorldBox(p_object)))
	{
		EventOut eventOut;
		if (p_object->isInterestedInEvent(eventOut.getType()))
		{
			p_object->eventHandler(&eventOut);
		}
	}

	// if view is following this object, adjust the view bounds
	if (_p_viewFollowing == p_object)
	{
		setViewPosition(p_object->getPosition());
	}

	return 0;
}

/**
 * Validates if event is handles by this manager.
 * @param eventType The event type name.
 * @return Returns TRUE if event is handled, else FALSE.
 */
bool WorldManager::isValid(string eventType)
 {
 	return eventType != STEP_EVENT &&
 		eventType != MOUSE_EVENT &&
 		eventType != KEYBOARD_EVENT;
 }

 /**
 * Gets a reference to the screne graph.
 * @return The worlds screne graph.
 */
SceneGraph &WorldManager::getSceneGraph(void)
{
	return _sceneGraph;
}

  /**
  * Sets the view to center screen on position the specified position
  * @note The view edge will not go bexound the world boundries
  * @param worldPosition The view position to look to.
  */
void WorldManager::setViewPosition(Position worldPosition)
{
	LogManager &logManager = LogManager::getInstance();

	// ensure horizontal not out of world bounds
	int x = worldPosition.getX() - _viewBoundary.getHorizontal() / 2;
	if (x + _viewBoundary.getHorizontal() > _worldBoundary.getHorizontal())
		x = _worldBoundary.getHorizontal() - _viewBoundary.getHorizontal();
	else if (x < 0)
		x = 0;

	// ensure vertical not out of world bounds
	int y = worldPosition.getY() - _viewBoundary.getVertical() / 2;
	if (y + _viewBoundary.getVertical() > _worldBoundary.getVertical())
		y = _worldBoundary.getVertical() - _viewBoundary.getVertical();
	else if (y < 0)
		y = 0;

	// set view
	 _viewBoundary.setCorner(Position(x, y));

	 logManager.writeLog(LOG_DEBUG,
				"WorldManager::setViewPosition()",
				"Updated camera bounds to: x=%d, y=%d, h=%d, v=%d\n",
				_viewBoundary.getCorner().getX(),
				_viewBoundary.getCorner().getY(),
				_viewBoundary.getHorizontal(),
				_viewBoundary.getVertical());
}

/**
 * Sets the view to center screen on object.
 * @param p_viewFollowing The object to follow or NULL to stop following.
 * @return Returns 0 if ok, else -1.
 */
int WorldManager::setViewFollowing(Object *p_viewFollowing)
{
	// check disabling object following
	if (!p_viewFollowing)
	{
		_p_viewFollowing = NULL;
		return 0;
	}

	// verify the requested object to follow exists
	bool found = false;
	ObjectList allObjects = getAllObjects();
	ObjectListIterator it(&allObjects);
	for (it.first(); !it.isDone(); it.next())
	{
		if (it.currentObject() == p_viewFollowing)
		{
			found = true;
			break;
		}
	}

	// if found, adjust attribute accordingly and set view position
	if (found)
	{
		_p_viewFollowing = p_viewFollowing;
		setViewPosition(_p_viewFollowing->getPosition());
		return 0;
	}

	return -1;
}

/**
 * Gets the world boundary.
 * @return The world boundary.
 */
Box WorldManager::getWorldBoundary(void)
{
	return _worldBoundary;
}

/**
 * Sets the world boundary.
 * @param world The world boundary.
 */
void WorldManager::setWorldBoundary(Box world)
{
	_worldBoundary = world;
}

/**
 * Gets the view boundary.
 * @return The view boundary.
 */
Box WorldManager::getViewBoundary(void)
{
	return _viewBoundary;
}

/**
 * Sets the view boundary.
 * @param view The view boundary.
 */
void WorldManager::setViewBoundary(Box view)
{
 	_viewBoundary = view;
}

/**
 * Gets the current game level.
 * @return The current game level.
 */
int WorldManager::getLevel(void)
{
 	return _sceneGraph.getLevel();
}

/**
 * Sets the current game level at the end of world managers update.
 * @param level The new game level.
 * @return Returns 0 if ok, else -1.
 */
int WorldManager::setLevel(int level)
{
	LogManager &logManager = LogManager::getInstance();

	if (!valueInRange(level, 0, MAX_LEVEL))
	{
		logManager.writeLog(LOG_ERROR,
			"WorldManager::setLevel()",
			"Level value %d is not in the allowed range.\n",
			level);
		return -1;
	}

	_nextLevel = level;
	return 0;
}
