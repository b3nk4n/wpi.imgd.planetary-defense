/*******************************************************************************
 * @file        WaveData.cpp
 * @author      bsautermeister
 * @description The wave data holding the information of one wave.
 ******************************************************************************/

#include "WaveData.h"

/**
 * Creates a wave data instance.
 */
WaveData::WaveData(void)
{
	_type = ENEMY_TYPE_UNKNOWN;
	_count = 0;
	_delay = 0;
}

/**
 * Creates a new wave data instance.
 * @param type The type of the enemy.
 * @param count The number of enemies to spawn.
 * @param delay The delay between enemies.
 */
WaveData::WaveData(string type, int count, int delay)
{
	_type = type;
	_count = count;
	_delay = delay;
}

/**
 * Gets the enemy type.
 * @return The enemy type.
 */
string WaveData::getType(void)
{
	return _type;
}

/**
 * Gets the number of enemies to spawn.
 * @return The number of enemies.
 */
int WaveData::getCount(void)
{
	return _count;
}

/**
 * Gets delay between the enemies.
 * @return The delay between enemies.
 */
int WaveData::getDelay(void)
{
	return _delay;
}
