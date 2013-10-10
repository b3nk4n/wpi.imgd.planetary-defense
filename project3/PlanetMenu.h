/*******************************************************************************
 * @file        PlanetMenu.h
 * @author      kcbryant
 * @description Planet selection screen
 ******************************************************************************/


#include "ViewObject.h"

class PlanetMenu : public ViewObject {
private:
	/**
  	 * Planet choice of player
  	 */
  	int _choice;

protected:
	/**
  	 * Starts up the world screen
  	 */
  	void start();

 public:
 	/**
 	 * Create a new PlanetMenu()
 	 */
	PlanetMenu();

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

