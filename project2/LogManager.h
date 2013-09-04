/* LogManager.h */

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>

#include "Manager.h"
#include "utility.h"

#define LOGFILE_NAME "GameEngine.log"

/**
 * The log file manager.
 */
class LogManager : public Manager
{
private:
	/**
	 * Creates a new log manager instance.
	 */
	LogManager(void);

	/**
	 * Hides copy constructor.
	 * @param logManager The log manager to copy.
	 */
	LogManager(LogManager const &logManager);

	/**
	 * Hides equals operator.
	 * @param logManager The log manager to copy.
	 */
	void operator=(LogManager const &logManager);

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
	 * Starts up the log manager.
	 * @param flush Optional activates flusing. Default is FALSE.
	 * @return Returns 0 if start up was successfull, else negative.
	 */
	int startUp(bool flush=false);

	/**
	 * Shuts down the log manager.
	 */
	void shutDown(void);

	/**
	 * Writes a log massage.
	 * @param format The format string in classic printf() style.
	 * @param ... Additional parameters.
	 * @return Returns number of bytes written or -1 if an error occured.
	 */
	int writeLog(const char *format, ...);
};

#endif