/*******************************************************************************
* @file        ViewObject.cpp
* @author      bsautermeister
* @description The bass class for all game view objects representing an
*              notifyable object in the game world.
******************************************************************************/

#include "ViewObject.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventView.h"
#include "utility.h"

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
	if (p_event->getType() == VIEW_EVENT)
	{
		EventView *p_viewEvent = static_cast<EventView *>(p_event);

		// see if this event is meant for this object
		if (p_viewEvent->getTag() == getViewString())
		{
			if (p_viewEvent->getDelta()) // change
				setValue(getValue() + p_viewEvent->getValue());
			else // replace
				setValue(p_viewEvent->getValue());
		}

		return 1;
	}

	return 0;
}

/**
 * Renders the view objects including string and value.
 */
void ViewObject::draw(void)
{
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	string displayString;

	// display viewsting and value
	if (getBorder())
		displayString = " " + getViewString() + " " + intToString(getValue()) + " ";
	else
		displayString = getViewString() + " " + intToString(getValue());

	// render centered to position
	Position pos = viewToWorld(getPosition());
	graphicsManager.drawString(pos, displayString, CENTER_JUSTIFIED, getColor());

	if (getBorder())
	{
		// render border
		int textLength = displayString.length();
		int leftHalf = displayString.length() / 2;
		int rightHalf = textLength - leftHalf;
		for (int i = 0; i < textLength; ++i)
		{
			graphicsManager.drawChar(
				Position(
					pos.getX() - leftHalf + i,
					pos.getY() - 1),
				'-',
				getColor());
		}

		graphicsManager.drawChar(
				Position(
					pos.getX() - leftHalf - 1,
					pos.getY()),
				'|',
				getColor());

		graphicsManager.drawChar(
				Position(
					pos.getX() + rightHalf,
					pos.getY()),
				'|',
				getColor());

		for (int i = 0; i < textLength; ++i)
		{
			graphicsManager.drawChar(
				Position(
					pos.getX() - leftHalf + i,
					pos.getY() + 1),
				'-',
				getColor());
		}
	}
}

/**
 * Sets the location of the view object on the screen.
 * @param location The scren location.
 */
void ViewObject::setLocation(ViewObjectLocation location)
{
	WorldManager &worldManager = WorldManager::getInstance();
	Position pos;
	int delta = 0;

	// set new position based on location
	switch (location)
	{
	case TOP_LEFT:
		pos.setXY(worldManager.getViewBoundary().getHorizontal() * 1/6.0f, 1);
		if (!getBorder())
			delta = -1;
		break;
	case TOP_CENTER:
		pos.setXY(worldManager.getViewBoundary().getHorizontal() * 3/6.0f, 1);
		if (!getBorder())
			delta = -1;
		break;
	case TOP_RIGHT:
		pos.setXY(worldManager.getViewBoundary().getHorizontal() * 5/6.0f, 1);
		if (!getBorder())
			delta = -1;
		break;
	case BOTTOM_LEFT:
		pos.setXY(worldManager.getViewBoundary().getHorizontal() * 1/6.0f,
			worldManager.getViewBoundary().getHorizontal() - 1);
		if (!getBorder())
			delta = 1;
		break;
	case BOTTOM_CENTER:
		pos.setXY(worldManager.getViewBoundary().getHorizontal() * 3/6.0f,
			worldManager.getViewBoundary().getHorizontal() - 1);
		if (!getBorder())
			delta = 1;
		break;
	case BOTTOM_RIGHT:
		pos.setXY(worldManager.getViewBoundary().getHorizontal() * 5/6.0f,
			worldManager.getViewBoundary().getHorizontal() - 1);
		if (!getBorder())
			delta = 1;
		break;
	}

	// shift, as needed, based on border
	pos.setY(pos.getY() + delta);

	// set view object position
	setPosition(pos);
}

/**
 * Sets the value.
 * @param value The value.
 */
void ViewObject::setValue(int value)
{
	_value = value;
}

/**
 * Gets the value.
 * @return The value.
 */
int ViewObject::getValue(void)
{
	return _value;
}

/**
 * Sets whether the border is displayed.
 * @param value The border.
 */
void ViewObject::setBorder(bool value)
{
	_border = value;
}

/**
 * Gets whether the border is displayed.
 * @return The border.
 */
bool ViewObject::getBorder(void)
{
	return _border;
}

/**
 * Sets the text color.
 * @param value the text color.
 */
void ViewObject::setColor(int value)
{
	_color = value;
}

/**
 * Gets the text color.
 * @return The text color.
 */
int ViewObject::getColor(void)
{
	return _color;
}

/**
 * Sets the view string.
 * @param value The view string.
 */
void ViewObject::setViewString(string value)
{
	_viewString = value;
}

/**
 * Gets the view string.
 * @return The view string.
 */
string ViewObject::getViewString(void)
{
	return _viewString;
}
