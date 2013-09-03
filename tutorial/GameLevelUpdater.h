/* GameLevelUpdater.h */

#ifndef GAME_LEVEL_UPDATER_H
#define GAME_LEVEL_UPDATER_H

#include "ViewObject.h"

#define ENEMY_SPAWN_TICKS 1500
#define ENEMY_DELAY_TICKS 450
#define BOSS_SPAWN_TICKS 1200 
#define BOSS_DELAY_TICKS 9999999 // endless until boss leaves world or is killed

enum GameLevelSates
{
	ENEMY_SPAWN,
	ENEMY_DELAY,
	BOSS_SPAWN,
	BOSS_DELAY
};

class GameLevelUpdater : public ViewObject
{
private:
	int difficulty;
	int stepTimer;
	GameLevelSates currentState;
	
protected:
	/**
	 * Handles update.
	 */
	void step();

	/**
	 * Sends a command.
	 */
	void sendCommand(int command);

	/**
	 * Goes to the next state.
	 */
	void nextState(void);

	/**
	 * Select start state.
	 */
	void startState(void);

public:
	/**
	 * Creates a new game over instance.
	 */
	GameLevelUpdater(int difficulty);
	/**
	 * Supresses rendering.
	 */
	void draw(void);
	/**
	 * Handles the events.
	 */
	int eventHandler(Event *p_event);

	/**
	 * Spawns the enemies.
	 */
	void spawnEnemies(void);

	/**
	 * Spawns the boss.
	 */
	void spawnBoss(void);
};

#endif