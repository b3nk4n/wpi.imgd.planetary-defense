/*******************************************************************************
 * @file        TeslaTower.h
 * @author      bsautermeister
 * @description The tesla tower, which fires a splash damage shock.
 ******************************************************************************/

#ifndef __TESLA_TOWER_H__
#define __TESLA_TOWER_H__

#include "Tower.h"

#define TOWER_TESLA "Tesla Tower"
#define KEY_TESLA '5'
#define INIT_PRICE_TESLA 750
#define INIT_ENERGY_TESLA -8
#define INIT_FIRE_RATE_TESLA 75
#define INIT_FIRE_POWER_TESLA 40
#define INIT_FIRE_RANGE_TESLA 15

/*
* Represents a tesla tower with splash damage.
*/
class TeslaTower : public Tower
{
public:
 	/**
 	 * Creates a new tesla tower object.
 	 */
 	TeslaTower(void);

 	/**
 	 * Fires a tesla at the enemy object.
	 * @param p_object The enemy object. 
	 */
	virtual void fire(Object *p_object);
};

#endif

