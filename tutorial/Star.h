/* Star.h */

#ifndef STAR_H
#define STAR_H

#include "Object.h"

#define STAR_CHAR '.'

class Star : public Object
{
private:
	void randomXVelocity(void);

protected:
	void out(void);

public:
	Star(void);
	void draw(void);
	int eventHandler(Event *p_event);
};

#endif