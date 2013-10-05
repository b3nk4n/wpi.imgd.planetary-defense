/*******************************************************************************
 * @file        LevelData.h
 * @author      bsautermeister
 * @description The level data holding the information of a level with many
 *              waves and different enemies and bosses.
 ******************************************************************************/

#include <string>
#include "LevelData.h"
#include "LogManager.h"

/**
 * Creates a wave data instance.
 * @note Hidden because the number of waves must be specified.
 */
LevelData::LevelData(void)
{
}

/**
 * Creates a new level data instance.
 * @param wavesCapacity The requested number of waves.
 */
LevelData::LevelData(int wavesCapacity)
{
	_wavesCount = 0;
	_label = UNKNOWN_LEVEL;
	_wavesCapacity = wavesCapacity;
	_p_waves = new WaveData[wavesCapacity];
}

/**
 * Adds a wave to the leve.
 * @param wave The wave to add.
 * @return Returns 0 for success, else -1.
 */
int LevelData::addWave(WaveData wave)
{
	if (_wavesCount == _wavesCapacity)
	{
		LogManager &logManager = LogManager::getInstance();
		logManager.writeLog(LOG_ERROR,
			"LevelData::addWave()",
			"Waves list out of capacity\n");
		return -1;;
	}

	_p_waves[_wavesCount] = wave;
	++_wavesCount;
	return 0;
}

/**
 * Gets a wave data at a specified index.
 * @param index The wave index.
 * @return The requested wave or an empty wave, if index out of bounds.
 */
WaveData LevelData::getWave(int index)
{
	if (index < 0 || index >= _wavesCount)
	{
		LogManager &logManager = LogManager::getInstance();
		logManager.writeLog(LOG_ERROR,
			"LevelData::getWave()",
			"Index out of bounds: %d\n",
			index);
		return WaveData();
	}

	return _p_waves[index];
}

/**
 * Gets the number of waves.
 * @return The number of waves.
 */
int LevelData::getWavesCount(void)
{
	return _wavesCount;
}

/**
 * Gets the level data label.
 * @return The level data label.
 */
string LevelData::getLabel(void)
{
	return _label;
}

/**
 * Sets the level data label.
 * @param value The level data label.
 */
void LevelData::setLabel(string value)
{
	_label = value;
}
