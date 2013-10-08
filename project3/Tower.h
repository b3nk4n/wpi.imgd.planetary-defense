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

 	/**
 	 * The current enemy target, so the tower can follow that one as
 	 * long as it is in its range.
 	 */
 	Object *_p_currentTarget;

 	/**
	 * Checks whether the enemy is in the towers range.
	 * @param enemy The enemy to check if it is in range.
	 * @return Returns TRUE, if in range, else FALSE.
	 */
	bool isInRange(Object *enemy);

	/**
	 * Gets the distance to the tower
	 * @param enemy The enemy to check the distance.
	 * @return The distance to the tower or a high int if enemy is NULL.
	 */
	float distanceTo(Object *enemy);

	/**
	 * Faces the object to a given object.
	 * @param p_object The object to face to.
	 */
	void faceTo(Object *p_object);

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

 	/**
 	 * Fires a projectile at the enemy object.
	 * @param p_object The enemy object. 
	 */
	virtual void fire(Object *p_object) = 0;

	/**
	 * Finds the closest enemy to the tower, which is in its range
	 * @return The closest enemy in its range or NULL, if no enemy found.
	 */
	Object* findTarget(void);

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
