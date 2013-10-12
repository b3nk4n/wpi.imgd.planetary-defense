/*******************************************************************************
 * @file        GameOver.h
 * @author      kcbryant
 * @description Game Over Screen
 ******************************************************************************/

#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "ViewObject.h"

class GameOver : public ViewObject {

 public:
 	/**
 	 * Create a new Game Over 
 	 */
	GameOver(bool success);

	/**
	 * Handle events
	 * @param Event, Event being passed to the handler
	 * @return int, return 0 if ignored, else 1
	 */
	int eventHandler(Event *p_event);

	/**
	 * Draw to screen
	 */
	void draw();
};

#endif // __GAME_OVER_H__
