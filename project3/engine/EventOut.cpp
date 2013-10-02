/*******************************************************************************
 * @file        EventOut.cpp
 * @author      bsautermeister
 * @description Out event class to notify other game objects to that an object
 *              has left the viewable game field.
 ******************************************************************************/

#include "EventOut.h"

/**
 * Creates a new out event instance.
 */
EventOut::EventOut(void)
{
	setType(OUT_EVENT);
}
