/* Hitpoints.h */

#ifndef HITPOINTS_H
#define HITPOINTS_H

#include "ViewObject.h"

#define HITPOINTS_STRING "HP"

class Hitpoints : public ViewObject
{
public:
	/**
	 * Creates a new hitpoints instance.
	 */
	Hitpoints(void);
	/**
	 * Render the hp bar.
	 */
	void draw(void);
};

#endif
