/*******************************************************************************
 * @file        GameManager.h
 * @author      bsautermeister
 * @description The core game management unit, which handles the game loop.
 ******************************************************************************/

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <time.h>
#include "Manager.h"

#define DEFAULT_FRAME_TIME 33333 // in usec

/**
 * Class which manages the games workflow.
 */
class GameManager : public Manager
{
private:
	/**
	 * Indicates whether the game is over.
	 */
	bool _gameOver;

	/**
	 * The games target frame time.
	 */
	int _frameTime;

	/**
	 * Creates a game manager instance.
	 */
	GameManager(void);

	/**
	 * Hides copy constructor.
	 */
	GameManager(GameManager const&);

	/**
	 * Hides assignment operator.
	 */
	void operator=(GameManager const&);

public:
	/**
	 * Cleansup the game manager.
	 */
	~GameManager(void);

	/**
	 * Gets the singleton game manager instance.
	 * @return The singleton game manager instance.
	 */
	static GameManager& getInstance(void);

	/**
	 * Starts up all game manager services.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	int startUp(void);

	/**
	 * Starts up all game manager services.
	 * @param flush Configures log file flushing.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	int startUp(bool flush);

	/**
	 * Shuts down all game manager services.
	 */
	virtual void shutDown(void);

	/**
	 * Starts the blocking game loop.
	 * @param frameTime The target frame time. Default is DEFAULT_FRAME_TIME.
	 * @return The number of game loops updated and rendered.
	 */
	long int run(int frameTime = DEFAULT_FRAME_TIME);

	/**
	 * Validates if event is handles by this manager.
	 * @param eventType The event type name.
	 * @return Returns TRUE if event is handled, else FALSE.
	 */
	 virtual bool isValid(string eventType);

	/**
	 * Sets the game over flag to quit the game loop.
	 * @param gameOver The new game over flag value.
	 */
	void setGameOver(bool gameOver);

	/**
	 * Gets the target frame time.
	 * @return The taget frame time.
	 */
	int getFrameTime();
};

#endif
