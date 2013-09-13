/*******************************************************************************
 * @file        utility.h
 * @author      bsautermeister
 * @description Utility function modul used in different classes of the engine.
 ******************************************************************************/

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <sstream>
#include "Position.h"
#include "Box.h"

/**
 * Gets the current time as a string.
 * @return The current time string.
 */
char *getTimeString(void);

/**
 * Checks for positoin intersection.
 * @param position1 The first position.
 * @param position2 The second position.
 * @return Returns TRUE if positions are intersection, else FALSE.
 */
bool positionIntersect(Position position1, Position position2);

/**
 * Checks for intersection between a box and a position.
 * @param box The box/rectangle.
 * @param position The position.
 * @param Returns TRUE if the position intersects the box, else false.
 */
bool boxContainsPoint(Box box, Position position);

#endif
