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

	// register events
	registerInterest(STEP_EVENT);
}

/**
 * Finds the closest enemy to the tower, which is in its range
 * @return The closest enemy in its range or NULL, if no enemy found.
 */
Object* Tower::findTarget(void)
{	

	 // TODO: use worldManager::solidObjects/allObjects and filter
	                                   //       for the enemies (getType() == TYPE_ENEMY) 
									   //       --> spawner not needed here!
									   //  WARNING: causes sometimes SEG FAULTS...
	LogManager &logManager = LogManager::getInstance();
	WorldManager &world_manager = WorldManager::getInstance();
	ObjectList All = world_manager.getAllObjects();
	ObjectListIterator enemyIt = ObjectListIterator(&All);
	Object* enemy_best = NULL;
	for (enemyIt.first();!enemyIt.isDone();enemyIt.next())
	{	
		Object* curObj = enemyIt.currentObject();
		if (curObj->getType() == TYPE_ENEMY && ((enemy_best == NULL) || (isClose(curObj) < isClose(enemy_best))))
		{
			logManager.writeLog(
		            LOG_DEBUG,
		            "Tower::findTarget()",
		            "#1!\n");
			enemy_best = enemyIt.currentObject();
		}
	}
	logManager.writeLog(
        LOG_DEBUG,
        "Tower::findTarget()",
        "#2!\n");

	return enemy_best;
}

/**
 * gives a closeness value
 * @param Enemy, that you are deciding whether or not to target
 * @return int, closeness value of enemy
 */
int Tower::isClose(Object *enemy)
{	
	return distance(this->getPosition(), enemy->getPosition()) <= getFireRange();
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
			Object *p_target = findTarget(); // TODO: store the last found target, check if the last found
	                                         //       is still close enough and fire the that one
			
			if (p_target != NULL)
			{
				logManager.writeLog(
		            LOG_DEBUG,
		            "Tower::eventHandler()",
		            "Tower is fireing to enemy!\n");
				fire(p_target);
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
