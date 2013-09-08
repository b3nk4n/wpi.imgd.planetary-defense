/*******************************************************************************
 * @file        ObjectListIterator.cpp
 * @author      bsautermeister
 * @description Iterator for the game object list to travers a list efficiently.
 ******************************************************************************/

#include "ObjectListIterator.h"

/**
 * Hides the default constructor because a list must be given.
 */
ObjectListIterator::ObjectListIterator(void)
{
}

/**
 * Creates a new object list iterator instance.
 * @param p_list The object list to iterate over.
 */
ObjectListIterator::ObjectListIterator(const ObjectList *p_list)
{
	_p_list = p_list;
	first();
}

/**
 * Cleans up the object list.
 */
ObjectListIterator::~ObjectListIterator(void)
{
	_p_list = NULL;
}

/**
 * Sets the iterator to the first object of the list.
 */
void ObjectListIterator::first(void)
{
	_index = 0;
}

/**
 * Moves the iterator to the next object of the list.
 */
void ObjectListIterator::next(void)
{
	++_index;
}

/**
 * Indicates whether the traversion is finished.
 * @return Returns TRUE when the end of the list has been reached.
 */
bool ObjectListIterator::isDone(void)
{
	return _index == (_p_list->_count);
}

/**
 * Gets the current object.
 * @return The current object or NULL if isDone() is TRUE.
 */
Object *ObjectListIterator::currentObject(void)
{
	return _p_list->_pp_data[_index];
}

