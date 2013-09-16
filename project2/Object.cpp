/*******************************************************************************
 * @file        Object.cpp
 * @author      bsautermeister
 * @description The bass class for all game objects representing an object in
 *              the game world.
 ******************************************************************************/

#include <math.h>
#include "Object.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "InputManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "EventKeyboard.h"
#include "EventMouse.h"

/**
 * Creates a game object instance.
 * NOTE: Game objects MUST be created on heap via 'new' because they will be 
 *       deleted via 'delete' in the world manager.
 */
Object::Object(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	LogManager &logManager = LogManager::getInstance();

	setType(TYPE_OBJECT);
	setSolidness(HARD);

	_velocityX = 0;
	_velocityXCountdown = 0;
	_velocityY = 0;
	_velocityYCountdown = 0;

	_noSoft = false;

	_eventCount = 0;
	_altitude = MAX_ALTITUDE / 2;

	// add itself to the world manager
	if (worldManager.insertObject(this))
	{
		logManager.writeLog(LOG_ERROR,
			"Object::Object()",
			"Objects could not be registered to the world\n");
	}
}

/**
 * Cleans up the game object.
 */
Object::~Object(void)
{
	LogManager &logManager = LogManager::getInstance();

	// unregister all event interests
	for (int i = 0; i < _eventCount; ++i)
	{
		if (unregisterInterest(_eventTypes[i]))
		{
			logManager.writeLog(LOG_ERROR,
				"Object::~Object()",
				"Uregister of event %s failed\n",
				_eventTypes[i].c_str());
		}
	}

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
 * Registers its interest for an event. Keeps track of manager and event.
 * @param eventType The event type name.
 * @return Returns 0 if ok, else -1.
 */
int Object::registerInterest(string eventType)
{
	int regResult;
	// check if event limit has reached
	if (_eventCount == MAX_OBJ_EVENTS)
		return -1;

	GameManager &gameManager = GameManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();
	InputManager &inputManager = InputManager::getInstance();

	// register with appropriate manager
	if (eventType == STEP_EVENT)
		regResult = gameManager.registerInterest(this, eventType);
	else if (eventType == KEYBOARD_EVENT || eventType == MOUSE_EVENT)
		regResult = inputManager.registerInterest(this, eventType);
	else
		regResult = worldManager.registerInterest(this, eventType);

	// keep track of aded event
	_eventTypes[_eventCount] = eventType;
	++_eventCount;


	return regResult;
}

/**
 * Unregisters its interest for an event.
 * @note doesn't check if game object has already been registered.
 * @param eventType The event type name.
 * @return Returns 0 if ok, else -1.
 */
int Object::unregisterInterest(string eventType)
{
	// find the registerd event
	for (int i = 0; i < _eventCount; ++i)
	{
		if (_eventTypes[i] == eventType)
		{
			GameManager &gameManager = GameManager::getInstance();
			WorldManager &worldManager = WorldManager::getInstance();
			InputManager &inputManager = InputManager::getInstance();

			// unregister event from appropriate manager
			if (eventType == STEP_EVENT)
				gameManager.unregisterInterest(this, eventType);
			else if (eventType == KEYBOARD_EVENT || eventType == MOUSE_EVENT)
				inputManager.unregisterInterest(this, eventType);
			else
				worldManager.unregisterInterest(this, eventType);

			// scoot over events
			for (int j = i; j < _eventCount - 1; ++j)
				_eventTypes[j] = _eventTypes[j + 1];

			--_eventCount;

			return 0;
		}
	}

	// event type has not been registerd
	return -1;
}

/**
 * Renders the game object.
 */
void Object::draw(void)
{

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

/**
 * Gets the x velocity.
 * @return The x velocity.
 */
float Object::getVelocityX(void)
{
	return _velocityX;
}

/**
 * Sets the x velocity.
 * @param velocity The x velocity.
 */
void Object::setVelocityX(float velocity)
{
	_velocityXCountdown = 1;
	_velocityX = velocity;
}

/**
 * Gets the y velocity.
 * @return The y velocity.
 */
float Object::getVelocityY(void)
{
	return _velocityY;
}

/**
 * Sets the y velocity.
 * @param velocity The y velocity.
 */
void Object::setVelocityY(float velocity)
{
	_velocityYCountdown = 1;
	_velocityY = velocity;
}

/**
 * Gets the horizontal direction perfomed in one step.
 * @return The horizontal movement distance for this step.
 */
int Object::getVelocityXStep(void)
{
	// verify there is any x velocity
	if (_velocityX == 0)
		return 0;

	// check for moving in this step
	_velocityXCountdown -= fabs(_velocityX);
	if (_velocityXCountdown > 0)
		return 0;

	// moveing this step, calculate how far
	int spaces = (int)floor(1 - _velocityXCountdown);
	_velocityXCountdown = 1 + fmod(_velocityXCountdown, 1);

	// check direction left/right
	if (_velocityX < 0)
		spaces *= -1;

	return spaces;
}

/**
 * Gets the vertical direction perfomed in one step.
 * @return The vertical movement distance for this step.
 */
int Object::getVelocityYStep(void)
{
	// verify there is any y velocity
	if (_velocityY == 0)
		return 0;

	// check for moving in this step
	_velocityYCountdown -= fabs(_velocityY);
	if (_velocityYCountdown > 0)
		return 0;

	// moveing this step, calculate how far
	int spaces = (int)floor(1 - _velocityYCountdown);
	_velocityYCountdown = 1 + fmod(_velocityYCountdown, 1);

	// check direction up down
	if (_velocityY < 0)
		spaces *= -1;

	return spaces;
}

/**
 * Sets the verifies the altitude/depth of the object.
 * @param value The new altitude value.
 * @return Returns 0 if ok, else -1.
 */
int Object::setAltitude(int value)
{
	if (value < MIN_ALTITUDE || MAX_ALTITUDE < value)
		return -1;

	_altitude = value;
	return 0;
}

/**
 * Gets the objects altitude/depth.
 * @return The objects altitude.
 */
int Object::getAltitude(void)
{
	return _altitude;
}

/**
 * Checks whether the object is solid or not.
 * @return Returns TRUE if the game object is solid, else FALSE.
 */
bool Object::isSolid(void)
{
	return _solidness != SPECTRAL;
}

/**
 * Sets the solidness of the game object.
 * @param value The new solidness value.
 * @return Returns 0 if ok, else -1.
 */
int Object::setSolidness(Solidness value)
{
	if (value != HARD &&
		value != SOFT &&
		value != SPECTRAL)
		return -1;

	_solidness = value;
	return 0;
}

/**
 * Gets the game objects solidness.
 * @return The solidness.
 */
Solidness Object::getSolidness(void)
{
	return _solidness;
}

/**
 * Gets the no soft value.
 * @return The no soft value.
 */
bool Object::getNoSoft(void)
{
	return _noSoft;
}

/**
 * Sets the no soft value.
 * @param The no soft value.
 */
void Object::setNoSoft(bool value)
{
	_noSoft = value;
}
