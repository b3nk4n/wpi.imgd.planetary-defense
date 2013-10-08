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

class Spawner : public Object
{

private:
	Spawner(void);  // Private so that it can  not be called
    Spawner(Spawner const&){};             // copy constructor is private
    Spawner& operator=(Spawner const&){};  // assignment operator is private
    static Spawner* s_Instance;

	int _activeEnemies;

	int _waves;

	int _enemyCounter;

	int _waveCounter;

	int _delay;

	int _coolDown;

	ObjectList *_enemyList;

	Position *_position;

	LevelData *_data;

	WaveData _currentWave;

public:
	static Spawner* Instance(); //create a singleton instance of the WorldManager

	void spawnEnemy();

	ObjectList* getEnemies(void); //gets list of active enemies

	//void startWave(Wavedata data);

	//Handle enemy killed event -> activecounter-- --> EventWaveOver-> captured by mapObject();
	int eventHandler(Event *p_event);

	void removeEnemy(Enemy *enemy);

};

#endif // __SPAWNER_H__



