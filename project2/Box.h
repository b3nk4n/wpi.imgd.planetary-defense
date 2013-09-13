/*******************************************************************************
 * @file        Box.h
 * @author      bsautermeister
 * @description A simple box in a 2D world. The origin (0,0) is at the
 *              top left corner.
 ******************************************************************************/

#ifndef __BOX_H__
#define __BOX_H__

#include "Position.h"

/**
 * Class representing a 2D box.
 */
class Box
{
private:
	/**
	 * The top left corner of the box.
	 */
	Position _corner;

	/**
	 * The horizonal width.
	 */
	int _horizontal;

	/**
	 * The vertical height.
	 */
	int _vertical;

public:
	/**
	 * Creates a new box in the top left corner (0,0)
	 * without any width or height.
	 */
	Box(void);

	/**
	 * Creates a new 2d box.
	 * @param corner The top left position of the box.
	 * @param horizontal The horizontal width of the box.
	 * @param vertical The vertical height of the box.
	 */
	Box(Position corner, int horizontal, int vertical);

	/**
	 * Overrides the comparison operator to compare two boxs.
	 * @param otherBox The other box.
	 * @return Returns TRUE if both boxs have the same
	 *         coordinates, else false.
	 */
	bool operator==(Box otherBox) const;

	/**
	 * Overrides the negated comparison operator to compare two boxs.
	 * @param otherBox The other box.
	 * @return Returns TRUE if both boxs do not have the same
	 *         coordinates, else false.
	 */
	bool operator!=(Box otherBox) const;

	/**
	 * Gets the top left corner of the box.
	 * @return The top left corner of the box.
	 */
	Position getCorner(void);

	/**
	 * Sets the top left corner of the box.
	 * @param corner The top left corner of the box.
	 */
	void setCorner(Position corner);

	/**
	 * Gets the horizonal width of the box.
	 * @return The horizontal width.
	 */
	int getHorizontal(void);

	/**
	 * Sets the horizontal width of the box.
	 * @param The horizontal width.
	 */
	void setHorizontal(int value);

	/**
	 * Gets the vertical height of the box.
	 * @return The vertical height.
	 */
	int getVertical(void);

	/**
	 * Sets the vertical height of the box.
	 * @param The vertical height.
	 */
	void setVertical(int value);
};

#endif
