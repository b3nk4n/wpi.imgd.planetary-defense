/*******************************************************************************
 * @file        Spawner.h
 * @author      bsautermeister, Kcbryant
 * @description Manages the map and the cursor. Also, it is implemented as a
 *              singleton, so e.g. enemies can get map information using this
 *              manager class.
 ******************************************************************************/



public:

	void spawnEnemy(void);

	void startWave(Wavedata data);

	//Handle enemy killed event -> activecounter-- --> EventWaveOver-> captured by mapObject();
	void eventHandler(Event *p_e);

	 


private:

	int _activeEnemies

	int _counter;

	Position _position



