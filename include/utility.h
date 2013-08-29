//
// Utility functions to support Dragonfly and its games.
//
// Functions here do not use any attributes of any classes, so
// can stand alone.
//

#ifndef __UTILITY_H__
#define __UTILITY_H__

// System includes
#include <sstream>		// for intToString()

// Engine includes
#include "Box.h"
#include "Circle.h"
#include "Line.h"
#include "Object.h"
#include "Position.h"

// Function prototypes

// Return true if value is between min and max (inclusive).
bool valueInRange(int value, int min, int max);

// Convert relative bounding Box for Object to absolute world Box.
Box getWorldBox(Object *p_o);

// Return distance between any two Points.
float distance(Position p1, Position p2);

// Return true of Point is within Box.
bool boxContainsPoint(Box b, Position p);

// Return true if Lines intersect.
bool lineIntersectsLine(Line line1, Line line2);

// Return true if Line intersects Box.
bool lineIntersectsBox(Line line, Box b);

// Return true if Boxes intersect.
bool boxIntersectsBox(Box box1, Box box2);

// Return true if Circle intersects or contains Box.
bool circleIntersectsBox(Circle circle, Box b);

// Launch splash screen. Return 0 if ok, else -1.
int splash();

// Returns pretty-formatted time as char * string.
char *getTimeString();	    

// Convert world position to view position.
Position worldToView(Position world_pos);

// Convert view position to world position.
Position viewToWorld(Position view_pos);

// Convert integer to string, returning string.
string intToString(int number);

#endif // __UTILITY_H__
