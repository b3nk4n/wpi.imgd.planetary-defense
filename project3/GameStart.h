/*******************************************************************************
 * @file        GameStart.h
 * @author      kcbryant
 * @description Game start screen
 ******************************************************************************/


#include "ViewObject.h"

class GameStart : public ViewObject {

protected:
	/**
  	 * Starts up the world screen
  	 */
  	void start();

  	/**
  	 * Counter for menu screen
  	 */
  	int _counter;

 public:
 	/**
 	 * Create a new GameStart()
 	 */
	GameStart();

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

