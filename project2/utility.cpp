/*******************************************************************************
 * @file        utility.cpp
 * @author      bsautermeister
 * @description Utility function modul used in different classes of the engine.
 ******************************************************************************/

#include <time.h>
#include <stdio.h>

#include "utility.h"

/**
 * Gets the current time as a string.
 * @return The current time string.
 */
char *getTimeString(void)
{
	// string to return, made static to persist
	static char timeStringBuffer[32];

	// system calls to get time
	time_t sysTime;
	time(&sysTime);
	struct tm *p_time = localtime(&sysTime);

	// write formatted time
	sprintf(timeStringBuffer,
		"%02d:%02d:%02d",
		p_time->tm_hour,
		p_time->tm_min,
		p_time->tm_sec);

	return timeStringBuffer;
}
