/*******************************************************************************
 * @file        EnemyOrk.h
 * @author      kcbryant
 * @description An ork enemy.
 ******************************************************************************/
#ifndef __ENEMY_ORK_H__
#define __ENEMY_ORK_H__

#include "Enemy.h"

#define ENEMY_NAME_ORK "Space Ork"

/*
* Represents an ork enemy.
*/
class EnemyOrk : public Enemy
{
public:
	/**
	 * Creates a new enemy object instance with speed and health set
	 * @param health The enemies initial health.
	 * @param speed The enemies speed.
	 * @param killCredits The value the player gains for killing this enemy.
	 */
	EnemyOrk(int health, float speed, int killCredits);
};

#endif

