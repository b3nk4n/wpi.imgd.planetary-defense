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
#define INIT_PRICE_MACHINE_GUN 150
#define INIT_ENERGY_MACHINE_GUN -3

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

