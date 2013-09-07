/*******************************************************************************
 * @file        GameManager.cpp
 * @author      bsautermeister
 * @description The core game management unit, which handles the game loop.
 ******************************************************************************/

#include <stdio.h>
#include "GameManager.h"
#include "ObjectList.h"
#include "LogManager.h"
#include "Clock.h"
#include "WorldManager.h"
#include "EventStep.h"

/**
 * Creates a game manager instance.
 */
GameManager::GameManager(void)
{
	_frameTime = DEFAULT_FRAME_TIME;
	_gameOver = false;
}

/**
 * Hides copy constructor.
 */
GameManager::GameManager(GameManager const &gm)
{
}

/**
 * Hides assignment operator.
 */
void GameManager::operator=(GameManager const &gm)
{
}

/**
 * Cleansup the game manager.
 */
GameManager::~GameManager(void)
{

}

/**
 * Gets the singleton game manager instance.
 * @return The singleton game manager instance.
 */
GameManager& GameManager::getInstance(void)
{
	static GameManager gameManager;
	return gameManager;
}

/**
 * Starts up all game manager services.
 * @return Returns 0 if start up was successfull, else negative.
 */
int GameManager::startUp(void)
{
	return startUp(false);
}

/**
 * Starts up all game manager services.
 * @param flush Configures log file flushing.
 * @return Returns 0 if start up was successfull, else negative.
 */
int GameManager::startUp(bool flush)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	if (logManager.startUp(flush))
	{
		perror("LogManager could not be started");
		return -1;
	}
	else
	{
		logManager.writeLog(LOG_ERROR,
			"GameManager::startUp()",
			"LogManager started\n");
	}

	if (worldManager.startUp())
	{
		logManager.writeLog(LOG_ERROR,
			"GameManager::startUp()",
			"WorldManager could not be started\n");
		return -1;
	}
	else
	{
		logManager.writeLog(LOG_ERROR,
			"GameManager::startUp()",
			"WorldManager started\n");
	}

	_isStarted = true;

	logManager.writeLog(LOG_INFO,
			"GameManager::startUp()",
			"GameManager start up process completed\n");

	return 0;
}

/**
 * Shuts down all game manager services.
 */
void GameManager::shutDown(void)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	logManager.writeLog(LOG_INFO,
			"GameManager::shutDown()",
			"GameManager shut down process started\n");

	logManager.writeLog(LOG_ERROR,
			"GameManager::shutDown()",
			"WorldManager shutting down\n");
	worldManager.shutDown();

	logManager.writeLog(LOG_ERROR,
			"GameManager::shutDown()",
			"LogManager shutting down\n");
	logManager.shutDown();

	_isStarted = false;
}

/**
 * Starts the blocking game loop.
 * @param frameTime The target frame time. Default is DEFAULT_FRAME_TIME.
 * @return The number of game loops updated and rendered.
 */
long int GameManager::run(int frameTime)
{
	Clock clock;
	long int loopTime;
	long int loopCounter = 0;
	WorldManager &worldManager = WorldManager::getInstance();

	// set custom frame time
	_frameTime = frameTime;

	while (!_gameOver)
	{
		clock.delta();
		++loopCounter;

		// 1 - GET INPUT


		// 2 - UPDATE GAME SCENE
		ObjectList allObjects = worldManager.getAllObjects();
		EventStep eventStep;

		// fire events
		ObjectListIterator it(&allObjects);
		for (it.first(); !it.isDone(); it.next())
		{
			Object *p_object = it.currentObject();
			p_object->eventHandler(&eventStep);
		}

		// update the game world
		worldManager.update();

		// 3 - RENDER GAME SCENE TO BACK BUFFER


		// 4 - SWAP BACK BUFFER TO CURRENT BUFFER


		// 5 - MEASURE CURRENT LOOP TIME AND SLEEP TO HIT THE TARGET TIME
		loopTime = clock.split();
		usleep(_frameTime - loopTime);
	}

	return loopCounter;
}

/**
 * Sets the game over flag to quit the game loop.
 * @param gameOver The new game over flag value.
 */
void GameManager::setGameOver(bool gameOver)
{
	_gameOver = gameOver;
}

/**
 * Gets the target frame time.
 * @return The taget frame time.
 */
int GameManager::getFrameTime()
{
	return _frameTime;
}
