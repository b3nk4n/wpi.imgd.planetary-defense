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
	 * Creates a new enemy object instance with speed and health set
	 * @param health The enemies initial health.
	 * @param speed The enemies speed.
	 * @param killCredits The value the player gains for killing this enemy.
	 */
	EnemyGoblin(int health, float speed, int killCredits);
};

#endif


