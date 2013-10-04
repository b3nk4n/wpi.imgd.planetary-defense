/*******************************************************************************
 * @file        Enemy.h
 * @author      kcbryant
 * @description Base class for Enemies
 ******************************************************************************/
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Object.h"
#include "Position.h"

#define TYPE_ENEMY "enemy"

/*
* Base Class for all enemy units
*/
class Enemy : public Object
{
 private:
 	/**
 	 * Amount of health the enemy has.
 	 */
 	int _health;

 	/**
 	 * Speed of the enemy.
 	 */
 	float _speed;

 	/**
 	 * Target for enemy to approach.
 	 */
 	Position _currentTarget;

 	/**
 	 * Path position index.
 	 */
 	int _pathIndex;

 public:
	/**
	 * Creates a new enemy object instance with speed and health set
	 * @param spriteName The name of the sprite asset.
	 * @param health The enemies initial health.
	 * @param speed The enemies speed.
	 */
	Enemy(string spriteName, int health, float speed);

	/**
	 * Cleans up the enemy object.
	 */
	virtual ~Enemy(void);

	/**
	 * Handle events
	 * @param p_event The event.
	 * @return Returns 1 if event was handled, else 0.
	 */
	virtual int eventHandler(Event *p_event);
	 
	/**
	 * Move to next waypoint
	 */
	void move(void);

	/**
	 * Changes the target to the next path position.
	 * @return Returns 0 if ok and -1 if there is no target left.
	 */
	int nextTarget(void);

	/**
	 * Gets the current target position.
	 * @return The current target position.
	 */
	Position getCurrentTarget(void);

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
};

#endif
