/*******************************************************************************
 * @file        GrenadeTower.h
 * @author      bsautermeister
 * @description The grenade tower, which fires some splash damage grenades.
 ******************************************************************************/

#include <stdlib.h>
#include "GrenadeTower.h"
#include "FragmentationGrenade.h"
#include "WorldManager.h"
#include "ExplosionBig.h"
#include "Circle.h"
#include "EventDetonation.h"

/**
 * Creates a new granade tower object.
 */
GrenadeTower::GrenadeTower(void)
	: Tower(TOWER_GRENADE, "grenadetower",
		INIT_PRICE_GRENADE, INIT_ENERGY_GRENADE,
		INIT_FIRE_RATE_GRENADE, INIT_FIRE_POWER_GRENADE, INIT_FIRE_RANGE_GRENADE, true)
{

}

/**
 * Fires a granade at the enemy object.
 * @param p_object The enemy object. 
 */
void GrenadeTower::fire(Object *p_object)
{
	/**
	 * More elegant solution, but causes radomly SEG FAULTs. Reason unknown :(
	 */
	/*new FragmentationGrenade(getPosition(),
		p_object->getPosition(),
		getFirePower());*/


	// random variance
	Position detonationPos = p_object->getPosition();
	detonationPos.setX(detonationPos.getX() - 3 + random() % 7);
	detonationPos.setY(detonationPos.getY() - 2 + random() % 5);

	WorldManager &worldManager = WorldManager::getInstance();
    EventDetonation event(Circle(detonationPos, DETONATION_RADIUS),
        getFirePower());
    
    worldManager.onEvent(&event);
 

    new ExplosionBig(detonationPos);
}
