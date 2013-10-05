/*******************************************************************************
* @file        Tower.cpp
* @author      kcbryant
* @description Base class for offensive tower buildings.
******************************************************************************/

#include "Tower.h"
#include "EventStep.h"
#include "Bullet.h"

/**
 * Creates a new tower object.
 * @param name The name.
 * @param spriteName The name of the sprite.
 * @param cost The cost.
 * @param energy The energy cost or value.
 * @param fireRate The fire rate.
 * @param firePower The fire power.
 * @param fireRange The fire range.
 */
Tower::Tower(string name, string spriteName, int cost, int energy,
	int fireRate, int firePower, int fireRange)
	: Building(name, spriteName, cost, energy)
{
	_fireRate = fireRate;
	_firePower = firePower;
	_fireRange = fireRange;

	// register events
	registerInterest(STEP_EVENT);
}

/** 
 * Shoots a bullet at the enemy
 * @param string, type of bullet it shoots
 */
void Tower::shoot(string type)
{	
	new Bullet(type, 2, 0, _firePower, this);
}
/**
 * Finds the closest enemy to the tower
 * @return Enemy, the target enemy
 */
Enemy Tower::findTarget()
{

}

/**
 * Cleans the tower object.
 */
Tower::~Tower(void)
{
}

/**
* Handle the tower events, like selecting the appropriate frame index,
* seeking or attacking enemies.
* @return Returns 1 if event was handled, else 0.
*/
int Tower::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
  		shoot("bullet_1");
  		return 1;
	}
}

/**
* Gets the fire rate.
* @return The fire rate.
*/
int Tower::getFireRate(void)
{
	return _fireRate;
}

/**
 * Gets the fire power.
 * @return The fire power.
 */
int Tower::getFirePower(void)
{
	return _firePower;
}

/**
 * Gets the fire range.
 * @return The fire range.
 */
int Tower::getFireRange(void)
{
	return _fireRange;
}
