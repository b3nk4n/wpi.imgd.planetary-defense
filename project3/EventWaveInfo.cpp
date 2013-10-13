/*******************************************************************************
 * @file        EventWaveInfo.cpp
 * @author      bsautermeister
 * @description Wave info event, which is fired for a new wave.
 ******************************************************************************/

#include "EventWaveInfo.h"

/**
 * Creates a new wave info event instance withd default data.
 */
EventWaveInfo::EventWaveInfo(void)
{
	setType(WAVE_INFO_EVENT);
	_totalWaves = 0;
	_currentWave = 0;
	_count = 0;
	_name = "";
	_cooldown = 0;
}

/**
 * Creates a new wave info event instance.
 * @param total The total waves.
 * @param current The current wave number.
 * @param count The number of enemies.
 * @param name The enemy type.
 * @param cooldown The cooldown time.
 */
EventWaveInfo::EventWaveInfo(int total, int current, int count, string name, int cooldown)
{
	setType(WAVE_INFO_EVENT);
	_totalWaves = total;
	_currentWave = current;
	_count = count;
	_name = name;
	_cooldown = cooldown;
}

/**
 * Gets the total waves.
 * @return Total waves.
 */
int EventWaveInfo::getTotalWaves(void)
{
	return _totalWaves;
}

/**
 * Gets the curent wave number.
 * @return Current wave number.
 */
int EventWaveInfo::getCurrentWave(void)
{
	return _currentWave;
}

/**
 * Gets the enemies count.
 * @return The enemies count.
 */
int EventWaveInfo::getCount(void)
{
	return _count;
}

/**
 * Gets the enemy type name.
 * @return The enemy name.
 */
string EventWaveInfo::getName()
{
	return _name;
}

/**
 * Gets the cooldown time.
 * @return The cooldown time.
 */
int EventWaveInfo::getCooldown(void)
{
	return _cooldown;
}

