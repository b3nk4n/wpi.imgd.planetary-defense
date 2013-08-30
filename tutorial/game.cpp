/* game.cpp */

#include <stdlib.h> // for exit()
#include "GameManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Saucer.h"
#include "Hero.h"
#include "Points.h"
#include "Star.h"

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

	// setup HUD
	new Points();
	ViewObject *p_nukes = new ViewObject();
	p_nukes->setLocation(TOP_LEFT);
	p_nukes->setViewString("Nukes");
	p_nukes->setValue(1);
	p_nukes->setColor(COLOR_YELLOW);

	spawnStars();
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








