/*******************************************************************************
 * @file        EnemyOrk.cpp
 * @author      kcbryant
 * @description An ork enemy.
 ******************************************************************************/

#include "EnemyOrk.h"

/**
 * Creates a new enemy object instance with speed and health set
 * @param health The enemies initial health.
 * @param speed The enemies speed.
 * @param killCredits The value the player gains for killing this enemy.
 */
EnemyOrk::EnemyOrk(int health, float speed, int killCredits)
	: Enemy("ork", health, speed, killCredits)
{

}