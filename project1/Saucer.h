/* Saucer.h */

#ifndef SAUCER_H
#define SAUCER_H

#include "Enemy.h"

class Saucer : public Enemy
{
protected:
	/**
	 * Creates a new Saucer.
	 */
	void createEnemy(void);
public:
	/**
	 * Creates a new saucer instance.
	 */
	Saucer(void);
	/**
	 * Handles the events.
	 */
	virtual int eventHandler(Event *p_event);
};

#endif
