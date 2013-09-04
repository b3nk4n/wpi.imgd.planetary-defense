/*******************************************************************************
 * @file        Clock.cpp
 * @author      bsautermeister
 * @description Supports stopwatch like functionality.
 ******************************************************************************/

#include <stdio.h>
#include "Clock.h"

#define CLOCK_READ_ERROR "Could not read system clock"

/**
* Creates a new clock instance and sets previous time to current.
*/
Clock::Clock(void)
{
	// try reading current time
	if (clock_gettime(CLOCK_REALTIME, &_prevTimespec))
	{
		perror(CLOCK_READ_ERROR);
	}
}

/**
 * Gets the elepsed time and resets the previous time.
 * @return The elepsed time since its last call in usec.
 */
long int Clock::delta(void)
{
	struct timespec snapshot;

	// try reading current time
	if (clock_gettime(CLOCK_REALTIME, &snapshot))
	{
		perror(CLOCK_READ_ERROR);
	}

	// compute elapsed time
	long int beforeMsec, afterMsec;
	beforeMsec = _prevTimespec.tv_sec * 1000000 + _prevTimespec.tv_nsec / 1000;
	afterMsec = snapshot.tv_sec * 1000000 + snapshot.tv_nsec / 1000;

	// reset previous delta time
	_prevTimespec = snapshot;

	return afterMsec - beforeMsec;
}

/**
 * Gets the elepsed time without resetting the previous time.
 * @return The elepsed time since its last call in usec.
 */
long int Clock::split(void)
{
	struct timespec snapshot;

	// try reading current time
	if (clock_gettime(CLOCK_REALTIME, &snapshot))
	{
		perror(CLOCK_READ_ERROR);
	}

	// compute elapsed time
	long int beforeMsec, afterMsec;
	beforeMsec = _prevTimespec.tv_sec * 1000000 + _prevTimespec.tv_nsec / 1000;
	afterMsec = snapshot.tv_sec * 1000000 + snapshot.tv_nsec / 1000;

	return afterMsec - beforeMsec;
}