/*******************************************************************************
 * @file        Spawner.cpp
 * @author      Kcbryant
 * @description Manages all enemies and their spawn times
 ******************************************************************************/

#include "ObjectList.h"
#include "Position.h"
#include "Enemy.h"
#include "Spawner.h"
#include "EnemyOrk.h"
#include "EventStep.h"
#include "EventEnemyKilled.h"
#include "EventEnemyInvasion.h"
#include "Event.h"
#include "EventView.h"
#include "LevelData.h"
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
	_enemyList = new ObjectList;
	//_waves = _data->getWavesCount(); Causes seg fault
	registerInterest(STEP_EVENT);
	registerInterest(ENEMY_KILLED_EVENT);
	registerInterest(ENEMY_INVASION_EVENT);
	spawnEnemy();
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
	Enemy* yo = new EnemyOrk();
	_enemyList->insert(yo);
}

/**
 * Handle events
 * @param p_event The event.
 * @return Returns 1 if event was handled, else 0.
 */
int Spawner::eventHandler(Event *p_event)
{
	if (p_event->getType() == ENEMY_KILLED_EVENT || p_event->getType() == ENEMY_INVASION_EVENT)
	{
  		--_activeEnemies;
  		//_enemyList
  		spawnEnemy();
  		return 1;
	}

  return 0;
}