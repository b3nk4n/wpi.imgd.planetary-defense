/* Hitpoints.h */

#ifndef HITPOINTS_H
#define HITPOINTS_H

#include "ViewObject.h"

#define HITPOINTS_STRING "HP"

class Hitpoints : public ViewObject
{
public:
	Hitpoints(void);
	void draw(void);
};

#endif