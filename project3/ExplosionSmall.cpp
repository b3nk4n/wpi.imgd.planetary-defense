/*******************************************************************************
 * @file        ExplosionSmall.cpp
 * @author      bsautermeister
 * @description The small explosion effect.
 ******************************************************************************/

#include "ExplosionSmall.h"

/**
 * Creates a new small explosion instance.
 * @param position The explosion center.
 */
ExplosionSmall::ExplosionSmall(Position position)
	: Explosion("explosion_small", position, 1)
{

}
