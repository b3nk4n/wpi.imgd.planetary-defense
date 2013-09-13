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
#include "TestCollidableObject.h"

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
	TestCollidableObject *o2 = new TestCollidableObject();
	o2->setPosition(Position(15, 5));
	o2->setVelocityX(0.33f);
	o2->setVelocityY(0.33f);
	o2->setSolidness(HARD);
	o2->registerInterest(STEP_EVENT);
	o2->registerInterest(OUT_EVENT);
	TestObject *o3 = new TestObject();
	o3->setPosition(Position(50, 10));
	o3->setVelocityX(-0.1f);
	o3->setStepsToGameOver(150);
	o3->registerInterest(STEP_EVENT);
	TestObject *o4 = new TestObject();
	o4->setPosition(Position(30, 20));
	o4->setSolidness(HARD);
	o4->registerInterest(KEYBOARD_EVENT);
	o4->registerInterest(MOUSE_EVENT);


	// *** collision/solidness test:

	// top row:
	TestObject *hard1 = new TestObject();
	hard1->setSolidness(HARD);
	hard1->setPosition(Position(40, 1));
	hard1->setVelocityY(0.25);

	TestObject *hard2 = new TestObject();
	hard2->setSolidness(HARD);
	hard2->setPosition(Position(42, 1));
	hard2->setVelocityY(0.25);

	TestObject *hard3 = new TestObject();
	hard3->setSolidness(HARD);
	hard3->setPosition(Position(44, 1));
	hard3->setVelocityY(0.25);

	TestObject *soft4 = new TestObject();
	soft4->setSolidness(SOFT);
	soft4->setPosition(Position(46, 1));
	soft4->setVelocityY(0.25);

	TestObject *soft5 = new TestObject();
	soft5->setSolidness(SOFT);
	soft5->setPosition(Position(48, 1));
	soft5->setVelocityY(0.25);

	TestObject *spectral6 = new TestObject();
	spectral6->setSolidness(SPECTRAL);
	spectral6->setPosition(Position(50, 1));
	spectral6->setVelocityY(0.25);

	// bottom row:
	TestObject *hard_1 = new TestObject();
	hard_1->setSolidness(HARD);
	hard_1->setPosition(Position(40, 21));
	hard_1->setVelocityY(-0.25);

	TestObject *soft_2 = new TestObject();
	soft_2->setSolidness(SOFT);
	soft_2->setPosition(Position(42, 21));
	soft_2->setVelocityY(-0.25);

	TestObject *spectral_3 = new TestObject();
	spectral_3->setSolidness(SPECTRAL);
	spectral_3->setPosition(Position(44, 21));
	spectral_3->setVelocityY(-0.25);

	TestObject *soft_4 = new TestObject();
	soft_4->setSolidness(SOFT);
	soft_4->setPosition(Position(46, 21));
	soft_4->setVelocityY(-0.25);

	TestObject *spectral_5 = new TestObject();
	spectral_5->setSolidness(SPECTRAL);
	spectral_5->setPosition(Position(48, 21));
	spectral_5->setVelocityY(-0.25);

	TestObject *spectral_6 = new TestObject();
	spectral_6->setSolidness(SPECTRAL);
	spectral_6->setPosition(Position(50, 21));
	spectral_6->setVelocityY(-0.25);

	// no soft:
	TestObject *hard01 = new TestObject();
	hard01->setSolidness(HARD);
	hard01->setPosition(Position(60, 1));
	hard01->setVelocityY(0.25);
	hard01->setNoSoft(true);

	TestObject *soft02 = new TestObject();
	soft02->setSolidness(SOFT);
	soft02->setPosition(Position(62, 1));
	soft02->setVelocityY(0.25);
	soft02->setNoSoft(true);

	TestObject *soft03 = new TestObject();
	soft03->setSolidness(SOFT);
	soft03->setPosition(Position(64, 1));
	soft03->setVelocityY(0.25);
	soft03->setNoSoft(true);

	TestObject *soft04 = new TestObject();
	soft04->setSolidness(SOFT);
	soft04->setPosition(Position(60, 21));

	TestObject *soft05 = new TestObject();
	soft05->setSolidness(SOFT);
	soft05->setPosition(Position(62, 21));

	TestObject *hard06 = new TestObject();
	hard06->setSolidness(HARD);
	hard06->setPosition(Position(64, 21));
}
