/*******************************************************************************
 * @file        game.cpp
 * @author      bsautermeister
 * @description The engines test game to verify the graphical appearance.
 ******************************************************************************/

#include <stdlib.h>
#include "LogManager.h"
#include "GameManager.h"
#include "EventStep.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "TestObject.h"

#define TEST_OBJECTS_COUNT 4

// prototypes
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
	if (gameManager.startUp(true))
	{
		logManager.writeLog(LOG_ERROR,
			"main()",
			"Game manager startup error\n");
		gameManager.shutDown();
		exit(1);
	}

	// configure the log manager
	logManager.setVerbosity(LOG_DEBUG);

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
 * Loads the game resources.
 */
void loadResources(void)
{
	// load games txt sprite sheets
}

/**
 * Populates the game world.
 */
void populateWorld(void)
{
	TestObject *o1 = new TestObject();
	o1->setSTL(10);
	o1->setPosition(Position(10, 10));
	o1->setVelocityX(0.25f);
	o1->setVelocityY(0.25f);
	o1->registerInterest(STEP_EVENT);
	TestObject *o2 = new TestObject();
	o2->setStepsToGameOver(100);
	o2->setPosition(Position(15, 5));
	o2->setVelocityX(0.33f);
	o2->setVelocityY(0.33f);
	o2->setSolidness(HARD);
	o2->registerInterest(STEP_EVENT);
	o2->registerInterest(OUT_EVENT);
	TestObject *o3 = new TestObject();
	o3->setPosition(Position(50, 10));
	o3->setVelocityX(-0.1f);
	o3->registerInterest(STEP_EVENT);
	TestObject *o4 = new TestObject();
	o4->setPosition(Position(30, 20));
	o4->setSolidness(HARD);
	o4->registerInterest(KEYBOARD_EVENT);
	o4->registerInterest(MOUSE_EVENT);
	o4->registerInterest(COLLISION_EVENT);
}
