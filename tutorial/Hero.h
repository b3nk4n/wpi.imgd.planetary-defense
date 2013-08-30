/* Hero.h */

#ifndef HERO_H
#define HERO_H

#include "Object.h"
#include "EventKeyboard.h"

class Hero : public Object
{
protected:
	int fireSlowdown;
	int fireCountdown;
	int nukeCount;

	void keyboard(EventKeyboard *p_keyboard_event);
	void move(int dy);
	void moveToStart(void);
	void step(void);
	void fire(void);
	void nuke(void);

public:
	Hero(void);
	~Hero(void);
	int eventHandler(Event *p_e);
};

#endif