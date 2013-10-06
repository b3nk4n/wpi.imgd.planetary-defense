/*******************************************************************************
 * @file        Tower.h
 * @author      kcbryant
 * @description Base class for offensive tower buildings.
 ******************************************************************************/
#ifndef __TOWER_H__
#define __TOWER_H__

#include "Building.h"
#include "Enemy.h"
#include "Object.h"

/*
* Represents the base for all tower units.
*/
 class Tower : public Building
 {
 private:
 	/**
 	 * Rate at witch the tower shoots
 	 */
 	int _fireRate;

 	/**
 	 * The amount of damage a bullet does 
 	 */
 	int _firePower;

 	/**
 	 * The fire radius around the tower.
 	 */
 	int _fireRange;

 	/**
 	 * Cooldown rate
 	 */
 	int _coolDown;

 public:
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
 	Tower(string name, string spriteName, int cost, int energy,
 		int fireRate, int firePower, int fireRange);

 	/**  PROTOTYPE
 	 * Shoots a bullet at the enemy
	 * @param string, type of bullet it shoots
	 */
	void shoot(string type);

	/** PROTOTYPE
	 * Finds the closest enemy to the tower
	 * @return Enemy, the target enemy
	 */
	Object* findTarget();

	/**
 	 * gives a closeness value
 	 * @param Enemy, that you are deciding whether or not to target
 	 * @return int, closeness value of enemy
 	 */
	int isClose(Object *enemy);

 	/**
 	 * Cleans the tower object.
 	 */
 	virtual ~Tower(void);

 	/**
	 * Handle the tower events, like selecting the appropriate frame index,
	 * seeking or attacking enemies.
	 * @return Returns 1 if event was handled, else 0.
	 */
	virtual int eventHandler(Event *p_event);
	
	/**
	 * Gets the fire rate.
	 * @return The fire rate.
	 */
 	int getFireRate(void);

 	/**
 	 * Gets the fire power.
 	 * @return The fire power.
 	 */
 	int getFirePower(void);

 	/**
 	 * Gets the fire range.
 	 * @return The fire range.
 	 */
 	int getFireRange(void);
};

#endif
