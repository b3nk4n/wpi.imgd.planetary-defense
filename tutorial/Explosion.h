/* Explosion.h */

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Object.h"

class Explosion : public Object
{
protected:
	int timeToLive;
	void step(void);

public:
	Explosion(void);
	int eventHandler(Event *p_event);
};

#endif