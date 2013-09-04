/*******************************************************************************
 * @file        game.cpp
 * @author      bsautermeister
 * @description The engines dummy game.
 ******************************************************************************/

#include <stdlib.h>
#include "LogManager.h"
#include "Clock.h"
#include "GameManager.h"

/**
 * The games main function.
 * @param argc The arguments count.
 * @param argv The argument vector.
 * @return The succes code.
 */
int main(int argc, char *argv[])
{
	LogManager &logManager = LogManager::getInstance();
	logManager.setVerbosity(LOG_DEBUG);

	// start up game manager
	GameManager &gameManager = GameManager::getInstance();

	if (gameManager.startUp(true))
	{
		logManager.writeLog(LOG_ERROR,
			"main()",
			"Game startup error");
		gameManager.shutDown();
		exit(1);
	}

	// LOGGER TEST
	int written = logManager.writeLog(LOG_DEBUG,
		"main()",
		"Test nummer: %d, string: %s\n",
		123,
		"hallo");
	logManager.writeLog(LOG_DEBUG,
		"main()",
		"Written: %d bytes\n",
		written);

	// CLOCK TEST
	Clock clock;

	clock.delta();
	sleep(1);
	long int diff = clock.split();

	logManager.writeLog(LOG_DEBUG,
		"main()",
		"sleep(1) took exactly: %ldusec\n",
		diff);

	// GAME START
	long int loops = gameManager.run();

	logManager.writeLog(LOG_DEBUG,
		"main()",
		"Loops done by the game manager: %ld\n",
		loops);

	// shutdown everything
	gameManager.shutDown();

	return 0;
}
