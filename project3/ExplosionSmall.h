/*******************************************************************************
 * @file        ExplosionSmall.h
 * @author      bsautermeister
 * @description The small explosion effect.
 ******************************************************************************/

#ifndef EXPLOSION_SMALL_H
#define EXPLOSION_SMALL_H

#include "Explosion.h"

/**
 * Represents a small explosion.
 */
class ExplosionSmall : public Explosion
{
public:
	/**
	 * Creates a new small explosion instance.
	 * @param position The explosion center.
	 */
	ExplosionSmall(Position position);
};

#endif
