/* GameLevelUpdater.cpp */

#include "GameLevelUpdater.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "ViewObject.h"
#include "EventLevelCommand.h"
#include "GameStart.h"
#include "Saucer.h"
#include "Ufo.h"
#include "Boss.h"

/**
 * Creates a new game updater instance.
 */
GameLevelUpdater::GameLevelUpdater(int difficulty)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();

	// register for events
	registerInterest(STEP_EVENT);
	registerInterest(LEVEL_COMMAND_EVENT);

	// set object type
	setType("GameLevelUpdater");

	// disable collision detection
	setSolidness(SPECTRAL);

	this->difficulty = difficulty;

	startState();
}

/**
 * Handles the events.
 */
int GameLevelUpdater::eventHandler(Event *p_event)
{
	if (p_event->getType() == STEP_EVENT)
	{
		step();
		return 1;
	}

	if (p_event->getType() == LEVEL_COMMAND_EVENT)
	{
		EventLevelCommand *event_levelCommand = static_cast<EventLevelCommand *>(p_event);

		if (event_levelCommand->getCommand() == COMMAND_BOSS_KILLED)
		{
			startState();

			LogManager &logManager = LogManager::getInstance();
			logManager.writeLog("GameLevelUpdater::eventHandler() command received: %d", COMMAND_BOSS_KILLED);
		}

		return 1;
	}

	return 0;
}

/**
 * Handles step input.
 */
void GameLevelUpdater::step(void)
{
	--stepTimer;

	if (stepTimer <= 0)
	{
		nextState();
	}
}

/**
 * Renders the game over object.
 */
void GameLevelUpdater::draw(void)
{
	// suppress rendering!
}

/**
 * Sends the command
 */
void GameLevelUpdater::sendCommand(int command)
{
	WorldManager &worldManager = WorldManager::getInstance();
	LogManager &logManager = LogManager::getInstance();

	EventLevelCommand levelCommandEvent(command);
	worldManager.onEvent(&levelCommandEvent);

	logManager.writeLog("Command %d sended!", command);
	
}

/**
 * Goes to the next state.
 */
void GameLevelUpdater::nextState()
{
	if (currentState == ENEMY_SPAWN)
	{
		currentState = ENEMY_DELAY;
		stepTimer = ENEMY_DELAY_TICKS;
		sendCommand(COMMAND_STOP_ENEMY);
	}
	else if (currentState == ENEMY_DELAY)
	{
		currentState = BOSS_SPAWN;
		stepTimer = BOSS_SPAWN_TICKS;
		spawnBoss();
	}
	else if (currentState == BOSS_SPAWN)
	{
		currentState = BOSS_DELAY;
		stepTimer = BOSS_DELAY_TICKS;
		sendCommand(COMMAND_STOP_BOSS);
	}
	else
	{
		startState();
	}
}

/**
 * Select start state.
 */
void GameLevelUpdater::startState()
{
	currentState = ENEMY_SPAWN;
	stepTimer = ENEMY_SPAWN_TICKS;
	spawnEnemies();
}

/**
 * Spawns new enemies.
 */
void GameLevelUpdater::spawnEnemies()
{
	int saucerCount;
	int ufoCount;

	if (difficulty == EASY_DIFF)
	{
		saucerCount = INIT_SAUCER_COUNT_EASY;
		ufoCount = INIT_UFO_COUNT_EASY;
	}
	else if (difficulty == MEDIUM_DIFF)
	{
		saucerCount = INIT_SAUCER_COUNT_MED;
		ufoCount = INIT_UFO_COUNT_MED;
	}
	else
	{
		saucerCount = INIT_SAUCER_COUNT_HARD;
		ufoCount = INIT_UFO_COUNT_HARD;
	}

	for (int i = 0; i < saucerCount; ++i)
	{
		new Saucer();
	}

	for (int i = 0; i < ufoCount; ++i)
	{
		new Ufo();
	}

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog("GameLevelUpdater::spawnEnemies(): Enemie spawned");
}

/**
 * Spawns a new boss.
 */
void GameLevelUpdater::spawnBoss()
{
	new Boss();
}
