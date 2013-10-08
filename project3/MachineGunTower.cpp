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
	: Tower(TOWER_MACHINE_GUN, "machinegun",
		INIT_PRICE_MACHINE_GUN, -3, 30, 2, 5)
{

}

/**
 * Fires a projectile at the enemy object.
 * @param p_object The enemy object. 
 */
void MachineGunTower::fire(Object *p_object)
{	
	MapObject* mapObject = MapObject::getInstance();
	if (mapObject->isPassable(p_object->getPosition()) == false)
	{
		new Bullet(getPosition(), p_object->getPosition());
	}
}
