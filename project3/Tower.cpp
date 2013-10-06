/*******************************************************************************
* @file        Tower.cpp
* @author      kcbryant
* @description Base class for offensive tower buildings.
******************************************************************************/

#include "Tower.h"
#include "EventStep.h"
#include "Bullet.h"
#include "Spawner.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

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
	_coolDown = 0;

	// register events
	registerInterest(STEP_EVENT);
}

/** 
 * Shoots a bullet at the enemy
 * @param string, type of bullet it shoots
 */
void Tower::shoot(string type)
{	
	new Bullet(type, 5, 0, _firePower, this, findTarget()); //5 firerate = machine gun
}

/**
 * Finds the next target of tower
 * @return Enemy, the target enemy
 */
Object* Tower::findTarget()
{	
	Object* enemy_best; 
 	ObjectList* enemies;

	Spawner* sp = Spawner::Instance();
	enemies = sp->getEnemies();
	ObjectListIterator enemyIt = ObjectListIterator(enemies);
	enemyIt.first();
	enemy_best = enemyIt.currentObject();
	while (enemyIt.isDone() != true){
		if (isClose(enemyIt.currentObject()) < isClose(enemy_best)){
			enemy_best = enemyIt.currentObject();
		}
		enemyIt.next();
	}

	return enemy_best;
}

/**
 * gives a closeness value
 * @param Enemy, that you are deciding whether or not to target
 * @return int, closeness value of enemy
 */
int Tower::isClose(Object *enemy)
{	

	return 0;
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
		_coolDown = _coolDown + _fireRate;
		if (_coolDown >= 250){
			shoot("bullet_1");
			_coolDown = 0;
		}
  		
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
