/*******************************************************************************
 * @file        Spawner.cpp
 * @author      Kcbryant
 * @description Manages all enemies and their spawn times
 ******************************************************************************/

#include <string>
#include "LogManager.h"
#include "ObjectList.h"
#include "Position.h"
#include "Enemy.h"
#include "Spawner.h"
#include "EnemyOrk.h"
#include "EnemyGoblin.h"
#include "EnemyBoss.h"
#include "EventStep.h"
#include "EventEnemyKilled.h"
#include "EventEnemyInvasion.h"
#include "Event.h"
#include "EventView.h"
#include "LevelData.h"
#include "WaveData.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "EventPlayerKilled.h"
#include "EventPlayerWin.h"
#include "EventWaveInfo.h"
#include "EventSkipTime.h"

/**
 * Creates a new instance of the spawner object
 */
Spawner::Spawner()
{
	_activeEnemies = 0;
	_waveCounter = 0;
	_waves = 0;
	_waveType = ENEMY_TYPE_UNKNOWN;
	_enemyCounter = 0;
	_delay = 0;
	_coolDown = 0;
	_isStopped = false;

	// register events
	registerInterest(STEP_EVENT);
	registerInterest(ENEMY_KILLED_EVENT);
	registerInterest(ENEMY_INVASION_EVENT);
	registerInterest(SKIP_TIME_EVENT);
}

/**
 * Starts spawing with the given level data.
 * @param level The level data.
 */
void Spawner::start(LevelData *level)
{
	_data = level;
	_waves = _data->getWavesCount();
	_isStopped = false;
	_activeEnemies = 0;
	_waveCounter = 0;

	spawnWave(TIME_START_WAVES);
}

/**
 * Stops spawning.
 */
void Spawner::stop(void)
{
	_isStopped = true;
}

/**
 * Spawns a new wave.
 * @param cooldown the wait delay factor.
 */
void Spawner::spawnWave(int cooldown)
{
	_currentWave = _data->getWave(_waveCounter);
	_enemyCounter = _currentWave.getCount();
	_delay = _currentWave.getDelay();
	_waveType = _currentWave.getType();
	_coolDown = cooldown;

	// notify sidebar
	string enemyName;

	if (_waveType == "ork")
		enemyName = ENEMY_NAME_ORK;
	else if (_waveType == "goblin")
		enemyName = ENEMY_NAME_GOBLIN;
	else
		enemyName = ENEMY_NAME_BOSS;

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
		"Spawner::spawnWave()",
		"New wave. type=%s, count=%d, health=%d, speed=%f, credits=%d\n",
		enemyName.c_str(),
		_currentWave.getCount(),
		_currentWave.getHealth(),
		_currentWave.getSpeed(),
		_currentWave.getCredits());

	WorldManager &worldManager = WorldManager::getInstance();

	EventWaveInfo waveEvent(_waves,
		_waveCounter + 1,
		_enemyCounter,
		enemyName,
		_coolDown);
	worldManager.onEvent(&waveEvent);
}

/**
 * Spawns a new enemy
 */
void Spawner::spawnEnemy()
{	
	if (_isStopped)
		return;

	_activeEnemies++;

	if (_waveType == "ork")
	{
		 new EnemyOrk(_currentWave.getHealth(),
		 	_currentWave.getSpeed(),
		 	_currentWave.getCredits());
		
	}
	else if (_waveType == "goblin")
	{
		new EnemyGoblin(_currentWave.getHealth(),
		 	_currentWave.getSpeed(),
		 	_currentWave.getCredits());
		
	}
	else if (_waveType == "boss")
	{
		new EnemyBoss(_currentWave.getHealth(),
		 	_currentWave.getSpeed(),
		 	_currentWave.getCredits());
	}
}

/**
 * Handle events
 * @param p_event The event.
 * @return Returns 1 if event was handled, else 0.
 */
int Spawner::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{	
		if (_coolDown < 0 && _enemyCounter > 0)
		{
			spawnEnemy();
			--_enemyCounter;
			_coolDown = _delay;

		}
		else if (_enemyCounter <= 0 && _coolDown < -30)
		{				

			if (_waveCounter < _waves)
			{
				++_waveCounter;
				if (_waveType == "boss") // longer timer after bosses
					spawnWave(TIME_AFTER_BOSS);
				else
					spawnWave(TIME_BETWEEN_WAVES);
			}
		}

		--_coolDown;

		// check for win
		if (_activeEnemies == 0 && _waveCounter >= _waves)
		{
			WorldManager &worldManager = WorldManager::getInstance();
			EventPlayerWin eventWin;
			worldManager.onEvent(&eventWin);
		}

		return 1;
	}
	else if (p_event->getType() == ENEMY_KILLED_EVENT || p_event->getType() == ENEMY_INVASION_EVENT)
	{
  		--_activeEnemies;
  		return 1;
	}
	else if (p_event->getType() == SKIP_TIME_EVENT)
	{
  		if (_coolDown > 90)
  			_coolDown = 90;
  		return 1;
	}

  return 0;
}