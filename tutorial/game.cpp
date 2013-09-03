/* game.cpp */

#include <stdlib.h> // for exit()
#include "GameManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Star.h"
#include "GameStart.h"
#include "utility.h"

#define STARS_COUNT 16

/* Prototypes */
void loadResources(void);
void populateWorld(void);
void spawnStars(void);

/**
 * Games main function
 */
int main(int argc, char *argv[])
{
	LogManager &logManager = LogManager::getInstance();

	// start up game manager
	GameManager &gameManager = GameManager::getInstance();

	if (gameManager.startUp())
	{
		logManager.writeLog("GameManager: startup error");
		gameManager.shutDown();
		exit(1);
	}

	splash();

	loadResources();
	populateWorld();

	gameManager.run();

	// shutdown everything
	gameManager.shutDown();
}

/**
 * Loads the game resources.
 */
void loadResources(void)
{
	// load saucer sprite
	ResourceManager &resourceManager = ResourceManager::getInstance();
	resourceManager.loadSprite("sprites/saucer-spr.txt", "saucer");
	resourceManager.loadSprite("sprites/ufo-spr.txt", "ufo");
	resourceManager.loadSprite("sprites/ship-spr.txt", "ship");
	resourceManager.loadSprite("sprites/bullet-spr.txt", "bullet");
	resourceManager.loadSprite("sprites/laser-spr.txt", "laser");
	resourceManager.loadSprite("sprites/rocket-spr.txt", "rocket");
	resourceManager.loadSprite("sprites/explosion-spr.txt", "explosion_small");
	resourceManager.loadSprite("sprites/explosionbig-spr.txt", "explosion_large");
	resourceManager.loadSprite("sprites/gameover-spr.txt", "gameover");
	resourceManager.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	resourceManager.loadSprite("sprites/poweruplaser-spr.txt", "poweruplaser");
	resourceManager.loadSprite("sprites/poweruprocket-spr.txt", "poweruprocket");
	resourceManager.loadSprite("sprites/powerupscore-spr.txt", "powerupscore");
}

/**
 * Populates the game world.
 */
void populateWorld(void)
{
	spawnStars();

	new GameStart();
}

/**
 * Spawns the configured amount of stars.
 */
void spawnStars(void)
{
	for (int i = 0; i < STARS_COUNT; ++i)
	{
		new Star();
	}
}








