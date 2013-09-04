/*******************************************************************************
 * @file        game.cpp
 * @author      bsautermeister
 * @description The engines dummy game.
 ******************************************************************************/

#include <stdlib.h>
#include "LogManager.h"

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
	if (logManager.startUp())
	{
		// error occured
		exit(1);
	}

	int written = logManager.writeLog(LOG_DEBUG,
		"main()",
		"Test nummer: %d, string: %s\n",
		123,
		"hallo");
	logManager.writeLog(LOG_DEBUG,
		"main()",
		"Written: %d bytes\n",
		written);

	return 0;
}