/*******************************************************************************
 * @file        ObjectList.h
 * @author      bsautermeister
 * @description Basic list collection for storing, interating and accessing 
 *              game objects efficiently.
 ******************************************************************************/

#ifndef __OBJECT_LIST_H__
#define __OBJECT_LIST_H__

#include "Object.h"
#include "ObjectListIterator.h"

// forward referencing
class ObjectListIterator;

#define INIT_LIST_SIZE 128

/**
 * Class representing a iterable and efficient list of game objects.
 */
class ObjectList
{
private:
	/**
	 * The current objects count of the list.
	 */
	int _count;

	/**
	 * The current object capacity of the list.
	 */
	int _capacity;

	/**
	 * The fixed/static array of pointers to game objects
	 * with initial size of INIT_LIST_SIZE.
	 */
	Object **_pp_data;

public:
	/**
	 * Creates a new game object list instance.
	 */
	ObjectList(void);

	/**
	 * Deep copy constructor to create a copy of another list.
	 * @param otherList The other list to copy over.
	 */
	ObjectList(const ObjectList &otherList);

	/**
	 * Cleans up the game object list.
	 */
	~ObjectList(void);

	/**
	 * The friend iterator class.
	 */
	friend class ObjectListIterator;

	/**
	 * Creates a game object interator instance.
	 */
	ObjectListIterator createIterator() const;

	/**
	 * Inserts a new object to the list.
	 * @param p_object The object to add.
	 * @return Returns 0 if insertion was successful, in case of error -1.
	 */
	int insert(Object *p_object);

	/**
	 * Removes an object from the list.
	 * @param p_object The object to remove.
	 * @return Returns 0 if object was found and removed, else -1.
	 */
	int remove(Object *p_object);

	/**
	 * Clears the game object list.
	 */
	void clear(void);

	/**
	 * Gets the game object list current size.
	 * @return The current list size.
	 */
	int getCount(void);

	/**
	 * Gets whether the object list is empty.
	 * @return Returns TRUE when the list is empty, else FALSE.
	 */
	bool isEmpty(void);

	/**
	 * Gets whether the object list is full and needs a reallocation.
	 * @return Returns TRUE when the list is full and needs to be reallocated, else FALSE.
	 */
	bool reachedCapacity(void);

	/**
	 * Appends the second list to the first list. It appends as much as it can.
	 * @param otherList The list to append.
	 * @return The concatenated list.
	 */
	ObjectList operator+(ObjectList otherList);

	/**
	 * Assigns an other lists values to this object list by deep copy.
	 * @param otherList The other object list to assign from.
	 */
	ObjectList &operator=(const ObjectList &otherList);
};

#endif
