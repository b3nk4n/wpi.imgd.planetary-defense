/*******************************************************************************
 * @file        EventPlayerKilled.h
 * @author      bsautermeister
 * @description Player event, which is fired when the player is dead.
 ******************************************************************************/

#ifndef __EVENT_PLAYER_KILLED_H__
#define __EVENT_PLAYER_KILLED_H__

#include "Event.h"

#define PLAYER_KILLED_EVENT "player_killed"

/**
 * The player killed event class.
 */
class EventPlayerKilled : public Event
{
public:
	/**
	 * Creates a new player killed event instance.
	 */
	EventPlayerKilled(void);
};

#endif
