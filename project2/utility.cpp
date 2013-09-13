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

/**
 * Checks for positoin intersection.
 * @param position1 The first position.
 * @param position2 The second position.
 * @return Returns TRUE if positions are intersection, else FALSE.
 */
bool positionIntersect(Position position1, Position position2)
{
	return position1.getX() == position2.getX() &&
		position1.getY() == position2.getY();
}

/**
 * Checks for intersection between a box and a position.
 * @param box The box/rectangle.
 * @param position The position.
 * @param Returns TRUE if the position intersects the box, else false.
 */
bool boxContainsPoint(Box box, Position position)
{
	int boxX = box.getCorner().getX();
	int boxY = box.getCorner().getY();

	return position.getX() >= boxX &&
		position.getX() <= boxX + box.getHorizontal() &&
		position.getY() >= boxY &&
		position.getY() <= boxY + box.getVertical();
}
