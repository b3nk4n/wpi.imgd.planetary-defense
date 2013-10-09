/*******************************************************************************
 * @file        LaserTower.h
 * @author      bsautermeister
 * @description The laser tower, which fires a fly through lasers.
 ******************************************************************************/

#include "LaserTower.h"
#include "Laser.h"

/**
 * Creates a new laser tower object.
 */
LaserTower::LaserTower(void)
	: Tower(TOWER_LASER, "lasertower",
		INIT_PRICE_LASER, INIT_ENERGY_LASER,
		45, 1, 15, true)
{

}

/**
 * Fires a laser at the enemy object.
 * @param p_object The enemy object. 
 */
void LaserTower::fire(Object *p_object)
{
	new Laser(getPosition(),
		p_object->getPosition(),
		getFirePower());
}
