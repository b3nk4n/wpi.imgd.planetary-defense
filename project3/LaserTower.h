/*******************************************************************************
 * @file        LaserTower.h
 * @author      bsautermeister
 * @description The laser tower, which fires some fly through lasers.
 ******************************************************************************/

#ifndef __LASER_TOWER_H__
#define __LASER_TOWER_H__

#include "Tower.h"

#define TOWER_LASER "Laser Tower"
#define KEY_LASER '4'
#define INIT_PRICE_LASER 300
#define INIT_ENERGY_LASER -5

/*
* Represents a laser tower with splash damage.
*/
class LaserTower : public Tower
{
public:
 	/**
 	 * Creates a new laser tower object.
 	 */
 	LaserTower(void);

 	/**
 	 * Fires a laser at the enemy object.
	 * @param p_object The enemy object. 
	 */
	virtual void fire(Object *p_object);
};

#endif