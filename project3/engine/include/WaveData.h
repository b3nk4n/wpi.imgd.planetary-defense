/*******************************************************************************
 * @file        WaveData.h
 * @author      bsautermeister
 * @description The wave data holding the information of one wave.
 ******************************************************************************/

#ifndef __WAVE_DATA_H__
#define __WAVE_DATA_H__

#include <string>

using std::string;

#define ENEMY_TYPE_UNKNOWN "unknown_enemy_type"
#define ENEMY_TYPE_ORK "ork"
#define ENEMY_TYPE_GOBLIN "goblin"

/**
 * Represents a wave by holding all their information.
 */
class WaveData
{
private:
	/**
	 * The type of the enemy.
	 */
	string _type;

	/**
	 * The number of enemyies to spawn in this wave.
	 */
	int _count;
	/**
	 * The delay betweeen the enemies in steps.
	 */
	int _delay;

public:
	/**
	 * Creates a wave data instance.
	 */
	WaveData(void);

	/**
	 * Creates a new wave data instance.
	 * @param type The type of the enemy.
	 * @param count The number of enemies to spawn.
	 * @param delay The delay between enemies.
	 */
	WaveData(string type, int count, int delay);

	/**
	 * Gets the enemy type.
	 * @return The enemy type.
	 */
	string getType(void);

	/**
	 * Gets the number of enemies to spawn.
	 * @return The number of enemies.
	 */
	int getCount(void);

	/**
	 * Gets delay between the enemies.
	 * @return The delay between enemies.
	 */
	int getDelay(void);
};

#endif
