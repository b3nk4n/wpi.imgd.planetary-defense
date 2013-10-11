/*******************************************************************************
 * @file        EventPlayerWin.h
 * @author      bsautermeister
 * @description Player event, which is fired when the player won the game.
 ******************************************************************************/

#ifndef __EVENT_PLAYER_WIN_H__
#define __EVENT_PLAYER_WIN_H__

#include "Event.h"

#define PLAYER_WIN_EVENT "player_win"

/**
 * The player win event class.
 */
class EventPlayerWin : public Event
{
public:
	/**
	 * Creates a new player win event instance.
	 */
	EventPlayerWin(void);
};

#endif
