/*******************************************************************************
* @file        Line.cpp
* @author      bsautermeister
* @description A simple line in a 2D world.
******************************************************************************/

#include "Line.h"

/**
 * Creates a new 2d line instance.
 */
Line::Line(void)
{

}

/**
 * Creates a new 2d line instance.
 * @param position1 The start position of the line.
 * @param position2 The end position of the line.
 */
Line::Line(Position position1, Position position2)
{
	_position1 = position1;
	_position2 = position2;
}

/**
 * Overrides the comparison operator to compare two lines.
 * @param otherLine The other line.
 * @return Returns TRUE if both lines have the same
 *         coordinates, else false.
 */
bool Line::operator==(Line otherLine) const
{
	return _position1 == otherLine.getPosition1() &&
		_position2 == otherLine.getPosition2() ||
		_position1 == otherLine.getPosition2() &&
		_position2 == otherLine.getPosition1();
}

/**
 * Overrides the negated comparison operator to compare two lines.
 * @param otherLine The other line.
 * @return Returns TRUE if both lines do not have the same
 *         coordinates, else false.
 */
bool Line::operator!=(Line otherLine) const
{
	return !(*this == otherLine);
}

/**
 * Gets the start position of the line.
 * @return The start position of the line.
 */
Position Line::getPosition1(void)
{
	return _position1;
}

/**
 * Sets the start positoin of the line.
 * @param position The start position of the line.
 */
void Line::setPosition1(Position position)
{
	_position1 = position;
}

/**
 * Gets the end position of the line.
 * @return The end position of the line.
 */
Position Line::getPosition2(void)
{
	return _position2;
}

/**
 * Sets the end positoin of the line.
 * @param position The end position of the line.
 */
void Line::setPosition2(Position position)
{
	_position2 = position;
}
