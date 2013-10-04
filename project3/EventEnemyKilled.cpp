/*******************************************************************************
* @file        EventEnemyKilled.cpp
* @author      bsautermeister
* @description Player event, which is fired when an enemy is killed.
******************************************************************************/

#include "EventEnemyKilled.h"

/**
 * Creates a new enemy killed event instance.
 * @param credits The credits the player can gain.
 */
EventEnemyKilled::EventEnemyKilled(int credits)
{
	setType(ENEMY_KILLED_EVENT);
	_credits = credits;
}

/**
 * Gets the credits the player gains.
 * @return The credits the player gains.
 */
int EventEnemyKilled::getCredits(void)
{
	return _credits;
}
