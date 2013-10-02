/*******************************************************************************
 * @file        Box.cpp
 * @author      bsautermeister
 * @description A simple box in a 2D world. The origin (0,0) is at the
 *              top left corner.
 ******************************************************************************/

#include "Box.h"

/**
 * Creates a new box in the top left corner (0,0)
 * without any width or height.
 */
Box::Box(void)
{
	setHorizontal(0);
	setVertical(0);
}

/**
 * Creates a new 2d box.
 * @param corner The top left position of the box.
 * @param horizontal The horizontal width of the box.
 * @param vertical The vertical height of the box.
 */
Box::Box(Position corner, int horizontal, int vertical)
{
	setCorner(corner);
	setHorizontal(horizontal);
	setVertical(vertical);
}

/**
 * Overrides the comparison operator to compare two boxs.
 * @param otherBox The other box.
 * @return Returns TRUE if both boxs have the same
 *         coordinates, else false.
 */
bool Box::operator==(Box otherBox) const
{
	return _corner == otherBox.getCorner() &&
		_horizontal == otherBox.getHorizontal() &&
		_vertical == otherBox.getVertical();
}

/**
 * Overrides the negated comparison operator to compare two boxs.
 * @param otherBox The other box.
 * @return Returns TRUE if both boxs do not have the same
 *         coordinates, else false.
 */
bool Box::operator!=(Box otherBox) const
{
	return !(*this == otherBox);
}

/**
 * Gets the top left corner of the box.
 * @return The top left corner of the box.
 */
Position Box::getCorner(void)
{
	return _corner;
}

/**
 * Sets the top left corner of the box.
 * @param corner The top left corner of the box.
 */
void Box::setCorner(Position corner)
{
	_corner = corner;
}

/**
 * Gets the horizonal width of the box.
 * @return The horizontal width.
 */
int Box::getHorizontal(void)
{
	return _horizontal;
}

/**
 * Sets the horizontal width of the box.
 * @param The horizontal width.
 */
void Box::setHorizontal(int value)
{
	_horizontal = value;
}

/**
 * Gets the vertical height of the box.
 * @return The vertical height.
 */
int Box::getVertical(void)
{
	return _vertical;
}

/**
 * Sets the vertical height of the box.
 * @param The vertical height.
 */
void Box::setVertical(int value)
{
	_vertical = value;
}
