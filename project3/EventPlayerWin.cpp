/*******************************************************************************
 * @file        EventPlayerWin.cpp
 * @author      bsautermeister
 * @description Player event, which is fired when the player won the game.
 ******************************************************************************/

#include "EventPlayerWin.h"

/**
 * Creates a new player win event instance.
 */
EventPlayerWin::EventPlayerWin(void)
{
	setType(PLAYER_WIN_EVENT);
}

