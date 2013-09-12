/*******************************************************************************
 * @file        EventKeyboard.h
 * @author      bsautermeister
 * @description Keyboard event class to notify other game when
 *              a key was pressed.
 ******************************************************************************/

#ifndef __EVENT_KEYBOARD_H__
#define __EVENT_KEYBOARD_H__

#include "Event.h"

#define KEYBOARD_EVENT "__keyboard__"

#define KEY_UNDEFINED -1;
#define KEY_DOWN 258
#define KEY_UP 259
#define KEY_LEFT 260
#define KEY_RIGHT 261
#define KEY_SPACE 32
#define KEY_ENTER 13
#define KEY_PAUSE 29

/**
 * The keyboard event class.
 */
class EventKeyboard : public Event
{
private:
	/**
	 * The keyboard value.
	 */
	int _keyValue;
public:
	/**
	 * Creates a new keyboard event instance.
	 */
	EventKeyboard(void);

	/**
	 * Gets the pressed key of the event.
	 * @return The pressed key.
	 */
	int getKey(void);

	/**
	 * Sets the pressed key of the event.
	 * @param key The pressed key.
	 */
	void setKey(int key);
};

#endif
