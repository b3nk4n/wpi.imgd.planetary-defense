/*******************************************************************************
 * @file        GrenadeTower.h
 * @author      bsautermeister
 * @description The grenade tower, which fires some splash damage grenades.
 ******************************************************************************/

#ifndef __GRENADE_TOWER_H__
#define __GRENADE_TOWER_H__

#include "Tower.h"

#define TOWER_GRENADE "Grenade Tower"
#define KEY_GRENADE '3'
#define INIT_PRICE_GRENADE 400
#define INIT_ENERGY_GRENADE -4
#define INIT_FIRE_RATE_GRENADE 60
#define INIT_FIRE_POWER_GRENADE 15
#define INIT_FIRE_RANGE_GRENADE 20

/*
* Represents a grenade tower with splash damage.
*/
class GrenadeTower : public Tower
{
public:
 	/**
 	 * Creates a new granade tower object.
 	 */
 	GrenadeTower(void);

 	/**
 	 * Fires a granade at the enemy object.
	 * @param p_object The enemy object. 
	 */
	virtual void fire(Object *p_object);
};

#endif

