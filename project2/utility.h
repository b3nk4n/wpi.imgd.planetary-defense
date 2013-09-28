/*******************************************************************************
 * @file        utility.h
 * @author      bsautermeister
 * @description Utility function modul used in different classes of the engine.
 ******************************************************************************/

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>
#include <sstream>
#include "Position.h"
#include "Box.h"
#include "Line.h"
#include "Circle.h"
#include "Object.h"
#include "Splash.h"
#include "GameManager.h"

 using std::string;

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
 * Checks for intersection between to boxes.
 * @param box1 The first box.
 * @param box2 The second box.
 * @return Returns TRUE if both boxes are intersecting, else FALSE.
 */
bool boxIntersectsBox(Box box1, Box box2);

/**
 * Checks whether the value is in the given range.
 * @param value The value.
 * @param min The ranges minimum.
 * @param max The ranges maximum.
 * @return Returns TRUE, if value is in range, else FALSE.
 */
bool valueInRange(int value, int min, int max);

/**
 * Clips the value to the given range.
 * @param value The value.
 * @param min The ranges minimum.
 * @param max The ranges maximum.
 * @return Returns the clipped value.
 */
int clipValue(int value, int min, int max);

/**
 * Converts relative bounding box for object to absolute world box.
 * @param p_object Points to the object to convert.
 * @return The converted bounding box in absolute world coordinates.
 */
Box getWorldBox(Object *p_object);

/**
 * Checks for intersection between a box and a position.
 * @param box The box/rectangle.
 * @param position The position.
 * @param Returns TRUE if the position intersects the box, else FALSE.
 */
bool boxContainsPoint(Box box, Position position);

/**
 * Checks for intersection between two lines.
 * @param line1 The first line.
 * @param line2 The second line.
 * @param Returns TRUE if both lines intersects, else FALSE.
 */
bool lineIntersectsLine(Line line1, Line Line2);

/**
 * Checks for intersection between line and box.
 * @param line The line.
 * @param box The box.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool lineIntersectsBox(Line line, Box box);

/**
 * Checks for intersection between circle and box.
 * @param circle The circle.
 * @param box The box.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool circleIntersectsBox(Circle circle, Box box);

/**
 * Checks for intersection between twoe circles.
 * @param circle1 The first circle.
 * @param circle2 The second circle.
 * @param Returns TRUE if both intersects, else FALSE.
 */
bool circleIntersectsCircle(Circle circle1, Circle circle2);

/**
 * Calculates the distance between two positions.
 * @param position1 The first position.
 * @param position2 The second position.
 * @return The calculates distance.
 */
float distance(Position position1, Position position2);

/**
 * Calculates the optimized squared distance between two positions.
 * @param position1 The first position.
 * @param position2 The second position.
 * @return The calculates squared distance.
 */
float distanceSquared(Position position1, Position position2);

/**
 * Converts the world position to view position
 * @param worldPosition The world position.
 * @return The converted view position.
 */
Position worldToView(Position worldPosition);

/**
 * Converts the view position to world position
 * @param viewPosition The view position.
 * @return The converted world position.
 */
Position viewToWorld(Position viewPosition);

/**
 * Converts an int value to a string.
 * @param value The value to convert.
 * @return The string converted value.
 */
string intToString(int value);

/**
 * Launch the splash screen.
 * @return Returns 0 if ok, else -1.
 */
int splash(void);

#endif
