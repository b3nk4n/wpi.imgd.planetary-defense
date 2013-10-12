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
	_health = 0;
	_speed = 0.0f;
	_credits = 0;
}

/**
 * Creates a new wave data instance.
 * @param type The type of the enemy.
 * @param count The number of enemies to spawn.
 * @param delay The delay between enemies.
 * @param health The HP.
 * @param speed The speed.
 * @param credits The kill credits.
 */
WaveData::WaveData(string type, int count, int delay, int health, float speed, int credits)
{
	_type = type;
	_count = count;
	_delay = delay;
	_health = health;
	_speed = speed;
	_credits = credits;
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

/**
 * Gets the HP.
 * @return The HP.
 */
int WaveData::getHealth(void)
{
	return _health;
}

/**
 * Gets the speed.
 * @return The speed.
 */
float WaveData::getSpeed(void)
{
	return _speed;
}

/**
 * Gets the credits.
 * @return The credits.
 */
int WaveData::getCredits(void)
{
	return _credits;
}
