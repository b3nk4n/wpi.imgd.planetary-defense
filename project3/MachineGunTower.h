/*******************************************************************************
 * @file        MachineGunTower.h
 * @author      bsautermeister
 * @description The machine gun tower, which fires some bullets.
 ******************************************************************************/

#ifndef __MACHINE_GUN_TOWER_H__
#define __MACHINE_GUN_TOWER_H__

#include "Tower.h"

#define TOWER_MACHINE_GUN "MG Tower"
#define KEY_MACHINE_GUN '2'
#define INIT_PRICE_MACHINE_GUN 250
#define INIT_ENERGY_MACHINE_GUN -3
#define INIT_FIRE_RATE_MACHINE_GUN 30
#define INIT_FIRE_POWER_MACHINE_GUN 5
#define INIT_FIRE_RANGE_MACHINE_GUN 10

/*
* Represents a machine gun tower that fires bullets.
*/
class MachineGunTower : public Tower
{
public:
 	/**
 	 * Creates a new machine gun tower object.
 	 */
 	MachineGunTower(void);

 	/**
 	 * Fires a projectile at the enemy object.
	 * @param p_object The enemy object. 
	 */
	virtual void fire(Object *p_object);

};

#endif

