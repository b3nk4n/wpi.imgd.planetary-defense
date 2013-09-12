/*******************************************************************************
 * @file        EventMouse.cpp
 * @author      bsautermeister
 * @description Mouse event class to notify other game when the user
 *   	        interacted using the mouse.
 ******************************************************************************/

#include "EventMouse.h"

/**
 * Creates a new mouse event instance.
 */
EventMouse::EventMouse(void)
{
	setType(MOUSE_EVENT);
	_mouseAction = UNDEFINED;
}

/**
 * Gets the events mouse action.
 * @return The mouse action.
 */
int EventMouse::getMouseAction(void)
{
	return _mouseAction;
}

/**
 * Sets the events mouse action.
 * @param The mouse action.
 */
void EventMouse::setMouseAction(enum MouseActions mouseAction)
{
	_mouseAction = mouseAction;
}

/**
	 * Gets the events mouse position.
 * @return The mouse position.
 */
Position EventMouse::getPosition(void)
{
	return _position;
}

/**
 * Sets the events mouse position.
 * @param the mouse position.
 */
void EventMouse::setPosition(Position position)
{
	_position = position;
}
