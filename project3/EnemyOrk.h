/*******************************************************************************
 * @file        EnemyOrk.h
 * @author      kcbryant
 * @description An ork enemy.
 ******************************************************************************/
#ifndef __ENEMY_ORK_H__
#define __ENEMY_ORK_H__

#include "Enemy.h"

/*
* Represents an ork enemy.
*/
class EnemyOrk : public Enemy
{
public:
	/**
	 * Creates a new ork enemy object instance.
	 */
	EnemyOrk(void);
};

#endif

