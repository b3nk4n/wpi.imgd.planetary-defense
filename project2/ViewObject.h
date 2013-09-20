/*******************************************************************************
 * @file        ViewObject.h
 * @author      bsautermeister
 * @description The bass class for all game view objects representing an
 *              notifyable object in the game world.
 ******************************************************************************/

#ifndef __VIEW_OBJECT_H__
#define __VIEW_OBJECT_H__

#include <string>
#include "Object.h"
#include "Event.h"

using std::string;

#define TYPE_VIEW_OBJECT "Object"

/**
 * General location of view objects on screen.
 */
enum ViewObjectLocation
{
	TOP_LEFT,
	TOP_CENTER,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT
};

/**
 * Represents a view object in the game world.
 */
class ViewObject : public Object
{
private:
	/**
	 * The value label.
	 */
	string _viewString;

	/**
	 * The displayed value.
	 */
	int _value;

	/**
	 * Indicates whether a sourrounding border is rendered.
	 */
	bool _border;

	/**
	 * The text color.
	 */
	int _color;

public:
	/**
	 * Creates a view object instance. These are always spectral
	 * at max. altitude with border, top center and default color.
	 */
	ViewObject(void);

	/**
	 * Cleans up the view object.
	 */
	virtual ~ViewObject(void);

	/**
	 * Handles the view events.
	 * @param p_event Points to the current event to handle.
	 * @return Return 0 if ignored, else 1 if event was handled.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Renders the view objects including string and value.
	 */
	virtual void draw(void);

	/**
	 * Sets the location of the view object on the screen.
	 * @param location The scren location.
	 */
	void setLocation(ViewObjectLocation location);

	/**
	 * Sets the value.
	 * @param value The value.
	 */
	void setValue(int value);

	/**
	 * Gets the value.
	 * @return The value.
	 */
	int getValue(void);

	/**
	 * Sets whether the border is displayed.
	 * @param value The border.
	 */
	void setBorder(bool value);

	/**
	 * Gets whether the border is displayed.
	 * @return The border.
	 */
	bool getBorder(void);

	/**
	 * Sets the text color.
	 * @param value the text color.
	 */
	void setColor(int value);

	/**
	 * Gets the text color.
	 * @return The text color.
	 */
	int getColor(void);

	/**
	 * Sets the view string.
	 * @param value The view string.
	 */
	void setViewString(string value);

	/**
	 * Gets the view string.
	 * @return The view string.
	 */
	string getViewString(void);
};

#endif
