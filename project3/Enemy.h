/*******************************************************************************
 * @file        Enemy.h
 * @author      kcbryant
 * @description Base Class for Enemies
 * @lastEdit 	10/3/2013
 ******************************************************************************/
 #ifndef __ENEMY_H__
 #define __ENEMY_H__

//Engine Includes
 #include "Object.h"



/*
* Base Class for all enemy units
*/
 class Enemy : public Object
 {
 private:
 	/**
 	 * Amount of health the enemy has
 	 */
 	int _health;

 	/**
 	 * Speed of the enemy
 	 * 1 for slow, 2 for average, 3 for fast
 	 */
 	int _speedIndex;

 	/**
 	 * cell that the enemy is on
 	 */
 	// Cell _currentCell;

 	/**
 	 * Last cell the enemy was on
 	 */
 	// Cell _lastCell



 public:
	/**
	 * Creates a new enemy object instance with speed and health set
	 * @param int health
	 * @param int speedIndex
	 */
	Enemy(int health, int speedIndex);


	/**
	 * Cleans up the enemy object.
	 */
	virtual ~Enemy(void);

	/**
	 * Gets the speed index of the Enemy.
	 * @return speed index of the enemy.
	 */
	int getSpeed(void);

	/**
	 * Set the speed index of the Enemy.
	 * @param int speed you want the enemy to go.
	 */
	int setSpeed(int speedIndex);

	/**
	 * Gets the current health of the Enemy.
	 * @return the health of the enemy.
	 */
	int getHealth(void);

	/**
	 * Set the health of the Enemy.
	 * @param int health you want the enemy to have.
	 */
	int setHealth(int health);

	/**
	 * Move the enemy to the next open path cell
	 */
	 void move(void);

	 /**
	  * Check cells around the enemy for possible move
	  * @return Cell that is next in path
	  */
	//cell checkCells(cell current);


};

#endif // __ENEMY_H__
