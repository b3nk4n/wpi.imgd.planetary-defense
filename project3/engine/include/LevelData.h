/*******************************************************************************
 * @file        LevelData.h
 * @author      bsautermeister
 * @description The level data holding the information of a level with many
 *              waves and different enemies and bosses.
 ******************************************************************************/

#ifndef __LEVEL_DATA_H__
#define __LEVEL_DATA_H__

#include <string>
#include "WaveData.h"

using std::string;

#define UNKNOWN_LEVEL "unknown_level"

/**
 * Represents a level by holding all its information.
 */
class LevelData
{
private:
	/**
	 * The text label to identify the mapdata.
	 */
	string _label;

	/**
	 * The array of waves.
	 */
	WaveData *_p_waves;

	/**
	 * The real number of waves
	 */
	int _wavesCount;

	/**
	 * The waves capacity.
	 */
	int _wavesCapacity;

	/**
	 * Creates a wave data instance.
	 * @note Hidden because the number of waves must be specified.
	 */
	LevelData(void);

public:

	/**
	 * Creates a new level data instance.
	 * @param wavesCapacity The requested number of waves.
	 */
	LevelData(int wavesCapacity);

	/**
	 * Adds a wave to the leve.
	 * @param wave The wave to add.
	 * @return Returns 0 for success, else -1.
	 */
	int addWave(WaveData wave);

	/**
	 * Gets a wave data at a specified index.
	 * @param index The wave index.
	 * @return The requested wave or an empty wave, if index out of bounds.
	 */
	WaveData getWave(int index);

	/**
	 * Gets the number of waves.
	 * @return The number of waves.
	 */
	int getWavesCount(void);

	/**
	 * Gets the level data label.
	 * @return The level data label.
	 */
	string getLabel(void);

	/**
	 * Sets the level data label.
	 * @param value The level data label.
	 */
	void setLabel(string value);
};

#endif
