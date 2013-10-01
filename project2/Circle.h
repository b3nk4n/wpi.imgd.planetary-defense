/*******************************************************************************
 * @file        Circle.h
 * @author      bsautermeister
 * @description A simple circle in a 2D world.
 ******************************************************************************/

#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Position.h"

/**
 * Class representing a 2D circle.
 */
class Circle
{
private:
	/**
	 * The center of the circle.
	 */
	Position _center;

	/**
	 * The radius.
	 */
	float _radius;

public:
	/**
	 * Creates a new 2d circle instnce with 0 radius.
	 */
	Circle(void);

	/**
	 * Creates a new 2d circle instance.
	 * @param center The center position of the circle.
	 * @param radius The circles radius.
	 */
	Circle(Position center, float radius);

	/**
	 * Overrides the comparison operator to compare two circles.
	 * @param otherCircle The other circle.
	 * @return Returns TRUE if both circles have the same
	 *         coordinates, else false.
	 */
	bool operator==(Circle otherCircle) const;

	/**
	 * Overrides the negated comparison operator to compare two circles.
	 * @param otherCircle The other circle.
	 * @return Returns TRUE if both circles do not have the same
	 *         coordinates, else false.
	 */
	bool operator!=(Circle otherCircle) const;

	/**
	 * Gets the center of the circle.
	 * @return The center of the circle.
	 */
	Position getCenter(void);

	/**
	 * Sets the center of the circle.
	 * @param center center corner of the circle.
	 */
	void setCenter(Position center);

	/**
	 * Gets the radius of the circle.
	 * @return The radius.
	 */
	float getRadius(void);

	/**
	 * Sets the radius of the circle.
	 * @param The radius.
	 */
	void setRadius(int value);
};

#endif
