/*******************************************************************************
 * @file        ObjectListIterator.h
 * @author      bsautermeister
 * @description Iterator for the game object list to travers a list efficiently.
 ******************************************************************************/

#ifndef __OBJECT_LIST_ITERATOR_H__
#define __OBJECT_LIST_ITERATOR_H__

#include "ObjectList.h"

// forward referencing
class ObjectList;

/**
 * Class representing an iterator to travers an object list.
 */
class ObjectListIterator
{
private:
	/**
	 * Points to the list to iterate over.
	 */
	const ObjectList *_p_list;

	/**
	 * The index of the current item.
	 */
	int _index;

	/**
	 * Hides the default constructor because a list must be given.
	 */
	ObjectListIterator(void);

public:
	/**
	 * Creates a new object list iterator instance.
	 * @param p_list The object list to iterate over.
	 */
	ObjectListIterator(const ObjectList *p_list);

	/**
	 * Cleans up the object list.
	 */
	~ObjectListIterator(void);

	/**
	 * Sets the iterator to the first object of the list.
	 */
	void first(void);

	/**
	 * Moves the iterator to the next object of the list.
	 */
	void next(void);

	/**
	 * Indicates whether the traversion is finished.
	 * @return Returns TRUE when the end of the list has been reached.
	 */
	bool isDone(void);

	/**
	 * Gets the current object.
	 * @return The current object or NULL if isDone() is TRUE.
	 */
	Object *currentObject(void);
};

#endif
