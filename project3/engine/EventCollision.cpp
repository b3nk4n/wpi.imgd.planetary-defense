/*******************************************************************************
* @file        EventCollision.cpp
* @author      bsautermeister
* @description Collision event class to notify other solid game objects if 
*              a collision has occured.
******************************************************************************/

#include "EventCollision.h"

/**
 * Creates a new collision event instance with default positin
 * and both objects set to NULL.
 */
EventCollision::EventCollision()
{
	setType(COLLISION_EVENT);
	setObject1(NULL);
	setObject2(NULL);
}

/**
 * Creates a new collision event instance.
 * @param p_obj1 The frist object in move.
 * @param p_obj2 The second object.
 * @param position The collisions position.
 */
EventCollision::EventCollision(Object *p_obj1, Object *p_obj2, Position position)
{
	setType(COLLISION_EVENT);
	setObject1(p_obj1);
	setObject2(p_obj2);
	setPosition(position);
}

/**
 * Gets the first object, which is in move.
 * @return Pointer to the object in move.
 */
Object *EventCollision::getObject1(void)
{
	return _p_object1;
}

/**
 * Sets the first object, which is in move.
 * @param p_obj Pointer to the object in move.
 */
void EventCollision::setObject1(Object *p_obj)
{
	_p_object1 = p_obj;
}

/**
 * Gets the second object.
 * @return Pointer to the other object.
 */
Object *EventCollision::getObject2(void)
{
	return _p_object2;
}

/**
 * Sets the second object.
 * @param p_obj Pointer to the other object.
 */
void EventCollision::setObject2(Object *p_obj)
{
	_p_object2 = p_obj;
}

/**
 * Gets the collisions position.
 * @return The collision position.
 */
Position EventCollision::getPosition(void)
{
	return _position;
}

/**
 * Sets the collisions position.
 * @param The collision position.
 */
void EventCollision::setPosition(Position position)
{
	_position = position;
}
