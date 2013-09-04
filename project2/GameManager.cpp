/*******************************************************************************
 * @file        GameManager.cpp
 * @author      bsautermeister
 * @description The core game management unit, which handles the game loop.
 ******************************************************************************/

#include <stdio.h>
#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"

/**
 * Creates a game manager instance.
 */
GameManager::GameManager(void)
{

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

	if (logManager.startUp(flush))
	{
		perror("Could not start the log manager");
		return -1;
	}

	return 0;
}

/**
 * Shuts down all game manager services.
 */
void GameManager::shutDown(void)
{
	LogManager &logManager = LogManager::getInstance();

	logManager.shutDown();
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

	// set custom frame time
	_frameTime = frameTime;

	while (!_gameOver)
	{
		clock.delta();
		++loopCounter;

		// get input


		// update game scene


		// render game scene to back buffer


		// swap back buffer to current buffer


		// measure current loop time and sleep to hit target time
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
