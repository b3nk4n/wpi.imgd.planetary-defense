/*******************************************************************************
 * @file        EventMouse.h
 * @author      bsautermeister
 * @description Mouse event class to notify other game when the user
 *   	        interacted using the mouse.
 ******************************************************************************/

#ifndef __EVENT_MOUSE_H__
#define __EVENT_MOUSE_H__

#include "Event.h"
#include "Position.h"

#define MOUSE_EVENT "__mouse__"

// the set of mouse actions
enum MouseActions
{
	LEFT_BUTTON_CLICK,
	LEFT_BUTTON_DOUBLECLICK,
	RIGHT_BUTTON_CLICK,
	RIGHT_BUTTON_DOUBLECLICK,
	UNDEFINED
};

/**
 * The mouse event class.
 */
class EventMouse : public Event
{
private:
	/**
	 * The events mouse action.
	 */
	enum MouseActions _mouseAction;

	/**
	 * The events mouse position.
	 */
	Position _position;

public:
	/**
	 * Creates a new mouse event instance.
	 */
	EventMouse(void);

	/**
	 * Gets the events mouse action.
	 * @return The mouse action.
	 */
	int getMouseAction(void);

	/**
	 * Sets the events mouse action.
	 * @param The mouse action.
	 */
	void setMouseAction(enum MouseActions mouseAction);

	/**
 	 * Gets the events mouse position.
	 * @return The mouse position.
	 */
	Position getPosition(void);

	/**
	 * Sets the events mouse position.
	 * @param the mouse position.
	 */
	void setPosition(Position position);
};

#endif
