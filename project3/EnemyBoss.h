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
	 * Creates a new boss enemy object instance.
	 */
	EnemyBoss(void);
};

#endif

