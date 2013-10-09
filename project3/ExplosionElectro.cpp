/*******************************************************************************
 * @file        ExplosionElectro.cpp
 * @author      bsautermeister
 * @description The electro explosion effect.
 ******************************************************************************/

#include "ExplosionElectro.h"

/**
 * Creates a new electro explosion instance.
 * @param position The explosion center.
 */
ExplosionElectro::ExplosionElectro(Position position)
	: Explosion("explosion_electro", position, 1)
{

}
