/*******************************************************************************
 * @file        SolarBuilding.cpp
 * @author      bsautermeister
 * @description The solar building to get some energy at constructin time.
 ******************************************************************************/

#include "SolarBuilding.h"

/**
 * Creates a new solar building object.
 */
SolarBuilding::SolarBuilding(void)
	: Building(BUILDING_SOLAR, "solar", INIT_PRICE_SOLAR, 8)
{
}
