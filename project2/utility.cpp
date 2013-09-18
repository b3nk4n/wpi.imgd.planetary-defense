/*******************************************************************************
 * @file        utility.cpp
 * @author      bsautermeister
 * @description Utility function modul used in different classes of the engine.
 ******************************************************************************/

#include <time.h>
#include <stdio.h>
#include <math.h>

#include "utility.h"
#include "Object.h"

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
 * Checks for intersection between to boxes.
 * @param box1 The first box.
 * @param box2 The second box.
 * @return Returns TRUE if both boxes are intersecting, else FALSE.
 */
bool boxIntersectsBox(Box box1, Box box2)
{
	// NOTE: The -1 for vertical/horizontal fixes curses colums representation
	int ax1 = box1.getCorner().getX();
	int ay1 = box1.getCorner().getY();
	int ax2 = box1.getCorner().getX() + box1.getHorizontal() - 1;
	int ay2 = box1.getCorner().getY() + box1.getVertical() - 1;
	int bx1 = box2.getCorner().getX();
	int by1 = box2.getCorner().getY();
	int bx2 = box2.getCorner().getX() + box2.getHorizontal() - 1;
	int by2 = box2.getCorner().getY() + box2.getVertical() - 1;

	// test honizontal overlap
	bool overlapX = (bx1 <= ax1 && ax1 <= bx2) ||
		(ax1 <= bx1 && bx1 <= ax2);

	// test vertical overlap
	bool overlapY = (by1 <= ay1 && ay1 <= by2) ||
		(ay1 <= by1 && by1 <= ay2);

	return overlapX && overlapY;
}

/**
 * Checks whether the value is in the given range.
 * @param value The value.
 * @param min The ranges minimum.
 * @param max The ranges maximum.
 * @return Returns TRUE, if value is in range, else FALSE:
 */
bool valueInRange(int value, int min, int max)
{
	return min <= value && value <= max;
}

/**
 * Converts relative bounding box for object to absolute world box.
 * @param p_object Points to the object to convert.
 * @return The converted bounding box in absolute world coordinates.
 */
Box getWorldBox(Object *p_object)
{
	return Box(); // TODO: implement
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

/**
 * Checks for intersection between two lines.
 * @param line1 The first line.
 * @param line2 The second line.
 * @param Returns TRUE if both lines intersects, else FALSE.
 */
bool lineIntersectsLine(Line line1, Line Line2)
{
	return false; // TODO: implement
}

/**
 * Checks for intersection between line and box.
 * @param line The line.
 * @param box The box.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool lineIntersectsBox(Line line, Box box)
{
	return false; // TODO: implement
}

/**
 * Checks for intersection between circle and box.
 * @param circle The circle.
 * @param box The box.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool circleIntersectsBox(Circle circle, Box box)
{
	return false; // TODO: implement
}

/**
 * Checks for intersection between twoe circles.
 * @param circle1 The first circle.
 * @param circle2 The second circle.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool circleIntersectsCircle(Circle circle1, Circle circle2)
{
	return false; // TODO: implement
}

/**
 * Calculates the distance between two positions.
 * @param position1 The first position.
 * @param position2 The second position.
 * @return The calculates distance.
 */
float distance(Position position1, Position position2)
{
	float deltaX = position2.getX() - position1.getX();
	float deltaY = position2.getY() - position1.getY();

	return (float)sqrt(deltaX * deltaX + deltaY * deltaY);
}

/**
 * Calculates the optimized squared distance between two positions.
 * @param position1 The first position.
 * @param position2 The second position.
 * @return The calculates squared distance.
 */
float distanceSquared(Position position1, Position position2)
{
	float deltaX = position2.getX() - position1.getX();
	float deltaY = position2.getY() - position1.getY();

	return deltaX * deltaX + deltaY * deltaY;
}
