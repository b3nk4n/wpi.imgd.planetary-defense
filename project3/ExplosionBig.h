/*******************************************************************************
 * @file        ExplosionBig.h
 * @author      bsautermeister
 * @description The big explosion effect.
 ******************************************************************************/

#ifndef EXPLOSION_BIG_H
#define EXPLOSION_BIG_H

#include "Explosion.h"

/**
 * Represents a big explosion.
 */
class ExplosionBig : public Explosion
{
public:
	/**
	 * Creates a new big explosion instance.
	 * @param position The explosion center.
	 */
	ExplosionBig(Position position);
};

#endif
