/*******************************************************************************
 * @file        Event.cpp
 * @author      bsautermeister
 * @description Basic event class to notify other game objects about all kinds
 *              of events that happend during the gameplay.
 ******************************************************************************/

#include "Event.h"

/**
 * Creates a new event instance.
 */
Event::Event(void)
{
	setType(UNDEFINED_EVENT);
}

/**
 * Cleans up the event.
 */
Event::~Event(void)
{

}

/**
 * Gets the event type.
 * @return The event type.
 */
string Event::getType(void)
{
	return _type;
}

/**
 * Sets the event type.
 * @param type The event type.
 */
void Event::setType(string type)
{
	_type = type;
}
