/* Saucer.cpp */

#include "Saucer.h"
#include "LogManager.h"

/**
 * Creates a new saucer instance.
 */
Saucer::Saucer(void)
	: Enemy("saucer", 1, 10, 0.01f, EXPLOSION_SMALL)
{
}

/**
 * Creates a new Saucer.
 */
void Saucer::createEnemy(void)
{
	new Saucer();
}