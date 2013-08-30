/* Explosion.h */

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Object.h"

class Explosion : public Object
{
protected:
	int timeToLive;
	void step();

public:
	Explosion();
	int eventHandler(Event *p_event);
};

#endif