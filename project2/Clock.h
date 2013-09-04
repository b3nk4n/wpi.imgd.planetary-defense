/*******************************************************************************
 * @file        Clock.h
 * @author      bsautermeister
 * @description Supports stopwatch like functionality.
 ******************************************************************************/
#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <time.h>
#include <unistd.h>

class Clock
{
private:
	/**
	 * The previous time delta() called.
	 */
	struct timespec _prevTimespec;

public:
	/**
	 * Creates a new clock instance and sets previous time to current.
	 */
	Clock(void);

	/**
	 * Gets the elepsed time and resets the previous time.
	 * @return The elepsed time since its last call.
	 */
	long int delta(void);

	/**
	 * Gets the elepsed time without resetting the previous time.
	 * @return The elepsed time since its last call.
	 */
	long int split(void);
};

#endif
