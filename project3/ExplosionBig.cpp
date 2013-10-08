/*******************************************************************************
 * @file        ExplosionBig.cpp
 * @author      bsautermeister
 * @description The big explosion effect.
 ******************************************************************************/

#include "ExplosionBig.h"

/**
 * Creates a new big explosion instance.
 * @param position The explosion center.
 */
ExplosionBig::ExplosionBig(Position position)
	: Explosion("explosion_big", position, 2)
{

}
