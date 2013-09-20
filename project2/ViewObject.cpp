/*******************************************************************************
* @file        ViewObject.cpp
* @author      bsautermeister
* @description The bass class for all game view objects representing an
*              notifyable object in the game world.
******************************************************************************/

#include "ViewObject.h"
#include "GraphicsManager.h"
#include "EventView.h"

/**
 * Creates a view object instance. These are always spectral
 * at max. altitude with border, top center and default color.
 */
ViewObject::ViewObject(void)
{
	// init object attributes
	setSolidness(SPECTRAL);
	setAltitude(MAX_ALTITUDE);
	setType(TYPE_VIEW_OBJECT);

	// init view object attributes
	setValue(0);
	setBorder(true);
	setLocation(TOP_CENTER);
	setColor(COLOR_DEFAULT);

	// register for view event
	registerInterest(VIEW_EVENT);
}

/**
 * Cleans up the view object.
 */
ViewObject::~ViewObject(void)
{
}

/**
 * Handles the view events.
 * @param p_event Points to the current event to handle.
 * @return Return 0 if ignored, else 1 if event was handled.
 */
int ViewObject::eventHandler(Event *p_event)
{
	return -1;
}

/**
 * Renders the view objects including string and value.
 */
void ViewObject::draw(void)
{

}

/**
 * Sets the location of the view object on the screen.
 * @param location The scren location.
 */
void ViewObject::setLocation(ViewObjectLocation location)
{

}

/**
 * Sets the value.
 * @param value The value.
 */
void ViewObject::setValue(int value)
{

}

/**
 * Gets the value.
 * @return The value.
 */
int ViewObject::getValue(void)
{
	return -1;
}

/**
 * Sets whether the border is displayed.
 * @param value The border.
 */
void ViewObject::setBorder(bool value)
{

}

/**
 * Gets whether the border is displayed.
 * @return The border.
 */
bool ViewObject::getBorder(void)
{
	return false;
}

/**
 * Sets the text color.
 * @param value the text color.
 */
void ViewObject::setColor(int value)
{

}

/**
 * Gets the text color.
 * @return The text color.
 */
int ViewObject::getColor(void)
{
	return -1;
}

/**
 * Sets the view string.
 * @param value The view string.
 */
void ViewObject::setViewString(string value)
{

}

/**
 * Gets the view string.
 * @return The view string.
 */
string ViewObject::getViewString(void)
{
	return NULL;
}
