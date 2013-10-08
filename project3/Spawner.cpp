/*******************************************************************************
 * @file        Spawner.cpp
 * @author      Kcbryant
 * @description Manages all enemies and their spawn times
 ******************************************************************************/

#include <string>
#include "ObjectList.h"
#include "Position.h"
#include "Enemy.h"
#include "Spawner.h"
#include "EnemyOrk.h"
#include "EnemyGoblin.h"
#include "EventStep.h"
#include "EventEnemyKilled.h"
#include "EventEnemyInvasion.h"
#include "Event.h"
#include "EventView.h"
#include "LevelData.h"
#include "WaveData.h"
#include "ResourceManager.h"
#include "WorldManager.h"

Spawner* Spawner::s_Instance = NULL;  // Global static pointer used to ensure a single instance of the class.


Spawner* Spawner::Instance()
{
   if (!s_Instance)   // Only allow one instance of class to be generated.
      s_Instance = new Spawner;

   return s_Instance;
}

Spawner::Spawner()
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	_data = resourceManager.getLevel("level1");
	_activeEnemies = 0;
	_waveCounter = 0;
	_enemyList = new ObjectList;
	_currentWave = _data->getWave(_waveCounter); 
	_waves = _data->getWavesCount();
	_waveType = _currentWave.getType();
	_enemyCounter = _currentWave.getCount();
	_delay = _currentWave.getDelay();
	_coolDown = 10000;
	registerInterest(STEP_EVENT);
	registerInterest(ENEMY_KILLED_EVENT);
	registerInterest(ENEMY_INVASION_EVENT);
	//spawnEnemy();
}

void Spawner::removeEnemy(Enemy *enemy)
{
	_enemyList->remove(enemy);
}

ObjectList* Spawner::getEnemies(void)
{
	return _enemyList;
}

void Spawner::spawnEnemy()
{	_activeEnemies++;

	Enemy* yo;
	if (_waveType == "ork")
	{
		yo = new EnemyOrk();
	}
	else if (_waveType == "goblin")
	{
		yo = new EnemyGoblin();
	}

	_enemyList->insert(yo);
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
			_coolDown = 2000;

		}
		else if (_enemyCounter <= 0)
		{				

			if (_waveCounter < _waves)
			{
				++_waveCounter;
				_currentWave = _data->getWave(_waveCounter);
				_enemyCounter = _currentWave.getCount();
				_delay = _currentWave.getDelay();
				_waveType = _currentWave.getType();
				_coolDown = 10000;
			}
		}

		_coolDown = _coolDown - _delay;
		return 1;
	}
	if (p_event->getType() == ENEMY_KILLED_EVENT || p_event->getType() == ENEMY_INVASION_EVENT)
	{
  		--_activeEnemies;
  		return 1;
	}

  return 0;
}