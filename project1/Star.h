/* Star.h */

#ifndef STAR_H
#define STAR_H

#include "Object.h"

#define SLOW_STAR_CHAR '.'
#define FAST_STAR_CHAR '-'

class Star : public Object
{
private:
	/**
	 * Sets up a random velocity.
	 */
	void randomXVelocity(void);

protected:
	/**
	 * Is called when the star leaves the game world.
	 */
	void out(void);

public:
	/**
	 * Creates a new start instance.
	 */
	Star(void);
	/**
	 * Renders the star.
	 */
	void draw(void);
	/**
	 * Handles the events of the star.
	 */
	int eventHandler(Event *p_event);
};

#endif
