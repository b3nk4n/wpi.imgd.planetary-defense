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

#define UNDEFINED_KEY -1;
#define DOWN_KEY 258
#define UP_KEY 259
#define LEFT_KEY 260
#define RIGHT_KEY 261
#define SPACE_KEY 32
#define ENTER_KEY 13
#define PAUSE_KEY 29

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
