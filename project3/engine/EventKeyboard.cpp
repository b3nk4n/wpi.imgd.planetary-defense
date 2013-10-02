/*******************************************************************************
 * @file        EventKeyboard.cpp
 * @author      bsautermeister
 * @description Keyboard event class to notify other game when
 *              a key was pressed.
 ******************************************************************************/

#include "EventKeyboard.h"

/**
 * Creates a new keyboard event instance.
 */
EventKeyboard::EventKeyboard(void)
{
	setType(KEYBOARD_EVENT);
	_keyValue = UNDEFINED_KEY;
}

/**
 * Gets the pressed key of the event.
 * @return The pressed key.
 */
int EventKeyboard::getKey(void)
{
	return _keyValue;
}

/**
 * Sets the pressed key of the event.
 * @param key The pressed key.
 */
void EventKeyboard::setKey(int key)
{
	_keyValue = key;
}
