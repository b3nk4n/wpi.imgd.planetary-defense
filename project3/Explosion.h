/*******************************************************************************
 * @file        Explosion.h
 * @author      bsautermeister
 * @description The explosion sprite effect base class.
 ******************************************************************************/

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Object.h"

#define TYPE_EXPLOSION "explosion"

/**
 * Represents a basic explosion using a sprite.
 */
class Explosion : public Object
{
private:
	/**
	 * The explosions life time.
	 */
	int _timeToLive;

public:
	/**
	 * Creates a new explosion instance.
	 * @param spriteName The name of the sprite resource.
	 * @param position The explosion center.
	 * @param slowdown The animation slowdown to adjust the effect speed.
	 */
	Explosion(string spriteName, Position position, int slowdown);

	/**
	 * Handles the explosions events.
	 * @param p_event The event.
	 */
	virtual int eventHandler(Event *p_event);
};

#endif
