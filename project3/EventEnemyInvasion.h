/*******************************************************************************
 * @file        EventEnemyInvasion.h
 * @author      bsautermeister
 * @description Enemy event, which is fired when an enemy reaches the planet.
 ******************************************************************************/

#ifndef __EVENT_ENEMY_INVASION_H__
#define __EVENT_ENEMY_INVASION_H__

#include "Event.h"

#define ENEMY_INVASION_EVENT "enemy_invasion"

/**
 * The enemy invasion event class.
 */
class EventEnemyInvasion : public Event
{
public:
	/**
	 * Creates a new enemy invasion event instance.
	 */
	EventEnemyInvasion(void);
};

#endif
