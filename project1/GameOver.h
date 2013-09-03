/* GameOver.h */

#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "ViewObject.h"

class GameOver : public ViewObject
{
private:
	/**
	 * Moves the game over text to the center of the screen.
	 */
	void toCenterOfScreen(void);
	
protected:
	int timeToLive;

	/**
	 * Updates the game over object.
	 */
	void step(void);

public:
	/**
	 * Creates a new game over instance.
	 */
	GameOver(void);
	/**
	 * Destructs the game over instance.
	 */
	~GameOver(void);
	/**
	 * Renders the game over object.
	 */
	void draw(void);
	/**
	 * Handles the events.
	 */
	int eventHandler(Event *p_event);
};

#endif