/*******************************************************************************
 * @file        TeslaTower.h
 * @author      bsautermeister
 * @description The tesla tower, which fires a splash damage shock.
 ******************************************************************************/

#include "TeslaTower.h"
#include "WorldManager.h"
#include "EventDetonation.h"
#include "ExplosionElectro.h"
#include "Circle.h"

/**
 * Creates a new tesla tower object.
 */
TeslaTower::TeslaTower(void)
	: Tower(TOWER_TESLA, "teslatower",
		INIT_PRICE_TESLA, INIT_ENERGY_TESLA,
		INIT_FIRE_RATE_TESLA, INIT_FIRE_POWER_TESLA, INIT_FIRE_RANGE_TESLA, false)
{

}

/**
 * Fires a tesla at the enemy object.
 * @param p_object The enemy object. 
 */
void TeslaTower::fire(Object *p_object)
{
	WorldManager &worldManager = WorldManager::getInstance();
	EventDetonation event(
		Circle(
			getPosition(),
			getFireRange()),
		getFirePower());
	worldManager.onEvent(&event);

	new ExplosionElectro(getPosition());
}
