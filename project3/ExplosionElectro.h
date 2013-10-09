/*******************************************************************************
 * @file        ExplosionElectro.h
 * @author      bsautermeister
 * @description The electro explosion effect.
 ******************************************************************************/

#ifndef EXPLOSION_ELECTRO_H
#define EXPLOSION_ELECTRO_H

#include "Explosion.h"

/**
 * Represents a electro explosion.
 */
class ExplosionElectro : public Explosion
{
public:
	/**
	 * Creates a new electro explosion instance.
	 * @param position The explosion center.
	 */
	ExplosionElectro(Position position);
};

#endif
