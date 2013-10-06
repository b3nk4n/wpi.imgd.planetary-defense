/*******************************************************************************
 * @file        game.cpp
 * @author      bsautermeister
 * @description The engines test game to verify the graphical appearance.
 ******************************************************************************/

#include <stdlib.h>
#include "LogManager.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "MapObject.h"
#include "EnemyOrk.h"
#include "Player.h"
#include "Spawner.h"

// prototypes
void configureGame(void);
void loadResources(void);
void populateWorld(void);

/**
 * The games main function.
 * @param argc The arguments count.
 * @param argv The argument vector.
 * @return The succes code.
 */
int main(int argc, char *argv[])
{
	LogManager &logManager = LogManager::getInstance();
	GameManager &gameManager = GameManager::getInstance();
	
	// startup the game manager
	if (gameManager.startUp(true, 12345))
	{
		logManager.writeLog(LOG_ERROR,
			"main()",
			"Game manager startup error\n");
		gameManager.shutDown();
		exit(1);
	}

	// configure the log manager
	logManager.setVerbosity(LOG_DEBUG);
	
	splash();

	configureGame();
	loadResources();
	populateWorld();

	// RUN GAME
	long int loops = gameManager.run();

	logManager.writeLog(LOG_DEBUG,
		"main()",
		"Loops done by the game manager: %ld\n",
		loops);

	// shutdown everything
	gameManager.shutDown();

	return 0;
}

/**
 * Configures the game.
 */
void configureGame(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	Box world = Box(Position(0, 0), 240, 48);
	worldManager.setWorldBoundary(world);
}

/**
 * Loads the game resources.
 */
void loadResources(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();

	// load sprite sheets
	resourceManager.loadSprite("assets/sprites/goblin-spr.txt", "goblin");
	resourceManager.loadSprite("assets/sprites/ork-spr.txt", "ork");
	resourceManager.loadSprite("assets/sprites/solar-spr.txt", "solar");
	resourceManager.loadSprite("assets/sprites/machinegun-spr.txt", "machinegun");
	resourceManager.loadSprite("assets/sprites/bullet_1-spr.txt", "bullet_1");

	// load maps
	resourceManager.loadMap("assets/maps/simple-map.txt", "map1");

	// load levels
	resourceManager.loadLevel("assets/levels/easy-map.txt", "level1");
}

/**
 * Populates the game world.
 */
void populateWorld(void)
{
	Player *player = Player::getInstance();

	MapObject* mapObject = MapObject::getInstance();
	mapObject->loadMap("map1");
	mapObject->loadLevel("level1");
	Spawner* sp = Spawner::Instance();

}
