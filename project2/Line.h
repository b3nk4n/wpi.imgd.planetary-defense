/*******************************************************************************
 * @file        Line.h
 * @author      bsautermeister
 * @description A simple line in a 2D world.
 ******************************************************************************/

#ifndef __LINE_H__
#define __LINE_H__

#include "Position.h"

/**
 * Class representing a 2D line.
 */
class Line
{
private:
	/**
	 * The start of the line.
	 */
	Position _position1;

	/**
	 * The end of the line.
	 */
	Position _position2;

public:
	/**
	 * Creates a new 2d line instance.
	 */
	Line(void);

	/**
	 * Creates a new 2d line instance.
	 * @param position1 The start position of the line.
	 * @param position2 The end position of the line.
	 */
	Line(Position position1, Position position2);

	/**
	 * Overrides the comparison operator to compare two lines.
	 * @param otherLine The other line.
	 * @return Returns TRUE if both lines have the same
	 *         coordinates, else false.
	 */
	bool operator==(Line otherLine) const;

	/**
	 * Overrides the negated comparison operator to compare two lines.
	 * @param otherLine The other line.
	 * @return Returns TRUE if both lines do not have the same
	 *         coordinates, else false.
	 */
	bool operator!=(Line otherLine) const;

	/**
	 * Gets the start position of the line.
	 * @return The start position of the line.
	 */
	Position getPosition1(void);

	/**
	 * Sets the start positoin of the line.
	 * @param position The start position of the line.
	 */
	void setPosition1(Position position);

	/**
	 * Gets the end position of the line.
	 * @return The end position of the line.
	 */
	Position getPosition2(void);

	/**
	 * Sets the end positoin of the line.
	 * @param position The end position of the line.
	 */
	void setPosition2(Position position);
};

#endif
