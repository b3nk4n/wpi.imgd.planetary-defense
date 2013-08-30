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
	Points(void);
	int eventHandler(Event *p_event);
};

#endif