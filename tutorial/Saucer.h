/* Saucer.h */

#ifndef SAUCER_H
#define SAUCER_H

#include "Object.h"

class Saucer : public Object
{
protected:
	void move(void);
	int eventHandler(Event *p_e);
	void out(void);
	void moveToStart(void);

public:
	Saucer();
};

#endif

