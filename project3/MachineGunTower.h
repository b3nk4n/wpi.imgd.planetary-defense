/*******************************************************************************
 * @file        MachineGunTower.h
 * @author      bsautermeister
 * @description The machine gun tower, which fires some bullets.
 ******************************************************************************/

#ifndef __MACHINE_GUN_TOWER_H__
#define __MACHINE_GUN_TOWER_H__

#include "Tower.h"

#define TOWER_MACHINE_GUN "machine_gun"
#define INIT_PRICE_MACHINE_GUN 150

/*
* Represents a solar panel to get energy.
*/
class MachineGunTower : public Tower
{
public:
 	/**
 	 * Creates a new machine gun tower object.
 	 */
 	MachineGunTower(void);
};

#endif