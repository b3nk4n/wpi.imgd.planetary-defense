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
	int written = logManager.writeLog("Test nummer: %d, string: %s\n", 123, "hallo");
	logManager.writeLog("Written: %d bytes\n", written);

	return 0;
}