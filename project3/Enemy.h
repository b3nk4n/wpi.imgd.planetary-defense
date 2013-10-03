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
 #include "Position.h"

//Possible Enemies
#define ORK_BOSS 1
#define ORK 2
#define GOBLIN 3

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
 	 * Type of enemy
 	 */
 	int _enemyIndex;

 	/**
 	 * Speed of the enemy
 	 */
 	float _speed;

 	/**
 	 * Waypoint for enemy to approach
 	 */
 	Position _currentWaypoint;

 	/**
 	 * Position index
 	 */
 	int _pathIndex

 public:
	/**
	 * Creates a new enemy object with a certain type of enemy
	 * @param int enemy index
	 */
	Enemy(int enemyIndex);

	/**
	 * Cleans up the enemy object.
	 */
	virtual ~Enemy(void);

	/**
	 * Handle events
	 * @return int 1 if event was handled, else 0
	 */
	int eventHandler(Event *p_e);
	 
	/**
	 * Move to next waypoint
	 */
	void move();

	/** 
	 * Gets the speed index of the Enemy.
	 * @return float speed of the enemy.
	 */
	float getSpeed(void);

	/**
	 * Set the speed index of the Enemy.
	 * @param float speed you want the enemy to go.
	 */
	void setSpeed(float speed);

	/**
	 * Gets the current health of the Enemy.
	 * @return int the health of the enemy.
	 */
	int getHealth(void);

	/**
	 * Set the health of the Enemy.
	 * @param int health you want the enemy to have.
	 */
	void setHealth(int health);

	/**
	 * Sets up the enemy based on enemyIndex
	 * @param int enemyIndex
	 * NOTE: Library for enemies,
	 * You can add more enemies here
	 */
	void setEnemy(int enemyIndex);

};

#endif // __ENEMY_H__
