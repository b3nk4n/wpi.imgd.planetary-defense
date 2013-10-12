/*******************************************************************************
 * @file        EnemyGoblin.cpp
 * @author      kcbryant
 * @description An goblin enemy.
 ******************************************************************************/

#include "EnemyGoblin.h"

/**
 * Creates a new enemy object instance with speed and health set
 * @param health The enemies initial health.
 * @param speed The enemies speed.
 * @param killCredits The value the player gains for killing this enemy.
 */
EnemyGoblin::EnemyGoblin(int health, float speed, int killCredits)
	: Enemy("goblin", health, speed, killCredits)
{

}