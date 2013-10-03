/*******************************************************************************
 * @file        Enemy.cpp
 * @author      kcbryant
 * @description Enemy Base Class Functions
 * @lastEdit 	10/3/2013
 ******************************************************************************/

 #include "Enemy.h"

/**
 * Creates a new enemy object instance with speed and health set
 * @param int enemyIndex
 */
Enemy::Enemy(int enemyIndex)
{
	setEnemy(enemyIndex);
}

/**
 * Cleans up the enemy object.
 */
virtual Enemy::~Enemy(void)
{
	_health = 0;
	_speedIndex = 0;
}

/**
 * Handle events
 * @return int 1 if event was handled, else 0
 */
int Enemy::eventHandler(Event *p_e) {

  if (p_e->getType() == STEP_EVENT) {
    if (this.getPosition() == _currentWaypoint){
    		//move(Waypoint.next);
    		return 1;
		}
	}
  //ignore this event
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
 * @return the health of the enemy.
 */
int Enemy::getHealth(void)
{
	return _health;
}

/**
 * Set the speed index of the Enemy.
 * @param int speed you want the enemy to go.
 */
int Enemy::setHealth(int health)
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
