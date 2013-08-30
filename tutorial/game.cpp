/* game.cpp */

#include <stdlib.h> // for exit()
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Saucer.h"
#include "Hero.h"

/* Prototypes */
void loadResources(void);
void populateWorld(void);

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
	resourceManager.loadSprite("sprites/ship-spr.txt", "ship");
	resourceManager.loadSprite("sprites/bullet-spr.txt", "bullet");
	resourceManager.loadSprite("sprites/explosion-spr.txt", "explosion");
}

/**
 * Populates the game world.
 */
void populateWorld(void)
{
	new Saucer();
	new Hero();
}








