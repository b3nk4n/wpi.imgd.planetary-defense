/*******************************************************************************
* @file        Tower.cpp
* @author      kcbryant/bsautermeister
* @description Base class for offensive tower buildings.
******************************************************************************/

#include <math.h>
#include "Tower.h"
#include "LogManager.h"
#include "worldManager.h"
#include "EventStep.h"
#include "Spawner.h"
#include "Object.h"
#include "EventPlayerKilled.h"

/**
 * Creates a new tower object.
 * @param name The name.
 * @param spriteName The name of the sprite.
 * @param cost The cost.
 * @param energy The energy cost or value.
 * @param fireRate The fire rate.
 * @param firePower The fire power.
 * @param fireRange The fire range.
 * @param facesToEnemy Whether the tower faces to the enemy
 */
Tower::Tower(string name, string spriteName, int cost, int energy,
	int fireRate, int firePower, int fireRange, bool isFacingToTarget)
	: Building(name, spriteName, cost, energy)
{
	_fireRate = fireRate;
	_firePower = firePower;
	_fireRange = fireRange;
	_coolDown = _fireRate;
	_isFacingToTarget = isFacingToTarget;

	_currentTargetId = INVALID_TARGET_ID;

	// disable sprite animatin when the tower should face to the enemy
	if (_isFacingToTarget)
		setSpriteSlowdown(0);

	// register events
	registerInterest(STEP_EVENT);
	registerInterest(PLAYER_KILLED_EVENT);
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

	if (p_event->getType() == PLAYER_KILLED_EVENT)
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
	}

	if (p_event->getType() == STEP_EVENT)
	{	
		Enemy *p_target = findTargetById(_currentTargetId);

		_coolDown--;
		if (_coolDown <= 0)
		{
			// find new target if it is gone or out of range
			if (p_target == NULL || !isInRange(p_target))
			{
				p_target = findTarget();

				if (p_target != NULL)
					_currentTargetId = p_target->getId();
			}
			
			if (p_target != NULL)
			{
				fire(p_target);
				_coolDown = _fireRate;
			}
		}

		if (isFacingToTarget() &&
			p_target != NULL)
			faceTo(p_target);
  		
  		return 1;
	}

	return 0;
}

/**
 * Finds the closest enemy to the tower, which is in its range
 * @return The closest enemy in its range or NULL, if no enemy found.
 */
Enemy* Tower::findTarget(void)
{	
	WorldManager &world_manager = WorldManager::getInstance();

	ObjectList All = world_manager.getAllObjects();
	ObjectListIterator enemyIt = ObjectListIterator(&All);
	Enemy* enemy_best = NULL;
	for (enemyIt.first();!enemyIt.isDone();enemyIt.next())
	{	
		Object* curObj = enemyIt.currentObject();
		if (curObj->getType() == TYPE_ENEMY &&
			isInRange(curObj) &&
			(enemy_best == NULL || distanceTo(curObj) < distanceTo(enemy_best)))
		{
			Enemy *p_enemy = static_cast<Enemy *>(curObj);
			enemy_best = p_enemy;
		}
	}

	return enemy_best;
}

/**
 * Finds the enemy with the given ID.
 * @return The  enemy with the given ID or NULL, if no enemy found.
 */
Enemy* Tower::findTargetById(int id)
{	
	WorldManager &world_manager = WorldManager::getInstance();

	ObjectList All = world_manager.getAllObjects();
	ObjectListIterator enemyIt = ObjectListIterator(&All);
	for (enemyIt.first();!enemyIt.isDone();enemyIt.next())
	{	
		Object* curObj = enemyIt.currentObject();
		if (curObj->getType() == TYPE_ENEMY)
		{
			Enemy *p_enemy = static_cast<Enemy *>(curObj);
			if (p_enemy->getId() == id)
				return p_enemy;
		}
	}

	// not found
	return NULL;
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
 * Faces the object to a given object.
 * @param p_object The object to face to.
 */
void Tower::faceTo(Object *p_object)
{
	int dx = p_object->getPosition().getX() - getPosition().getX();
	int dy = p_object->getPosition().getY() - getPosition().getY();

	// get angle of the vector.
	// @note: add 45°/2 so that the regions can be caluculated
	int angle = (int)(atan2(dy, dx) * 180 / M_PI + + 360 + 45.0 / 2);
	int index = (angle % 360) / 45;

	setSpriteIndex(index);
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

/**
 * Gets whether the enemy is facing to the target.
 * @return Returns TRUE if the tower is facing to the target, else FALSE.
 */
bool Tower::isFacingToTarget(void)
{
	return _isFacingToTarget;
}
