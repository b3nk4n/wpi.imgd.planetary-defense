/* Explosion.h */

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Object.h"

#define EXPLOSION_SMALL 0
#define EXPLOSION_LARGE 1

class Explosion : public Object
{
protected:
	int timeToLive;
	void step(void);

public:
	Explosion(int type);
	int eventHandler(Event *p_event);
};

#endif