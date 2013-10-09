/*******************************************************************************
 * @file        TeslaTower.h
 * @author      bsautermeister
 * @description The tesla tower, which fires a splash damage shock.
 ******************************************************************************/

#ifndef __TESLA_TOWER_H__
#define __TESLA_TOWER_H__

#include "Tower.h"

#define TOWER_TESLA "tesla"
#define INIT_PRICE_TESLA 450
#define INIT_ENERGY_TESLA 8

/*
* Represents a tesla tower with splash damage.
*/
class TeslaTower : public Tower
{
public:
 	/**
 	 * Creates a new tesla tower object.
 	 */
 	TeslaTower(void);

 	/**
 	 * Fires a tesla at the enemy object.
	 * @param p_object The enemy object. 
	 */
	virtual void fire(Object *p_object);
};

#endif