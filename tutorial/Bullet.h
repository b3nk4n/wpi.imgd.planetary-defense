/* Bullet.h */

#ifndef BULLET_H
#define BULLET_H

#include "Object.h"
#include "EventCollision.h"

class Bullet : public Object
{
protected:
	void out();
	void hit(EventCollision * p_collisionEvent);
public:
	Bullet(Position heroPos);
	int eventHandler(Event *p_event);
};

#endif