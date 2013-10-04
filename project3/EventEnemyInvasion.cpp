/*******************************************************************************
 * @file        EventEnemyInvasion.h
 * @author      bsautermeister
 * @description Enemy event, which is fired when an enemy reaches the planet.
 ******************************************************************************/

#include "EventEnemyInvasion.h"

/**
 * Creates a new enemy invasion event instance.
 */
EventEnemyInvasion::EventEnemyInvasion(void)
{
	setType(ENEMY_INVASION_EVENT);
}
