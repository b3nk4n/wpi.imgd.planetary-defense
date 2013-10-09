/*******************************************************************************
* @file        EventEnemyKilled.cpp
* @author      bsautermeister
* @description Player event, which is fired when an enemy is killed.
******************************************************************************/

#include "EventEnemyKilled.h"

/**
 * Creates a new enemy killed event instance.
 * @param position The enemy kill position.
 * @param credits The credits the player can gain.
 */
EventEnemyKilled::EventEnemyKilled(Position position, int credits)
{
	setType(ENEMY_KILLED_EVENT);
	_position = position;
	_credits = credits;
}

/**
 * Gets the position the enemy was killed.
 * @return The enemy kill position.
 */
Position EventEnemyKilled::getPosition(void)
{
	return _position;
}

/**
 * Gets the credits the player gains.
 * @return The credits the player gains.
 */
int EventEnemyKilled::getCredits(void)
{
	return _credits;
}
