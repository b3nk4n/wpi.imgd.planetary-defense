/*******************************************************************************
 * @file        MachineGunTower.cpp
 * @author      bsautermeister
 * @description The machine gun tower, which fires some bullets.
 ******************************************************************************/

#include "MachineGunTower.h"
#include "Bullet.h"

/**
 * Creates a new machine gun tower object.
 */
MachineGunTower::MachineGunTower(void)
	: Tower(TOWER_MACHINE_GUN, "mgtower",
		INIT_PRICE_MACHINE_GUN, INIT_ENERGY_MACHINE_GUN,
		INIT_FIRE_RATE_MACHINE_GUN, INIT_FIRE_POWER_MACHINE_GUN, INIT_FIRE_RANGE_MACHINE_GUN, true)
{

}

/**
 * Fires a projectile at the enemy object.
 * @param p_object The enemy object. 
 */
void MachineGunTower::fire(Object *p_object)
{	
	new Bullet(getPosition(),
		p_object->getPosition(),
		getFirePower());
}
