/*******************************************************************************
 * @file        SolarBuilding.h
 * @author      bsautermeister
 * @description The solar building to get some energy at constructin time.
 ******************************************************************************/

#ifndef __SOLAR_BUILDING_H__
#define __SOLAR_BUILDING_H__

#include "Building.h"

#define BUILDING_SOLAR "Solar Panel"
#define KEY_SOLAR '1'
#define INIT_PRICE_SOLAR 100
#define INIT_ENERGY_SOLAR 10

/*
* Represents a solar panel to get energy.
*/
class SolarBuilding : public Building
{
public:
 	/**
 	 * Creates a new solar building object.
 	 */
 	SolarBuilding(void);
};

#endif
