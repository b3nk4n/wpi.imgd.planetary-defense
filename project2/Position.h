/*******************************************************************************
 * @file        Position.h
 * @author      bsautermeister
 * @description A simple position in a 2D world. The origin (0,0) is at the
 *              top left corner.
 ******************************************************************************/

#ifndef __POSITION_H__
#define __POSITION_H__

/**
 * Class representing a 2D position.
 */
class Position
{
private:
	/**
	 * The x axis position.
	 */
	int _x;

	/**
	 * The y axis position.
	 */
	int _y;

public:
	/**
	 * Creates a new position with default value (0,0).
	 */
	Position(void);

	/**
	 * Creates a new position.
	 * @param x The x axis value.
	 * @param y The y axis value.
	 */
	Position(int x, int y);

	/**
	 * Gets the x value.
	 * @return The current x value.
	 */
	int getX(void);

	/**
	 * Sets the x value.
	 * @param x The new x value.
	 */
	void setX(int x);

	/**
	 * Gets the y value.
	 * @return The current y value.
	 */
	int getY(void);

	/**
	 * Sets the y value.
	 * @param y The new y value.
	 */
	void setY(int y);

	/**
	 * Sets the x and y value.
	 * @param x The new x value.
	 * @param y The new y value.
	 */
	void setXY(int x, int y);
};

#endif