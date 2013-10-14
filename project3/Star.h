/* Star.h */

#ifndef STAR_H
#define STAR_H

#include "Object.h"
#include "Box.h"

#define SLOW_STAR_CHAR '.'
#define FAST_STAR_CHAR '-'

class Star : public Object
{
private:
	/**
	 * The bounding box.
	 */
	Box _bounds;

	/**
	 * Is called when the star should reposition itself at the right side.
	 */
	void resetRight(void);

	/**
	 * Is called when the star should reposition itself anywhere.
	 */
	void reset(void);

	/**
	 * Last x velocity of star
	 */
	float _lastX;

	/**
	 * Last y velocity of star
	 */
	float _lastY;

public:
	/**
	 * Creates a new start instance.
	 */
	Star(void);
	/**
	 * Renders the star.
	 */
	void draw(void);
	/**
	 * Handles the events of the star.
	 */
	int eventHandler(Event *p_event);

	/**
	 * Sets the bounds of the star to move.
	 */
	void setBounds(Box bounds);
};

#endif
