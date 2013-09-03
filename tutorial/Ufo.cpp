/* Ufo.cpp */

#include "Ufo.h"

/**
 * Creates a new Ufo instance.
 */
Ufo::Ufo(void)
	: Enemy("ufo", 2, 50, 0.15f, EXPLOSION_LARGE)
{
}

/**
 * Creates a new Ufo.
 */
void Ufo::createEnemy(void)
{
	new Ufo();
}