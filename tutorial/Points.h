/* Points.h */

#ifndef POINTS_H
#define POINTS_H

#include "ViewObject.h"
#include "Event.h"

#define POINTS_STRING "Points"

class Points : public ViewObject
{
protected:
	int stepCount;
	
public:
	/**
	 * Creates a new points instance.
	 */
	Points(void);
	/**
	 * Handles the occured events.
	 */
	int eventHandler(Event *p_event);
	/**
	 * Render the score bar.
	 */
	void draw(void);
};

#endif