/*******************************************************************************
 * @file        Splash.h
 * @author      bsautermeister
 * @description The dragonfly splash screen.
 ******************************************************************************/

#ifndef __SPLASH_H__
#define __SPLASH_H__

#include "Object.h"

#define TYPE_SPLASH "__splash__"

class Splash : public Object
{
private:
	/**
	 * The count down to determine the end.
	 */
	int _countdown;

public:
	/**
	 * Creates a new splash screen instance.
	 */
	Splash(void);

	/**
	 * Cleans up the splash screens resources.
	 */
	~Splash(void);

	/**
	 * Handles the splash screen events.
	 * @param p_event The event.
	 * @return Returns 0 for success, else -1.
	 */
	virtual int eventHandler(Event *p_event);
};

#endif

