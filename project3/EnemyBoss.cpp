/*******************************************************************************
 * @file        EnemyBoss.cpp
 * @author      kcbryant
 * @description An boss enemy.
 ******************************************************************************/

#include "EnemyBoss.h"

/**
 * Creates a new enemy object instance with speed and health set
 * @param health The enemies initial health.
 * @param speed The enemies speed.
 * @param killCredits The value the player gains for killing this enemy.
 */
EnemyBoss::EnemyBoss(int health, float speed, int killCredits)
	: Enemy("boss", health, speed, killCredits)
{

}