/*******************************************************************************
* @file        Tower.cpp
* @author      kcbryant
* @description Base class for offensive tower buildings.
******************************************************************************/

#include "Tower.h"
#include "LogManager.h"
#include "worldManager.h"
#include "EventStep.h"
#include "Spawner.h"
#include "Object.h"

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
	_coolDown = _fireRate;

	_p_currentTarget = NULL;

	// register events
	registerInterest(STEP_EVENT);
}

/**
 * Finds the closest enemy to the tower, which is in its range
 * @return The closest enemy in its range or NULL, if no enemy found.
 */
Object* Tower::findTarget(void)
{	
	LogManager &logManager = LogManager::getInstance();
	WorldManager &world_manager = WorldManager::getInstance();

	ObjectList All = world_manager.getAllObjects();
	ObjectListIterator enemyIt = ObjectListIterator(&All);
	Object* enemy_best = NULL;
	for (enemyIt.first();!enemyIt.isDone();enemyIt.next())
	{	
		Object* curObj = enemyIt.currentObject();
		if (curObj->getType() == TYPE_ENEMY &&
			isInRange(curObj) &&
			(enemy_best == NULL || distanceTo(curObj) < distanceTo(enemy_best)))
		{
			enemy_best = curObj;
		}
	}

	return enemy_best;
}

/**
 * Checks whether the enemy is in the towers range.
 * @param enemy The enemy to check if it is in range.
 * @return Returns TRUE, if in range, else FALSE.
 */
bool Tower::isInRange(Object *enemy)
{	
	// verify enemy not NULL
	if (!enemy)
		return false;

	return distanceTo(enemy) <= getFireRange();
}

/**
 * Gets the distance to the tower
 * @param enemy The enemy to check the distance.
 * @return The distance to the tower or a high int if enemy is NULL.
 */
float Tower::distanceTo(Object *enemy)
{	
	// verify enemy not NULL
	if (!enemy)
		return 99999;

	return distance(this->getPosition(), enemy->getPosition());
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
	LogManager &logManager = LogManager::getInstance();

	if (p_event->getType() == STEP_EVENT)
	{	
		_coolDown--;
		if (_coolDown <= 0)
		{
			if (!isInRange(_p_currentTarget))
				_p_currentTarget = findTarget();
			
			if (_p_currentTarget != NULL)
			{
				logManager.writeLog(
		            LOG_DEBUG,
		            "Tower::eventHandler()",
		            "Tower is fireing to enemy!\n");
				fire(_p_currentTarget);
				_coolDown = _fireRate;
			}
		}
  		
  		return 1;
	}

	return 0;
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
