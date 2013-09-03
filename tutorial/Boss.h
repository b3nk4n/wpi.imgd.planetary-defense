/* Boss.h */

#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"

#define FIRE_TICKS_MIN 30
#define FIRE_TICKS_MAX 90

class Boss : public Enemy
{
protected:
	bool finished;
	int fireTimer;

	/**
	 * Fires a bullet.
	 */
	void tryFire(void);

	/**
	 * Creates a new boss.
	 */
	void createEnemy(void);
public:
	/**
	 * Creates a new boss instance.
	 */
	Boss(void);
	/**
	 * Destructs the boss.
	 */
	~Boss(void);
	/**
	 * Handles the events.
	 */
	virtual int eventHandler(Event *p_event);
};

#endif