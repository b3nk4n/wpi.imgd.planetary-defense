/*******************************************************************************
* @file        Circle.cpp
* @author      bsautermeister
* @description A simple circle in a 2D world.
******************************************************************************/

#include "Circle.h"

/**
 * Creates a new 2d circle instnce with 0 radius.
 */
Circle::Circle(void)
{
	_radius = 0;
}

/**
 * Creates a new 2d circle instance.
 * @param center The center position of the circle.
 * @param radius The circles radius.
 */
Circle::Circle(Position center, float radius)
{
	_center = center;
	_radius = radius;
}

/**
 * Overrides the comparison operator to compare two circles.
 * @param otherCircle The other circle.
 * @return Returns TRUE if both circles have the same
 *         coordinates, else false.
 */
bool Circle::operator==(Circle otherCircle) const
{
	return _center == otherCircle.getCenter() &&
		_radius == otherCircle.getRadius();
}

/**
 * Overrides the negated comparison operator to compare two circles.
 * @param otherCircle The other circle.
 * @return Returns TRUE if both circles do not have the same
 *         coordinates, else false.
 */
bool Circle::operator!=(Circle otherCircle) const
{
	return !(*this == otherCircle);
}

/**
 * Gets the center of the circle.
 * @return The center of the circle.
 */
Position Circle::getCenter(void)
{
	return _center;
}

/**
 * Sets the center of the circle.
 * @param center center corner of the circle.
 */
void Circle::setCenter(Position center)
{
	_center = center;
}

/**
 * Gets the radius of the circle.
 * @return The radius.
 */
int Circle::getRadius(void)
{
	return _radius;
}

/**
 * Sets the radius of the circle.
 * @param The radius.
 */
void Circle::setRadius(int value)
{
	_radius = value;
}
