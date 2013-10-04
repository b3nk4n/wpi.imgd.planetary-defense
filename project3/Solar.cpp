/*******************************************************************************
 * @file        Solar.h
 * @author      bsautermeister
 * @description The solar building to get some energy at constructin time.
 ******************************************************************************/

#include "Solar.h"

/**
 * Creates a new solar building object.
 */
Solar::Solar(void)
	: Building(BUILDING_SOLAR, "assets/sprites/solar-spr.txt", 100, 5)
{
}
