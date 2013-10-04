/*******************************************************************************
 * @file        Enemy.cpp
 * @author      kcbryant
 * @description Enemy base class Functions
 ******************************************************************************/

#include "EventStep.h"
#include "EventView.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Enemy.h"
#include "MapObject.h"

/**
 * Creates a new enemy object instance with speed and health set
 * @param spriteName The name of the sprite asset.
 * @param health The enemies initial health.
 * @param speed The enemies speed.
 */
Enemy::Enemy(string spriteName, int health, float speed)
{	
	LogManager &logManager = LogManager::getInstance();
  	ResourceManager &resourceManager = ResourceManager::getInstance();

  	setType(TYPE_ENEMY);
  	_health = health;
  	_speed = speed;

  	Sprite *p_tempSprite = resourceManager.getSprite(spriteName);
  	if (!p_tempSprite)
  	{
  		logManager.writeLog(LOG_ERROR,
  			"Enemy::Enemy()",
  			"Loading sprite failed.\n");
  	}
  	else
  	{
  		setSprite(p_tempSprite);
    	setSpriteSlowdown(4);	
  	}

	_pathIndex = 0;
	MapObject* mapObject = MapObject::getInstance();
	_currentTarget = mapObject->getPathPosition(_pathIndex);
	setPosition(_currentTarget);

	// register for events
	registerInterest(STEP_EVENT);
}

/**
 * Cleans up the enemy object.
 */
Enemy::~Enemy(void)
{
}


/**
 * Handle events
 * @return int 1 if event was handled, else 0
 */
int Enemy::eventHandler(Event *p_e)
{
	if (p_e->getType() == STEP_EVENT)
	{
  		move();
  		return 1;
	}

  return 0;
}

/**
 * Move to next waypoint
 */
void Enemy::move(void)
{	
	// check target reached
	if (getPosition() == _currentTarget)
	{
		nextTarget();
	}
}

/**
 * Changes the target to the next path position.
 * @return Returns 0 if ok and -1 if there is no target left.
 */
int Enemy::nextTarget(void)
{
	MapObject* mapObject = MapObject::getInstance();

	++_pathIndex;
	
	// verify target reached
	if (_pathIndex == mapObject->getPathPositionsCount())
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
		return -1;
	}

	_currentTarget = mapObject->getPathPosition(_pathIndex);

	// adjust velocity/direction
	int currentX = getPosition().getX();
	int currentY = getPosition().getY();
	int nextX = _currentTarget.getX();
	int nextY = _currentTarget.getY();

	if (nextY > currentY)
	{
		setVelocityY(_speed);
		setVelocityX(0);
	}
	else if (nextY < currentY)
	{
		setVelocityY(-_speed);
		setVelocityX(0);
	}
	else if (nextX > currentX)
	{
		setVelocityX(_speed);
		setVelocityY(0);
	}
	else
	{
		setVelocityX(-_speed);
		setVelocityX(0);
	}

	return 0;
}

/**
 * Gets the current target position.
 * @return The current target position.
 */
Position Enemy::getCurrentTarget(void)
{
	return _currentTarget;
}

/**
 * Gets the speed index of the Enemy.
 * @return float speed index of the enemy.
 */
float Enemy::getSpeed(void)
{
	return _speed;
}

/**
 * Set the speed index of the Enemy.
 * @param float speed you want the enemy to go.
 */
void Enemy::setSpeed(float speed)
{
	_speed = speed;
}

/**
 * Gets the health of the Enemy.
 * @return int the health of the enemy.
 */
int Enemy::getHealth(void)
{
	return _health;
}

/**
 * Set the health of the enemy
 * @param int health
 */
void Enemy::setHealth(int health)
{
	_health = health;
}

/**
 * Sets up the enemy based on enemyIndex
 * @param int enemyIndex
 * NOTE: Library for enemies,
 * You can add more enemies here
 */
/*void Enemy::setEnemy(int enemyIndex)
{	
	// ORK BOSS 1
	if (enemyIndex == ORK_BOSS)
	{
		setType("Ork Boss");
		_speed = 0.25;
		_health = 500;

	}

	// ORK 2
	if (enemyIndex == ORK)
	{
		setType("Ork");
		_speed = 0.5;
		_health = 50;
	}

	// GOBLIN 3
 	if (enemyIndex == GOBLIN)
 	{
 		setType("Goblin");
		_speed = 1.0;
		_health = 10;
	}
}*/
