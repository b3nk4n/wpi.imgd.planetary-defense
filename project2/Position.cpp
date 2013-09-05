/*******************************************************************************
 * @file        Position.cpp
 * @author      bsautermeister
 * @description A simple position in a 2D world. The origin (0,0) is at the
 *              top left corner.
 ******************************************************************************/

#include "Position.h"

/**
 * Creates a new position with default value (0,0).
 */
Position::Position(void)
{
	setXY(0, 0);
}

/**
 * Creates a new position.
 * @param x The x axis value.
 * @param y The y axis value.
 */
Position::Position(int x, int y)
{
	setXY(x, y);
}

/**
 * Gets the x value.
 * @return The current x value.
 */
int Position::getX(void)
{
	return _x;
}

/**
 * Sets the x value.
 * @param x The new x value.
 */
void Position::setX(int x)
{
	_x = x;
}

/**
 * Gets the y value.
 * @return The current y value.
 */
int Position::getY(void)
{
	return _y;
}

/**
 * Sets the y value.
 * @param y The new y value.
 */
void Position::setY(int y)
{
	_y = y;
}

/**
 * Sets the x and y value.
 * @param x The new x value.
 * @param y The new y value.
 */
void Position::setXY(int x, int y)
{
	_x = x;
	_y = y;
}
