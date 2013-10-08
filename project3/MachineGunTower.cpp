/*******************************************************************************
 * @file        MachineGunTower.cpp
 * @author      bsautermeister
 * @description The machine gun tower, which fires some bullets.
 ******************************************************************************/

#include "MachineGunTower.h"
#include "Bullet.h"
#include "MapObject.h"

/**
 * Creates a new machine gun tower object.
 */
MachineGunTower::MachineGunTower(void)
	: Tower(TOWER_MACHINE_GUN, "mgtower",
		INIT_PRICE_MACHINE_GUN, -INIT_ENERGY_MACHINE_GUN, 30, 2, 10)
{

}

/**
 * Fires a projectile at the enemy object.
 * @param p_object The enemy object. 
 */
void MachineGunTower::fire(Object *p_object)
{	
	new Bullet(getPosition(), p_object->getPosition());
}
