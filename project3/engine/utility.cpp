/*******************************************************************************
 * @file        utility.cpp
 * @author      bsautermeister
 * @description Utility function modul used in different classes of the engine.
 ******************************************************************************/

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <sstream>

#include "utility.h"
#include "Object.h"
#include "WorldManager.h"
#include "Splash.h"
#include "SplashDragonfly.h"
#include "LogManager.h"

using std::stringstream;

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

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
	// fixed witdh/height for curses
	int b1h = MAX(0, box1.getHorizontal() - 1);
	int b1v = MAX(0, box1.getVertical() - 1);
	int b2h = MAX(0, box2.getHorizontal() - 1);
	int b2v = MAX(0, box2.getVertical() - 1);

	// NOTE: The -1 for vertical/horizontal fixes curses colums representation
	int ax1 = box1.getCorner().getX();
	int ay1 = box1.getCorner().getY();
	int ax2 = box1.getCorner().getX() + b1h;
	int ay2 = box1.getCorner().getY() + b1v;
	int bx1 = box2.getCorner().getX();
	int by1 = box2.getCorner().getY();
	int bx2 = box2.getCorner().getX() + b2h;
	int by2 = box2.getCorner().getY() + b2v;

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
 * @return Returns TRUE, if value is in range, else FALSE.
 */
bool valueInRange(int value, int min, int max)
{
	return min <= value && value <= max;
}

/**
 * Clips the value to the given range.
 * @param value The value.
 * @param min The ranges minimum.
 * @param max The ranges maximum.
 * @return Returns the clipped value.
 */
int clipValue(int value, int min, int max)
{
	if (min > value)
		return min;

	if (max < value)
		return max;

	return value;
}

/**
 * Converts relative bounding box for object to absolute world box.
 * @param p_object Points to the object to convert.
 * @return The converted bounding box in absolute world coordinates.
 */
Box getWorldBox(Object *p_object)
{
	int x = p_object->getPosition().getX();
	int y = p_object->getPosition().getY();
	int bx = p_object->getBox().getCorner().getX();
	int by = p_object->getBox().getCorner().getY();
	int h = p_object->getBox().getHorizontal();
	int v = p_object->getBox().getVertical();

	if (p_object->isCentered())
	{
		x -= h / 2;
		y -= v / 2;
	}

	return Box(Position(x + bx, y + by), h, v);
}

/**
 * Checks for intersection between a box and a position.
 * @param box The box/rectangle.
 * @param position The position.
 * @param Returns TRUE if the position intersects the box, else false.
 */
bool boxContainsPoint(Box box, Position position)
{
	// fixed witdh/height for curses
	int bh = MAX(0, box.getHorizontal() - 1);
	int bv = MAX(0, box.getVertical() - 1);

	int boxX = box.getCorner().getX();
	int boxY = box.getCorner().getY();

	return position.getX() >= boxX &&
		position.getX() <= boxX + bh &&
		position.getY() >= boxY &&
		position.getY() <= boxY + bv;
}

/**
 * Checks for intersection between two lines.
 * @note codesource: http://stackoverflow.com/questions/9043805/
 *                   test-if-two-lines-intersect-javascript-function
 * @param line1 The first line.
 * @param line2 The second line.
 * @param Returns TRUE if both lines intersects, else FALSE.
 */
bool lineIntersectsLine(Line line1, Line line2)
{
	int x1 = line1.getPosition1().getX();
	int y1 = line1.getPosition1().getY();
	int x2 = line1.getPosition2().getX();
	int y2 = line1.getPosition2().getY();
	int x3 = line2.getPosition1().getX();
	int y3 = line2.getPosition1().getY();
	int x4 = line2.getPosition2().getX();
	int y4 = line2.getPosition2().getY();

	int overX = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	int underX = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	int overY = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
	int underY = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	// check for zero-division
	if (underX == 0 || underY == 0)
		return false;

	float x = overX/underX;
    float y = overY/underY;

    if (x1>=x2) {
        if (!(x2<=x&&x<=x1))
        	return false;
    }
    else
    {
        if (!(x1<=x&&x<=x2)) 
        	return false;
    }

    if (y1>=y2)
    {
        if (!(y2<=y&&y<=y1)) 
        	return false;
    } else {
        if (!(y1<=y&&y<=y2))
        	return false;
    }

    if (x3>=x4)
    {
        if (!(x4<=x&&x<=x3))
        	return false;
    } else
    {
        if (!(x3<=x&&x<=x4))
        	return false;
    }

    if (y3>=y4)
    {
        if (!(y4<=y&&y<=y3))
        	return false;
    } else
    {
        if (!(y3<=y&&y<=y4))
        	return false;
    }

    return true;
}

/**
 * Checks for intersection between line and box (incl. surface).
 * @param line The line.
 * @param box The box.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool lineIntersectsBox(Line line, Box box)
{
	// fixed witdh/height for curses
	int bh = MAX(0, box.getHorizontal() - 1);
	int bv = MAX(0, box.getVertical() - 1);

	int px1 = line.getPosition1().getX();
	int py1 = line.getPosition1().getY();
	int px2 = line.getPosition2().getX();
	int py2 = line.getPosition2().getY();

	int bLeftX = box.getCorner().getX();
	int bTopY = box.getCorner().getY();
	int bRightX = box.getCorner().getX() + bh;
	int bBottomY = box.getCorner().getY() + bv;

	// check if both line positions are outside a edgle
	if (py1 < bTopY && py2 < bTopY || // top
		py1 > bRightX && py2 > bRightX || // right
		py1 > bBottomY && py2 > bBottomY || // bottom
		py1 < bLeftX && py2 < bLeftX) // left
		return false;

	// check of one line point is inside the box
	if (boxContainsPoint(box, line.getPosition1()) ||
		boxContainsPoint(box, line.getPosition2()))
		return true;

	// check line intersection with all four edges
	return lineIntersectsLine(line, // top
		Line(
			Position(bLeftX, bTopY),
			Position(bRightX, bTopY))) || 
		lineIntersectsLine(line, // right
		Line(
			Position(bRightX, bTopY),
			Position(bRightX, bBottomY))) ||
		lineIntersectsLine(line, // bottom
		Line(
			Position(bLeftX, bBottomY),
			Position(bRightX, bBottomY))) ||
		lineIntersectsLine(line, // left
		Line(
			Position(bLeftX, bTopY),
			Position(bLeftX, bBottomY)));
}

/**
 * Checks for intersection between circle and box.
 * @param circle The circle.
 * @param box The box.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool circleIntersectsBox(Circle circle, Box box)
{
	// fixed witdh/height for curses
	int bh = MAX(0, box.getHorizontal() - 1);
	int bv = MAX(0, box.getVertical() - 1);

	float cr = circle.getRadius();
	Position cc = circle.getCenter();
	Box higherBox(
		Position(box.getCorner().getX(), (int)(box.getCorner().getY() - cr)),
		bh,
		(int)(bv + 2 * cr));
	Box widerBox(
		Position((int)(box.getCorner().getX() - cr), box.getCorner().getY()),
		(int)(bh + 2 * cr),
		bv);

	// check circle is inside the higher/wider box
	if (boxContainsPoint(higherBox, cc) ||
		boxContainsPoint(widerBox, cc))
		return true;

	// check corners
	float crSquared = cr * cr;
	Position topLeft(box.getCorner().getX(),
		box.getCorner().getY());
	Position topRight(box.getCorner().getX() + bh,
		box.getCorner().getY());
	Position bottomLeft(box.getCorner().getX(),
		box.getCorner().getY() + bv);
	Position bottomRight(box.getCorner().getX() + bh,
		box.getCorner().getY() + bv);
	if (distanceSquared(cc, topLeft) < crSquared ||
		distanceSquared(cc, topRight) < crSquared ||
		distanceSquared(cc, bottomLeft) < crSquared ||
		distanceSquared(cc, bottomRight) < crSquared)
		return true;

	return false;
}

/**
 * Checks for intersection between twoe circles.
 * @param circle1 The first circle.
 * @param circle2 The second circle.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool circleIntersectsCircle(Circle circle1, Circle circle2)
{
	float r1 = circle1.getRadius();
	float r2 = circle2.getRadius();

	return (r1 + r2) * (r1 + r2) >=
		distanceSquared(circle1.getCenter(), circle2.getCenter());
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

/**
 * Converts the world position to view position
 * @param worldPosition The world position.
 * @return The converted view position.
 */
Position worldToView(Position worldPosition)
{
	WorldManager &worldManager = WorldManager::getInstance();
	Position viewOrigin = worldManager.getViewBoundary().getCorner();
	int viewX = viewOrigin.getX();
	int viewY = viewOrigin.getY();
	Position viewPosition(worldPosition.getX() - viewX,
		worldPosition.getY() - viewY);
	return viewPosition;
}

/**
 * Converts the view position to world position
 * @param viewPosition The view position.
 * @return The converted world position.
 */
Position viewToWorld(Position viewPosition)
{
	WorldManager &worldManager = WorldManager::getInstance();
	Position viewOrigin = worldManager.getViewBoundary().getCorner();
	int viewX = viewOrigin.getX();
	int viewY = viewOrigin.getY();
	Position worldPosition(viewPosition.getX() + viewX,
		viewPosition.getY() + viewY);
	return worldPosition;
}

/**
 * Converts an int value to a string.
 * @param value The value to convert.
 * @return The string converted value.
 */
string intToString(int value)
{
	stringstream ss;
	ss << value;
	return ss.str();
}

/**
 * Launch the splash screen.
 * @return Returns 0 if ok, else -1.
 */
int splash(void)
{
	GameManager &gameManager = GameManager::getInstance();
	
	if (!gameManager.isStarted())
		return -1;

	new Splash();
	gameManager.run();
	return 0;
}
