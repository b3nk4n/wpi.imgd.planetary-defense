/*******************************************************************************
 * @file        GameManager.cpp
 * @author      bsautermeister
 * @description The core game management unit, which handles the game loop.
 ******************************************************************************/

#include <stdio.h>
#include "GameManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "ObjectList.h"
#include "LogManager.h"
#include "Clock.h"
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
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	InputManager &inputManager = InputManager::getInstance();

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

	if (graphicsManager.startUp())
	{
		logManager.writeLog(LOG_ERROR,
			"GameManager::startUp()",
			"GraphicsManager could not be started\n");
		return -1;
	}
	else
	{
		logManager.writeLog(LOG_ERROR,
			"GameManager::startUp()",
			"GraphicsManager started\n");
	}

	if (inputManager.startUp())
	{
		logManager.writeLog(LOG_ERROR,
			"GameManager::startUp()",
			"InputManager could not be started\n");
		return -1;
	}
	else
	{
		logManager.writeLog(LOG_ERROR,
			"GameManager::startUp()",
			"InputManager started\n");
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
	// verify manager is started
	if (!_isStarted)
		return;

	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();
	GraphicsManager &graphicsManager = GraphicsManager::getInstance();
	InputManager &inputManager = InputManager::getInstance();

	logManager.writeLog(LOG_INFO,
			"GameManager::shutDown()",
			"GameManager shut down process started\n");

	logManager.writeLog(LOG_ERROR,
			"GameManager::shutDown()",
			"InputManager shutting down\n");
	inputManager.shutDown();

	logManager.writeLog(LOG_ERROR,
			"GameManager::shutDown()",
			"GraphicsManager shutting down\n");
	graphicsManager.shutDown();

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
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();
	GraphicsManager &graphcisManager = GraphicsManager::getInstance();
	InputManager &inputManager = InputManager::getInstance();
	Clock clock;
	long int loopTime = frameTime;
	long int loopCounter = 0;
	long int targetTimeDiff;

	// set custom frame time
	_frameTime = frameTime;

	while (!_gameOver)
	{
		float lastDelta = loopTime / 1000000.0f;
		clock.delta();
		++loopCounter;

		// 1 - GET INPUT
		inputManager.getInput();

		// 2 - UPDATE GAME SCENE
		// fire events
		EventStep eventStep(lastDelta);
		onEvent(&eventStep);

		// update the game world
		worldManager.update(lastDelta);

		// 3 - RENDER GAME SCENE TO BACK BUFFER
		worldManager.draw();

		// 4 - SWAP BACK BUFFER TO CURRENT BUFFER
		graphcisManager.swapBuffers();

		// 5 - MEASURE CURRENT LOOP TIME AND SLEEP TO HIT THE TARGET TIME
		loopTime = clock.split();
		targetTimeDiff = _frameTime - loopTime;
		// just sleep if target is not already expired
		if (targetTimeDiff > 0)
		{
			logManager.writeLog(LOG_INFO,
				"GameManager::run()",
				"Target time reached. Sleep for: %ld\n",
				targetTimeDiff);
			Clock clock2;
			clock.delta();
			usleep(targetTimeDiff);
			long int sleepTime = clock.split();
			logManager.writeLog(LOG_INFO,
				"GameManager::run()",
				"Really slept for: %ld\n",
				sleepTime);
		}
		else
		{
			logManager.writeLog(LOG_WARNING,
				"GameManager::run()",
				"Target time not reached: %ld\n",
				targetTimeDiff);
		}
	}

	return loopCounter;
}

/**
 * Validates if event is handles by this manager.
 * @param eventType The event type name.
 * @return Returns TRUE if event is handled, else FALSE.
 */
 bool GameManager::isValid(string eventType)
 {
 	return eventType == STEP_EVENT;
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
int GameManager::getFrameTime(void)
{
	return _frameTime;
}
