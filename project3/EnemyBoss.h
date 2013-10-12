/*******************************************************************************
 * @file        EnemyBoss.h
 * @author      kcbryant
 * @description An boss enemy.
 ******************************************************************************/
#ifndef __ENEMY_BOSS_H__
#define __ENEMY_BOSS_H__

#include "Enemy.h"

#define ENEMY_NAME_BOSS "Space Boss"

/*
* Represents a Boss enemy.
*/
class EnemyBoss : public Enemy
{
public:
	/**
	 * Creates a new enemy object instance with speed and health set
	 * @param health The enemies initial health.
	 * @param speed The enemies speed.
	 * @param killCredits The value the player gains for killing this enemy.
	 */
	EnemyBoss(int health, float speed, int killCredits);
};

#endif

