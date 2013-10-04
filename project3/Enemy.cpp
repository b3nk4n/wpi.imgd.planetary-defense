/*******************************************************************************
 * @file        Enemy.cpp
 * @author      kcbryant
 * @description Enemy Base Class Functions
 * @lastEdit 	10/3/2013
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
 * @param int enemyIndex
 */
Enemy::Enemy(int enemyIndex)
{	
	LogManager &log_manager = LogManager::getInstance();
  	ResourceManager &resource_manager = ResourceManager::getInstance();
  	Sprite *p_temp_sprite = resource_manager.getSprite("saucer"); // eventually getType();

    setSprite(p_temp_sprite);
    setSpriteSlowdown(4);		
  	
	_pathIndex = 0;
	MapObject* mapObject = MapObject::Instance();
	_currentWaypoint = mapObject->getPathPosition(_pathIndex);

	setEnemy(enemyIndex);
	setPosition(_currentWaypoint);

	// register for events
	registerInterest(STEP_EVENT);
}


/**
 * Handle events
 * @return int 1 if event was handled, else 0
 */
int Enemy::eventHandler(Event *p_e)
{

  if (p_e->getType() == STEP_EVENT)
  {
  	LogManager &logManager = LogManager::getInstance();
  	logManager.writeLog(LOG_DEBUG,
		"Enemy::eventHandler()",
		"pos: x=%d, y=%d | currentWaypoint: x=%d, y=%d\n",
		getPosition().getX(),
		getPosition().getY(),
		_currentWaypoint.getX(),
		_currentWaypoint.getY());

  		move();
	}
  //ignore this event
  return 0;
}

/**
 * Move to next waypoint
 */
void Enemy::move()
{	
	// check target reached
	if (this->getPosition() == _currentWaypoint){
		nextTarget();
	}
}

/**
 * Changes the target to the next path position.
 * @return Returns 0 if ok and -1 if there is no target left.
 */
int Enemy::nextTarget(void)
{
	MapObject* mapObject = MapObject::Instance();

	++_pathIndex;
	
	// verify target reached
	if (_pathIndex == mapObject->getPathPositionsCount())
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
		return -1;
	}

	_currentWaypoint = mapObject->getPathPosition(_pathIndex);

	// adjust velocity/direction
	int currentX = getPosition().getX();
	int currentY = getPosition().getY();
	int nextX = _currentWaypoint.getX();
	int nextY = _currentWaypoint.getY();

	if (nextY > currentY){
		setVelocityY(_speed);
		setVelocityX(0);
	}
	else if (nextY < currentY){
		setVelocityY(-_speed);
		setVelocityX(0);
	}
	else if (nextX > currentX){
		setVelocityX(_speed);
		setVelocityY(0);
	}
	else {
		setVelocityX(-_speed);
		setVelocityX(0);
	}

	return 0;
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
void Enemy::setEnemy(int enemyIndex)
{	
	// ORK BOSS 1
	if (enemyIndex == ORK_BOSS){
		setType("Ork Boss");
		_speed = 0.25;
		_health = 500;

	}

	// ORK 2
	if (enemyIndex == ORK){
		setType("Ork");
		_speed = 0.5;
		_health = 50;
	}

	// GOBLIN 3
 	if (enemyIndex == GOBLIN){
 		setType("Goblin");
		_speed = 1.0;
		_health = 10;
	}
}
