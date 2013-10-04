/*******************************************************************************
 * @file        EventPlayerKilled.cpp
 * @author      bsautermeister
 * @description Player event, which is fired when the player is dead.
 ******************************************************************************/

#include "EventPlayerKilled.h"

/**
 * Creates a new player killed event instance.
 */
EventPlayerKilled::EventPlayerKilled(void)
{
	setType(PLAYER_KILLED_EVENT);
}
