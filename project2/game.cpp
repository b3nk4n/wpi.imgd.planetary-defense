/* game.cpp */

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
	logManager.writeLog("Test %d,%s\n", 123, "hallo");

	return 0;
}