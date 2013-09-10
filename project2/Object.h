/*******************************************************************************
 * @file        Object.h
 * @author      bsautermeister
 * @description The bass class for all game objects representing an object in
 *              the game world.
 ******************************************************************************/

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>
#include "Position.h"
#include "Event.h"

using std::string;

#define TYPE_OBJECT "Object"
#define MAX_OBJ_EVENTS 64

/**
 * Represents a game object in the game world.
 */
class Object
{
private:
	/**
	 * The type identifier of the object.
	 */
	string _type;

	/**
	 * The objects position in the game world.
	 */
	Position _position;

	/**
	 * The number of registerd events.
	 */
	int _eventCount;

	/**
	 * The registerd event types.
	 */
	string _eventTypes[MAX_OBJ_EVENTS];

public:
	/**
	* Creates a game object instance.
	* NOTE: Game objects MUST be created on heap via 'new' because they will be 
	*       deleted via 'delete' in the world manager.
	*/
	Object(void);

	/**
	 * Cleans up the game object.
	 */
	virtual ~Object(void);

	/**
	 * Handles events, while default is to ignore all events.
	 * @param p_event Points to the current event to handle.
	 * @return Return 0 if ignored, else 1 if event was handled.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Registers its interest for an event. Keeps track of manager and event.
	 * @param eventType The event type name.
	 * @return Returns 0 if ok, else -1.
	 */
	int registerInterest(string eventType);

	/**
	 * Unregisters its interest for an event.
	 * @note doesn't check if game object has already been registered.
	 * @param eventType The event type name.
	 * @return Returns 0 if ok, else -1.
	 */
	int unregisterInterest(string eventType);

	/**
	 * Gets the game objects type.
	 * @return The game object type.
	 */
	string getType(void);

	/**
	 * Sets the game objects type.
	 * @param type The new game object type.
	 */
	void setType(string type);

	/**
	 * Gets the game objects position in the game world.
	 * @return The game object position.
	 */
	Position getPosition(void);

	/**
	 * Sets the game objects position in the game world.
	 * @param position The new game objects position.
	 */
	void setPosition(Position position);
};

#endif
