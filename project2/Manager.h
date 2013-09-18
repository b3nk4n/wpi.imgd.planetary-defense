/*******************************************************************************
 * @file        Manager.h
 * @author      bsautermeister
 * @description The game engines manger base class which defines the basic
 *              structure of all manager classes.
 ******************************************************************************/

#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <string>
#include "ObjectList.h"

using std::string;

#define MAX_EVENTS 64

/**
 * The manager base class.
 */
class Manager
{
private:
	/**
	 * The number of events.
	 */
	int _eventListCount;

	/**
	 * The list of registerd event types.
	 * @note Parallel array with _objectList.
	 */
	string _events[MAX_EVENTS];

	/**
	 * Lists of game objects which are interestid in events.
	 * @note Parallel array with _events.
	 */
	ObjectList _objectLists[MAX_EVENTS];

protected:
	/**
	 * Indicates whether starting was successful.
	 */
	bool _isStarted;

public:
	/**
	 * Creates a new manager instance.
	 */
	Manager(void);
	/**
	 * Cleans up the manager.
	 */
	virtual ~Manager(void);

	/**
	 * Starts up the manager.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	virtual int startUp(void) = 0;

	/**
	 * Shuts down the manager.
	 */
	virtual void shutDown(void) = 0;

	/**
	 * Registers its interest for an event. This can be done multiple times.
	 * @param p_object Poits to the object to unregister.
	 * @param eventType The event type name.
	 * @return Returns 0 if ok, else -1.
	 */
	int registerInterest(Object *p_object, string eventType);

	/**
	 * Unregisters its interest for an event.
	 * @note doesn't check if game object has already been registered.
	 * @param p_object Poits to the object to register.
	 * @param eventType The event type name.
	 * @return Returns 0 if ok, else -1.
	 */
	int unregisterInterest(Object *p_object, string eventType);

	/**
	 * Sends an event to all interested game objects.
	 * @param p_event The event to send.
	 */
	void onEvent(Event *p_event);

	/**
	 * Validates if event is handles by this manager.
	 * @param eventType The event type name.
	 * @return Returns TRUE if event is handled, else FALSE.
	 */
	 virtual bool isValid(string eventType);

	/**
	 * Gets whether the manager is started.
	 * @return Returns TRUE if start up was successfull.
	 */
	bool isStarted(void);
};

#endif
