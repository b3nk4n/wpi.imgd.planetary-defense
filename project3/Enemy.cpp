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
  	
	_pathIndex = 1;
	MapObject* mapObject = MapObject::Instance();
	setEnemy(enemyIndex);
	_currentWaypoint = mapObject->getPathPosition(_pathIndex);
	_pathIndex++;
	setPosition(_currentWaypoint);
	move();
}


/**
 * Handle events
 * @return int 1 if event was handled, else 0
 */
int Enemy::eventHandler(Event *p_e) {

  if (p_e->getType() == STEP_EVENT) {
    if (this->getPosition() == _currentWaypoint){
    		_pathIndex++;
    		move();
    		return 1;
		}
	}
  //ignore this event
  return 0;
}

/**
 * Move to next waypoint
 */
void Enemy::move()
{	
	MapObject* mapObject = MapObject::Instance();
	int next_x = mapObject->getPathPosition(_pathIndex).getX();
	int next_y = mapObject->getPathPosition(_pathIndex).getY();
	int cur_x = _currentWaypoint.getX();
	int cur_y = _currentWaypoint.getY();
	if (next_y > cur_y){
		setVelocityY(_speed);
		setVelocityX(0);
	}
	else if (next_y < cur_y){
		setVelocityY(-_speed);
		setVelocityX(0);
	}
	else if (next_x > cur_x){
		setVelocityX(_speed);
		setVelocityY(0);
	}
	else {
		setVelocityX(-_speed);
		setVelocityX(0);
	}

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
