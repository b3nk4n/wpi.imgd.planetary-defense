/* Bullet.h */

#ifndef BULLET_H
#define BULLET_H

#include "Object.h"
#include "EventCollision.h"

class Bullet : public Object
{
protected:
	void out();
	void hit(EventCollision * p_c);
public:
	Bullet(Position hero_pos);
	int eventHandler(Event *p_e);
};

#endif