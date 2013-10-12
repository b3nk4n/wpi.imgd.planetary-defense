/*******************************************************************************
 * @file        GameControls.h
 * @author      kcbryant
 * @description Game instructions screen
 ******************************************************************************/

#ifndef __GAME_CONTROLS_H__
#define __GAME_CONTROLS_H__

#include "ViewObject.h"

class GameControls : public ViewObject {
private:

	/**
	 * Instruction page number
	 */
	int _counter;

protected:
	
	/**
  	 * Starts up controls screen
  	 */
  	void start();

 public:
 	/**
 	 * Create a new GameStart()
 	 */
	GameControls();

	/**
	 * Handle events
	 * @param Event, Event being passed to the handler
	 * @return int, return 0 if ignored, else 1
	 */
	int eventHandler(Event *e);

	/**
	 * Draw to screen
	 */
	void draw();
};

#endif // __GAME_START_H__
