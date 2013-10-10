/*******************************************************************************
 * @file        Spawner.h
 * @author      Kcbryant
 * @description Manages all enemies and their spawn times
 ******************************************************************************/
#ifndef __SPAWNER_H__
#define __SPAWNER_H__

#include "ObjectList.h"
#include "Position.h"
#include "Enemy.h"
#include "LevelData.h"
#include "WaveData.h"
#include "Object.h"
#include <string>

class Spawner : public Object
{

private:
    /**
     * Number of active enemies
     */
	int _activeEnemies;

	/**
	 * Number of waves this level
	 */
	int _waves;

	/**
	 * Number of enemies this wave
	 */
	int _enemyCounter;

	/**
	 * Counter for number of waves in a level
	 */
	int _waveCounter;

	/**
	 * Type of wave
	 */
	string _waveType;

	/**
	 * Amount of time between enemy spawns
	 */
	int _delay;

	/**
	 * Counter for pause between waves
	 */
	int _coolDown;

	/**
	 * Information about the current level
	 */
	LevelData *_data;

	/**
	 * Information about the current wave
	 */
	WaveData _currentWave;

public:

	/**
	 * Creates a new instance of spawner
	 */
	Spawner(void);  // Private so that it can  not be called

	/**
	 * Starts spawing with the given level data.
	 * @param level The level data.
	 */
	void start(LevelData *level);

	/**
	 * Spawns an enemy
	 */
	void spawnEnemy();

	/**
	 * Handles events
	 * @param Event, event type
	 * @return Returns 1 if event was handled, else 0.
	 */
	int eventHandler(Event *p_event);


};

#endif // __SPAWNER_H__



