/*******************************************************************************
 * @file        ObjectList.cpp
 * @author      bsautermeister
 * @description Basic list collection for storing, interating and accessing 
 *              game objects efficiently.
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ObjectList.h"
#include "LogManager.h"

/**
 * Creates a new game object list instance.
 */
ObjectList::ObjectList(void)
{
	_count = 0;
	_capacity = 0;

	// allocate memory dynamically
	_pp_data = (Object **)malloc(sizeof(Object*) * INIT_LIST_SIZE);
	
	// verify memory allocation was successful
	if (_pp_data == NULL)
	{
		perror("Memory allocation of object list failed.");
		return;
	}

	_capacity = INIT_LIST_SIZE;
}

/**
 * Deep copy constructor to create a copy of another list.
 * @param otherList The other list to copy over.
 */
ObjectList::ObjectList(const ObjectList &otherList)
{
	// allocate memory dynamically
	_pp_data = (Object **)malloc(sizeof(Object*) * otherList._capacity);

	// verify memory allocation was successful
	if (_pp_data == NULL)
	{
		perror("Memory allocation of object list failed.");
		return;
	}

	// copy over the data
	memcpy(_pp_data, otherList._pp_data, sizeof(Object *) * otherList._count);

	// adjust size and capacity
	_capacity = otherList._capacity;
	_count = otherList._count;
}

/**
 * Cleans up the game object list.
 */
ObjectList::~ObjectList(void)
{
	clear();
	free(_pp_data);
}

/**
 * Creates a game object interator instance.
 */
ObjectListIterator ObjectList::createIterator() const
{
	return ObjectListIterator(this);
}

/**
 * Inserts a new object to the list.
 * @param p_object The object to add.
 * @return Returns 0 if insertion was successful, in case of error -1.
 */
int ObjectList::insert(Object *p_object)
{
	// verify object
	if (p_object == NULL)
		return -1;

	// verify reallocation of memory required
	if (isFull())
	{
		Object **_pp_newData;
		_pp_newData = (Object **)realloc(_pp_data, 2 * sizeof(Object *) * _capacity);
		
		// verify memory allocation was successful
		if (_pp_newData == NULL)
		{
			perror("Memory reallocation of object list failed.");
			free(_pp_newData);
			return -1;
		}

		// use the new array and 
		_pp_data = _pp_newData;
		_capacity *= 2;
	}

	_pp_data[_count++] = p_object;
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
	// verify object
	if (p_object == NULL)
		return -1;

	for (int i = 0; i < _count; ++i)
	{
		// check if referenced object was found
		if (_pp_data[i] == p_object)
		{
			// keep the list order and gapless
			for (int j = i; j < _count; ++j)
			{
				_pp_data[j] = _pp_data[j + 1];
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
 * Gets whether the object list is full and needs a reallocation.
 * @return Returns TRUE when the list is full and needs to be reallocated, else FALSE.
 */
bool ObjectList::isFull(void)
{
	return _count == _capacity;
}

/**
 * Appends the second list to the first list. It appends as much as it can.
 * @param otherList The list to append.
 * @return The concatenated list.
 */
ObjectList ObjectList::operator+(ObjectList otherList)
{
	// verify other list is not empty
	if (otherList.isEmpty())
		return *this;
	
	Object **_pp_newData;
	int resizeFactor = 2;

	// find best power-of-two resize factor
	while (resizeFactor * _capacity < _count + otherList._count)
		resizeFactor *= 2;

	// reallocate the memory
	_pp_newData = (Object **)realloc(_pp_data, resizeFactor * sizeof(Object *) * _capacity);
	
	// verify memory allocation was successful
	if (_pp_newData == NULL)
	{
		perror("Memory reallocation of object list failed.");
		free(_pp_newData);
		return *this;
	}

	// use the new reallocated memory
	_pp_data = _pp_newData;

	// append the other lists objects
	memcpy(_pp_data + _count, otherList._pp_data, sizeof(Object *) * otherList._count);

	// adjust capacity and count
	_capacity *= resizeFactor;
	_count += otherList._count;

	return *this;
}

/**
 * Assigns an other lists values to this object list by deep copy.
 * @param otherList The other object list to assign from.
 */
ObjectList& ObjectList::operator=(const ObjectList &otherList)
{
	// verify not to assign the same instance
	if (&otherList == this)
		return *this;

	// free previous allocated memory
	if (_pp_data != NULL)
	{
		free(_pp_data);
	}

	// allocate new memory dynamically
	_pp_data = (Object **)malloc(sizeof(Object*) * otherList._capacity);

	// verify memory allocation was successful
	if (_pp_data == NULL)
	{
		perror("Memory allocation of object list failed.");
		return *this;
	}

	// copy over the data
	memcpy(_pp_data, otherList._pp_data, sizeof(Object *) * otherList._capacity);

	// adjust size and capacity
	_capacity = otherList._capacity;
	_count = otherList._count;

	return *this;
}
