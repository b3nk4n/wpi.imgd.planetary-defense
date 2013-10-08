/*******************************************************************************
 * @file        GrenadeTower.h
 * @author      bsautermeister
 * @description The grenade tower, which fires some splash damage grenades.
 ******************************************************************************/

#ifndef __GRENADE_TOWER_H__
#define __GRENADE_TOWER_H__

#include "Tower.h"

#define TOWER_GRENADE "grenade"
#define INIT_PRICE_GRENADE 250
#define INIT_ENERGY_GRENADE 4

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