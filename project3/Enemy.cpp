/*******************************************************************************
 * @file        Enemy.cpp
 * @author      kcbryant
 * @description Enemy Base Class Functions
 * @lastEdit 	10/3/2013
 ******************************************************************************/

 #include "Enemy.h"

/**
 * Creates a new enemy object instance with speed and health set
 * @param int health
 * @param int speedIndex
 */
Enemy::Enemy(int health, int speedIndex)
{
	_speedIndex = speedIndex;
	_health = health;
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
 * Gets the speed index of the Enemy.
 * @return speed index of the enemy.
 */
int Enemy::getSpeed(void)
{
	return _speedIndex;
}

/**
 * Set the speed index of the Enemy.
 * @param int speed you want the enemy to go.
 */
int Enemy::setSpeed(int speedIndex)
{
	_speedIndex = speedIndex;
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