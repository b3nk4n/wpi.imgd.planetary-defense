/*******************************************************************************
 * @file        EventEnemyKilled.h
 * @author      bsautermeister
 * @description Player event, which is fired when an enemy is killed.
 ******************************************************************************/

#ifndef __EVENT_ENEMY_KILLED_H__
#define __EVENT_ENEMY_KILLED_H__

#include "Event.h"

#define ENEMY_KILLED_EVENT "enemy_killed"

/**
 * The enemy killed event class.
 */
class EventEnemyKilled : public Event
{
private:
	/**
	 * The credits the player can gain for killing this enemy.
	 */
	int _credits;
public:
	/**
	 * Creates a new enemy killed event instance.
	 * @param credits The credits the player can gain.
	 */
	EventEnemyKilled(int credits);

	/**
	 * Gets the credits the player gains.
	 * @return The credits the player gains.
	 */
	int getCredits(void);
};

#endif
