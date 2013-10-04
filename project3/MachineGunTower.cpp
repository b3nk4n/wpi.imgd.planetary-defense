/*******************************************************************************
 * @file        MachineGunTower.cpp
 * @author      bsautermeister
 * @description The machine gun tower, which fires some bullets.
 ******************************************************************************/

#include "MachineGunTower.h"

/**
 * Creates a new machine gun tower object.
 */
MachineGunTower::MachineGunTower(void)
	: Tower(TOWER_MACHINE_GUN, "assets/sprites/machinegun-spr.txt", 150, -3, 30, 2, 5)
{

}
