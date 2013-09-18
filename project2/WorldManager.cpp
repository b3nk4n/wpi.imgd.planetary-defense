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
#include "Box.h"
#include "utility.h"

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
	// verify manager is started;
	if (!_isStarted)
		return;
	
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
	// NOTE: create a copy of the _updates list here, because each time 'delete obj'
	//       is called in the game objects desctructor the original _updates list 
	//       will be manipulated (causes iterator problems)
	ObjectList updatesListCopy = _updates;
	
	ObjectListIterator it(&updatesListCopy);
	for (it.first(); !it.isDone(); it.next())
	{
		delete it.currentObject();
	}

	_updates.clear();
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
	ObjectListIterator itVelocity(&_updates);
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
}

/**
 * Renders all game objects.
 */
void WorldManager::draw(void)
{
	// draw view layer by view layer
	for (int a = MIN_ALTITUDE; a < MAX_ALTITUDE; ++a)
	{
		ObjectListIterator it(&_updates);
		for (it.first(); !it.isDone(); it.next())
		{
			Object *p_object = it.currentObject();
			
			if (p_object->getAltitude() == a)
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
	LogManager &logManager = LogManager::getInstance();
	// create an empty list for collisions
	ObjectList collisionList;

	// check all objects for collision
	ObjectListIterator it(&_updates);
	for (it.first(); !it.isDone(); it.next())
	{
		Object *p_currentObject = it.currentObject();

		// do not consider self
		if (p_currentObject != p_object)
		{
			logManager.writeLog(LOG_DEBUG,
				"WorldManager::isCollision()",
				"Checking (x=%d,y=%d,h=%d,v=%d) and (x=%d,y=%d,h=%d,v=%d)\n",
				p_currentObject->getBox().getCorner().getX(),
				p_currentObject->getBox().getCorner().getY(),
				p_currentObject->getBox().getHorizontal(),
				p_currentObject->getBox().getVertical(),
				box.getCorner().getX(),
				box.getCorner().getY(),
				box.getHorizontal(),
				box.getVertical());

			// verify same position and same solidness
			if (boxIntersectsBox(p_currentObject->getBox(), box) &&
				p_currentObject->isSolid())
			{
				logManager.writeLog(LOG_DEBUG,
				"WorldManager::isCollision()",
				"Collision!\n");
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
		 Box nextBox = p_object->getBox();
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

			ObjectListIterator it(&collisionList);
			for (it.first(); !it.isDone(); it.next())
			{
				Object *p_currentObject = it.currentObject();

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
		p_object->getBox());

	// if here, no collision occued to move is allowed
	p_object->setPosition(position);

	// verify the object has left the screen.
	if (insideBeforeMove &&
		!boxIntersectsBox(
			Box(Position(),
				graphicsManager.getHorizontal(),
				graphicsManager.getVertical()),
			p_object->getBox()))
	{
		EventOut eventOut;
		if (p_object->isInterestedInEvent(eventOut.getType()))
		{
			logManager.writeLog(LOG_DEBUG,
				"WorldManager::moveObject()",
				"Fireing out event\n");
			p_object->eventHandler(&eventOut);
		}
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
