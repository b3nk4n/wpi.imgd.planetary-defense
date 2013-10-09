/*******************************************************************************
 * @file        PopupText.h
 * @author      bsautermeister
 * @description The upward moving text for text effects.
 ******************************************************************************/

#ifndef POPUP_TEXT_H
#define POPUP_TEXT_H

#include "Object.h"

#define TYPE_POPUP_TEXT "popup_text"

/**
 * Represents a popup text.
 */
class PopupText : public Object
{
private:
	/**
	 * The explosions life time.
	 */
	int _timeToLive;

	/**
	 * The displayed dollar value.
	 */
	int _value;

public:
	/**
	 * Creates a new popup text instance.
	 * @param position The text starting center.
	 * @param value The dollar displayed value.
	 */
	PopupText(Position position, int value);

	/**
	 * Handles the events.
	 * @param p_event The event.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Renders the popup text.
	 */
	virtual void draw(void);
};

#endif
