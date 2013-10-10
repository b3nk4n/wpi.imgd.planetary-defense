/*******************************************************************************
 * @file        Manager.cpp
 * @author      bsautermeister
 * @description The game engines manger base class which defines the basic
 *              structure of all manager classes.
 ******************************************************************************/

#include <stdio.h>
#include "Manager.h"

/**
 * Creates a new manager instance.
 */
Manager::Manager(void)
{
	_isStarted = false;
	_eventListCount = 0;
}
/**
 * Cleans up the manager.
 */
Manager::~Manager(void)
{
}

/**
 * Validates if event is handles by this manager.
 * @param eventType The event type name.
 * @return Returns TRUE if event is handled, else FALSE.
 */
 bool Manager::isValid(string eventType)
 {
 	return false;
 }

 /**
 * Registers its interest for an event. This can be done multiple times.
 * @param p_object Points to the object to unregister.
 * @param eventType The event type name.
 * @return Returns 0 if ok, else -1.
 */
int Manager::registerInterest(Object *p_object, string eventType)
{
	// validate if the event type is allowed
	if (!isValid(eventType))
		return -1;

	// check if this event is already registerd
	for (int i = _eventListCount - 1; i >= 0; --i)
	{
		if (_events[i] == eventType)
			return _objectLists[i].insert(p_object);
	}

	// otherwise this is a new event
	if (_eventListCount >= MAX_EVENTS)
	{
		perror("Managers event list is full.");
		return -1;
	}

	// try to insert to the list
	if (_objectLists[_eventListCount].insert(p_object))
		return -1;
	
	_events[_eventListCount] = eventType;
	++_eventListCount;
	return 0;
}

/**
 * Unregisters its interest for an event.
 * @note doesn't check if game object has already been registered.
 * @param p_object Poits to the object to register.
 * @param eventType The event type name.
 * @return Returns 0 if ok, else -1.
 */
int Manager::unregisterInterest(Object *p_object, string eventType)
{
	// validate if the event type is allowed
	if (!isValid(eventType))
		return -1;

	// copy the list count value
	int eventCount = _eventListCount;

	// check for events
	for (int i = 0; i < eventCount; ++i)
	{
		if (_events[i] == eventType)
		{
			// remove object and check if object was found
			if (_objectLists[i].remove(p_object))
			{
				return -1;
			}

			// check if list is now empty
			if (_objectLists[i].isEmpty())
			{
				// scoot over both list
				for (int j = i; j < _eventListCount - 1; ++j)
				{
					_events[j] = _events[j + 1];
					_objectLists[j] = _objectLists[j + 1];
				}

				--_eventListCount;
			}

			return 0;
		}
	}

	// unknow event type
	return -1;
}

/**
 * Sends an event to all interested game objects.
 * @param p_event The event to send.
 */
void Manager::onEvent(Event *p_event)
{
	for (int i = _eventListCount - 1; i >= 0; --i)
	{
		if (_events[i] == p_event->getType())
		{
			// notify all interested objects
			ObjectListIterator it(&_objectLists[i]);
			for (it.first(); !it.isDone(); it.next())
			{
				it.currentObject()->eventHandler(p_event);
			}
			return;
		}
	}
}

/**
 * Gets whether the manager is started.
 * @return Returns TRUE if start up was successfull.
 */
bool Manager::isStarted(void)
{
	return _isStarted;
}
