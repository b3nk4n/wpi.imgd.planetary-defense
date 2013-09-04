/* LogManager.cpp */

#include <stdarg.h>
#include "LogManager.h"

/**
 * Creates a new log manager instance.
 */
LogManager::LogManager(void)
{

}

/**
 * Hides copy constructor.
 * @param logManager The log manager to copy.
 */
LogManager::LogManager(LogManager const &logManager)
{

}

/**
 * Hides equals operator.
 * @param logManager The log manager to copy.
 */
void LogManager::operator=(LogManager const &logManager)
{

}

/**
 * Cleans up the log manager.
 */
LogManager::~LogManager(void)
{

}

/**
 * Gets the singleton log manager instance.
 * @return The singleton log manager instance.
 */
LogManager& LogManager::getInstance(void)
{
	static LogManager logManager;
	return logManager;
}

/**
 * Starts up the log manager.
 * @param flush Optional activates flusing. Default is FALSE.
 * @return Returns 0 if start up was successfull, else negative.
 */
int LogManager::startUp(bool flush)
{
	return -1;
}

/**
 * Shuts down the log manager.
 */
void LogManager::shutDown(void)
{

}

/**
 * Writes a log massage.
 * @param format The format string in classic printf() style.
 * @param ... Additional parameters.
 * @return Returns number of bytes written or -1 if an error occured.
 */
int LogManager::writeLog(const char *format, ...)
{
	int bytesWritten = 0;
	bytesWritten += fprintf(stderr, "[%s] : ", getTimeString());

	if (ferror(stderr))
	{
		return -1;
	}

	va_list args;

	// setup argmument stack
	va_start(args, format);

	// write format string and including arguments
	bytesWritten += vfprintf(stderr, format, args);

	if (ferror(stderr))
	{
		return -1;
	}

	// cleanup argument stack
	va_end(args);

	return bytesWritten;
}