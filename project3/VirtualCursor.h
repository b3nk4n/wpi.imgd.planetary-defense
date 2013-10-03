/*******************************************************************************
 * @file        VirtualCursor.h
 * @author      bsautermeister
 * @description The virtual cursor in a 2D tile based game world.
 ******************************************************************************/

#ifndef __VIRTUAL_CURSOR_H__
#define __VIRTUAL_CURSOR_H__

#include "Object.h"

#define TYPE_CURSOR "cursor"

/**
 * Represents a virtual cursor in a 2D tiles based world.
 */
class VirtualCursor : public Object
{
public:
	/**
	 * Creates a virtual cursors instance.
	 * @param the position of the cursors in the world.
	 */
	VirtualCursor(Position position);

	/**
	 * Cleans up the cursor resources.
	 */
	~VirtualCursor(void);
};

#endif
