/*******************************************************************************
 * @file        EnemyGoblin.h
 * @author      kcbryant
 * @description An goblin enemy.
 ******************************************************************************/
#ifndef __ENEMY_GOBLIN_H__
#define __ENEMY_GOBLIN_H__

#include "Enemy.h"

#define ENEMY_NAME_GOBLIN "Space Goblin"

/*
* Represents an ork enemy.
*/
class EnemyGoblin : public Enemy
{
public:
	/**
	 * Creates a new ork enemy object instance.
	 */
	EnemyGoblin(void);
};

#endif


