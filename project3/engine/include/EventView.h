/*******************************************************************************
 * @file        EventView.h
 * @author      bsautermeister
 * @description View event class to notify other game objects to that an
 *              view object needs to be updated.
 ******************************************************************************/

#ifndef __EVENT_VIEW_H__
#define __EVENT_VIEW_H__

#include "Event.h"

#define VIEW_EVENT "__view__"

/**
 * The view event class.
 */
class EventView : public Event
{
private:
	/**
	 * The associated tag.
	 */
	string _tag;

	/**
	 * The value for the view
	 */
	int _value;

	/**
	 * Indicates whether delta or replace value.
	 */
	bool _delta;

public:
	/**
	 * Creates a new view event instance with no value and no delta.
	 */
	EventView(void);

	/**
	 * Creates a new view event instance.
	 * @param tag The tag.
	 * @param value The value.
	 * @param delta Indicates whether the value is changed or replaced.
	 */
	EventView(string tag, int value, bool delta);

	/**
	 * Gets the tag.
	 * @return The associated tag.
	 */
	string getTag(void);

	/**
	 * Sets the tag.
	 * @param value The associated tag.
	 */
	void setTag(string value);

	/**
	 * Gets the value.
	 * @return The value.
	 */
	int getValue(void);

	/**
	 * Sets the value.
	 * @param value The value.
	 */
	void setValue(int value);

	/**
	 * Gets whether the value is changed or replaced.
	 * @return Returns whether delta or not.
	 */
	bool getDelta(void);

	/**
	 * Sets whether the value is changed or replaced.
	 * @param value Indicates whether delta or not.
	 */
	void setDelta(bool value);
};

#endif
