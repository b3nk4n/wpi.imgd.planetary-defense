/*******************************************************************************
 * @file        LogManager.cpp
 * @author      bsautermeister
 * @description Simple log file manager with configurable log levels / verbosity
 *              and flushing.
 ******************************************************************************/

#include <stdarg.h>
#include "LogManager.h"

/**
 * Creates a new log manager instance.
 */
LogManager::LogManager(void)
{
	this->_doFlush = false;
	this->_verbosity = LOG_DEBUG;
}

/**
 * Hides copy constructor.
 */
LogManager::LogManager(LogManager const &lm)
{
}

/**
 * Hides equals operator.
 */
void LogManager::operator=(LogManager const &lm)
{
}

/**
 * Cleans up the log manager.
 */
LogManager::~LogManager(void)
{
	shutDown();
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
 * Starts up the log manager and opens the log file LOGFILE_NAME
 * without flushing.
 * @return Returns 0 if start up was successfull, else negative.
 */
int LogManager::startUp(void)
{
	// open the log file
	p_file = fopen(LOGFILE_NAME, "w");

	// verify open was successful
	if (p_file == NULL)
		return -1;

	_isStarted = true;

	return 0;
}

/**
 * Starts up the log manager and opens the log file LOGFILE_NAME.
 * @param flush Optional activates flushing.
 * @return Returns 0 if start up was successfull, else negative.
 */
int LogManager::startUp(bool flush)
{
	this->_doFlush = flush;

	return startUp();
}

/**
 * Shuts down the log manager and closes the log file.
 */
void LogManager::shutDown(void)
{
	// close the log file (fclose() flushes automatically)
	if (p_file != NULL)
	{
		fclose(p_file);
		p_file = NULL;
	}
}

/**
 * Writes a log massage.
 * @param verbosity The new verbosity level.
 * @param source The class and method name for easier locating the source.
 * @param format The format string in classic printf() style.
 * @param ... Additional parameters.
 * @return Returns number of bytes written or -1 if an error occured.
 */
int LogManager::writeLog(int verbosity, const char *source, const char *format, ...)
{
	// verify log level
	if (verbosity > _verbosity)
		return 0;

	int bytesWritten = 0;

	// write log header
	bytesWritten += fprintf(p_file,
		"[%s - %s] : ",
		getTimeString(),
		source);

	if (ferror(p_file))
	{
		return -1;
	}

	va_list args;

	// setup argmument stack
	va_start(args, format);

	// write formatted log content including given arguments
	bytesWritten += vfprintf(p_file, format, args);

	if (ferror(p_file))
	{
		return -1;
	}

	if (_doFlush)
	{
		// try to flush the output
		if(fflush(p_file))
		{
			return -1;
		}
	}

	// cleanup argument stack
	va_end(args);

	return bytesWritten;
}

/**
 * Sets the verbosity level.
 * @param verbosity The new verbosity level.
 */
void LogManager::setVerbosity(int verbosity)
{
	_verbosity = verbosity;
}
