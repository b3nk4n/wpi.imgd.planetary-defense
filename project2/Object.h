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

using std::string;

#define TYPE_OBJECT "Object"

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

public:
	/**
	 * Creates a game object instance.
	 */
	Object(void);

	/**
	 * Cleans up the game object.
	 */
	virtual ~Object(void);

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
