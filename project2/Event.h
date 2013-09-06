/*******************************************************************************
 * @file        Event.h
 * @author      bsautermeister
 * @description Basic event class to notify other game objects about all kinds
 *              of events that happend during the gameplay.
 ******************************************************************************/

#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>

using std::string;

#define UNDEFINED_EVENT "__undefined__"

/**
 * The base event class.
 */
class Event
{
private:
	/**
	 * The event type.
	 */
	string _type;

public:
	/**
	 * Creates a new event instance.
	 */
	Event(void);

	/**
	 * Cleans up the event.
	 */
	virtual ~Event(void);

	/**
	 * Gets the event type.
	 * @return The event type.
	 */
	string getType(void);

	/**
	 * Sets the event type.
	 * @param type The event type.
	 */
	void setType(string type);
};

#endif
