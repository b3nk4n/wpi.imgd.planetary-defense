/*******************************************************************************
 * @file        LogManager.h
 * @author      bsautermeister
 * @description Simple log file manager with configurable log levels / verbosity
 *              and flushing.
 ******************************************************************************/

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>

#include "Manager.h"
#include "utility.h"

#define LOGFILE_NAME "enginex.log"

#define LOG_OFF 0
#define LOG_ERROR 1
#define LOG_WARNING 2
#define LOG_INFO 3
#define LOG_DEBUG 4

/**
 * The log file manager.
 */
class LogManager : public Manager
{
private:
	/**
	 * Indicates whether flushing after each write is activated.
	 */
	bool _doFlush;

	/**
	 * The current verbosity setting. Default is LOG_DEBUG.
	 */
	int _verbosity;

	/**
	 * Points to the log file structure.
	 */
	FILE *p_file;

	/**
	 * Creates a new log manager instance.
	 */
	LogManager(void);

	/**
	 * Hides copy constructor.
	 */
	LogManager(LogManager const&);

	/**
	 * Hides equals operator.
	 */
	void operator=(LogManager const&);

public:
	/**
	 * Cleans up the log manager.
	 */
	~LogManager(void);

	/**
	 * Gets the singleton log manager instance.
	 * @return The singleton log manager instance.
	 */
	static LogManager& getInstance(void);

	/**
	 * Starts up the log manager and opens the log file LOGFILE_NAME
	 * without flushing.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	virtual int startUp(void);

	/**
	 * Starts up the log manager and opens the log file LOGFILE_NAME.
	 * @param flush Optional activates flushing.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	int startUp(bool flush);

	/**
	 * Shuts down the log manager and closes the log file.
	 */
	virtual void shutDown(void);

	/**
	 * Writes a log massage.
	 * @param verbosity The new verbosity level.
	 * @param source The class and method name for easier locating the source.
	 * @param format The format string in classic printf() style.
	 * @param ... Additional parameters.
	 * @return Returns number of bytes written or -1 if an error occured.
	 */
	int writeLog(int verbosity, const char *source, const char *format, ...);

	/**
	 * Sets the verbosity level.
	 * @param verbosity The new verbosity level.
	 */
	void setVerbosity(int verbosity);
};

#endif
