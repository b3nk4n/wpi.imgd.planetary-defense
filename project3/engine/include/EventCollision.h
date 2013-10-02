/*******************************************************************************
 * @file        EventCollision.h
 * @author      bsautermeister
 * @description Collision event class to notify other solid game objects if 
 *              a collision has occured.
 ******************************************************************************/

#ifndef __EVENT_COLLISION_H__
#define __EVENT_COLLISION_H__

#include "Event.h"
#include "Object.h"

#define COLLISION_EVENT "__collision__"

/**
 * The collision event class.
 */
class EventCollision : public Event
{
private:
	/**
	 * The collisions position.
	 */
	Position _position;

	/**
	 * The object moving which caused the collision.
	 */
	Object *_p_object1;

	/**
	 * The other object beeing collided with.
	 */
	Object *_p_object2;
	
public:
	/**
	 * Creates a new collision event instance with default positin
	 * and both objects set to NULL.
	 */
	EventCollision();

	/**
	 * Creates a new collision event instance.
	 * @param p_obj1 The frist object in move.
	 * @param p_obj2 The second object.
	 * @param position The collisions position.
	 */
	EventCollision(Object *p_obj1, Object *p_obj2, Position position);

	/**
	 * Gets the first object, which is in move.
	 * @return Pointer to the object in move.
	 */
	Object *getObject1(void);

	/**
	 * Sets the first object, which is in move.
	 * @param p_obj Pointer to the object in move.
	 */
	void setObject1(Object *p_obj);

	/**
	 * Gets the second object.
	 * @return Pointer to the other object.
	 */
	Object *getObject2(void);

	/**
	 * Sets the second object.
	 * @param p_obj Pointer to the other object.
	 */
	void setObject2(Object *p_obj);

	/**
	 * Gets the collisions position.
	 * @return The collision position.
	 */
	Position getPosition(void);

	/**
	 * Sets the collisions position.
	 * @param The collision 
	 */
	void setPosition(Position position);
};

#endif
