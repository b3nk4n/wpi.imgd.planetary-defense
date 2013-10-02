/*******************************************************************************
 * @file        SplashDragonfly.h
 * @author      bsautermeister
 * @description The dragonfly splash screen.
 ******************************************************************************/

#ifndef __SPLASH_DRAGONFLY_H__
#define __SPLASH_DRAGONFLY_H__

#include "Object.h"

#define TYPE_SPLASH_DRAGONFLY "__splash_dragonfly__"

class SplashDragonfly : public Object
{
private:
	/**
	 * The animations end position.
	 */
	Position _endPosition;
	/**
	 * The count down to determine the end.
	 */
	int _countdown;

public:
	/**
	 * Creates a new splash screen instance.
	 * @param endPosition The end position.
	 */
	SplashDragonfly(Position endPosition);

	/**
	 * Cleans up the splash screens resources.
	 */
	~SplashDragonfly(void);

	/**
	 * Handles the splash screen events.
	 * @param p_event The event.
	 * @return Returns 0 for success, else -1.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Renders the splash X and the text.
	 */
	virtual void draw(void);
};

#endif

