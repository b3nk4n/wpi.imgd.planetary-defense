/*******************************************************************************
 * @file        EventView.cpp
 * @author      bsautermeister
 * @description View event class to notify other game objects to that an
 *              view object needs to be updated.
 ******************************************************************************/

#include "EventView.h"

/**
 * Creates a new view event instance with no value and no delta.
 */
EventView::EventView(void)
{
	setType(VIEW_EVENT);

	setTag("");
	setValue(0);
	setDelta(false);
}

/**
 * Creates a new view event instance.
 * @param tag The tag.
 * @param value The value.
 * @param delta Indicates whether the value is changed or replaced.
 */
EventView::EventView(string tag, int value, bool delta)
{
	setType(VIEW_EVENT);

	setTag(tag);
	setValue(value);
	setDelta(delta);
}

/**
 * Gets the tag.
 * @return The associated tag.
 */
string EventView::getTag(void)
{
	return _tag;
}

/**
 * Sets the tag.
 * @param value The associated tag.
 */
void EventView::setTag(string value)
{
	_tag = value;
}

/**
 * Gets the value.
 * @return The value.
 */
int EventView::getValue(void)
{
	return _value;
}

/**
 * Sets the value.
 * @param value The value.
 */
void EventView::setValue(int value)
{
	_value = value;
}

/**
 * Gets whether the value is changed or replaced.
 * @return Returns whether delta or not.
 */
bool EventView::getDelta(void)
{
	return _delta;
}

/**
 * Sets whether the value is changed or replaced.
 * @param value Indicates whether delta or not.
 */
void EventView::setDelta(bool value)
{
	_delta = value;
}
