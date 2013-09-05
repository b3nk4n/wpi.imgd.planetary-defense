/*******************************************************************************
 * @file        ObjectList.cpp
 * @author      bsautermeister
 * @description Basic list collection for storing, interating and accessing 
 *              game objects efficiently.
 ******************************************************************************/

#include "ObjectList.h"

/**
 * Creates a new game object list instance.
 */
ObjectList::ObjectList(void)
{
	_count = 0;
}

/**
 * Cleans up the game object list.
 */
ObjectList::~ObjectList(void)
{
	clear();
}

/**
 * Creates a game object interator instance.
 */
/*ObjectListIterator ObjectList::createIterator() const
{

}*/

/**
 * Inserts a new object to the list.
 * @param p_object The object to add.
 * @return Returns 0 if insertion was successful, in case of error -1.
 */
int ObjectList::insert(Object *p_object)
{
	// verify list is not full
	if (isFull())
		return -1;

	_list[_count++] = p_object;
	return 0;
}

/**
 * Removes an object from the list.
 * The object list also keeps its order and is everytime gapless.
 * @param p_object The object to remove.
 * @return Returns 0 if object was found and removed, else -1.
 */
int ObjectList::remove(Object *p_object)
{
	for (int i = 0; i < _count; ++i)
	{
		// check if referenced object was found
		if (_list[i] == p_object)
		{
			// keep the list order and gapless
			for (int j = i; j < _count; ++j)
			{
				_list[j] = _list[j + 1];
			}

			--_count;

			return 0;
		}
	}

	// object was not found
	return -1;
}

/**
 * Clears the game object list.
 */
void ObjectList::clear(void)
{
	_count = 0;
}

/**
 * Gets the game object list current size.
 * @return The current list size.
 */
int ObjectList::getCount(void)
{
	return _count;
}

/**
 * Gets whether the object list is empty.
 * @return Returns TRUE when the list is empty, else FALSE.
 */
bool ObjectList::isEmpty(void)
{
	return _count == 0;
}

/**
 * Gets whether the object list is full.
 * @return Returns TRUE when the list is full, else FALSE.
 */
bool ObjectList::isFull(void)
{
	return _count == MAX_OBJECTS;
}
