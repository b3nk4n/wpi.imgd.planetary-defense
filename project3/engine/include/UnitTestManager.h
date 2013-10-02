/*******************************************************************************
 * @file        UnitTestManager.h
 * @author      bsautermeister
 * @description Manager of a simplified unit test framework.
 ******************************************************************************/

#ifndef __UNIT_TEST_MANAGER__
#define __UNIT_TEST_MANAGER__

#include <stdarg.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using std::string;

#define MAX_TEST_CASES 256
#define TESTSFILE_NAME "unittests.log"

/**
 * A simple named test case.
 */
struct testCase
{
	string name;
	bool (* function)(void);
};

/**
 * Class managing a bunch of unit tests.
 */
class UnitTestManager
{
private:
	/**
	 * The registered test cases to run.
	 */
	struct testCase _testCases[MAX_TEST_CASES];

	/**
	 * The unit tests counter.
	 */
	int _casesCount;

	/**
	 * Points to the log file structure.
	 */
	FILE *p_file;

	/**
	 * The test managers setup function.
	 */
	void (* _funcSetup)(void);
	/**
	 * The test managers cleanup function.
	 */
	void (* _funcCleanup)(void);

	/**
	 * The setup function which is called before each run.
	 */
	void (* _funcBefore)(void);

	/**
	 * The cleanup function which is called after each run.
	 */
	void (* _funcAfter)(void);

	/**
	 * Creates a new unit test manager instance.
	 */
	UnitTestManager(void);

	/**
	 * Hides copy constructor.
	 */
	UnitTestManager(UnitTestManager const&);

	/**
	 * Hides equals operator.
	 */
	void operator=(UnitTestManager const&);

	/**
	 * Runs all unit tests.
	 * @return The number of succeeded tests.
	 */
	int testRunAll(void);

	/**
	 * Runs the specified unit test.
	 * @param testIndex The index of the test to run.
	 * @return The number of succeeded tests.
	 */
	int testRun(int testIndex);

	/**
	 * Writes a line log massage to the configured output stream.
	 * @param format The format string in classic printf() style.
	 * @param ... Additional parameters.
	 * @return Returns number of bytes written or -1 if an error occured.
	 */
	int print(const char *format, ...);


	/**
	 * Prints the frameworks ASCII bordered line.
	 * @param format The format string in classic printf() style.
	 * @param ... Additional parameters.
	 */
	void printBordered(const char *format, ...);


	/**
	 * Prints the frameworks ASCII logo.
	 */
	void printLogo(void);

	/**
	 * Prints an ASCII line.
	 * @param type The character type for the line.
	 * @param length The line length.
	 */
	void printLine(char type, int length);

	/**
	 * Prints an ASCII summary.
	 * @param total The number of tests.
	 * @param succeeded The number of succeeded tests.
	 */
	void printSummary(int total, int succeeded);

	/**
	 * Prints the help text.
	 */
	void printHelp(void);

public:
	/**
	 * Gets the singleton unit test manager instance.
	 * @return The singleton unit test manager instance.
	 */
	static UnitTestManager& getInstance(void);

	/**
	 * Configures the setup function.
	 * @param function The setup function.
	 */
	void configureSetupFunc(void (* function)(void));

	/**
	 * Configures the cleanup function.
	 * @param function The cleanup function.
	 */
	void configureCleanupFunc(void (* function)(void));

	/**
	 * Configures the before function.
	 * @param function The before function.
	 */
	void configureBeforeFunc(void (* function)(void));

	/**
	 * Configures the after function.
	 * @param function The after function.
	 */
	void configureAfterFunc(void (* function)(void));

	/**
	 * Registers a new unit test function
	 * @param function The test function to add.
	 */
	void registerTestFunction(string name, bool (*function)(void));

	/**
	 * Starts up the unit test manager and loads/opens all resources.
	 * @return Returns 0 if succeeded, else -1.
	 */
	int startUp(void);

	/**
	 * Shuts down the unit test manager and releases all resources.
	 */
	void shutDown(void);

	/**
	 * Runs the unit testing framework.
	 * @param argc The main's argc.
	 * @param argv The main's argv
	 */
	int run(int argc, char *argv[]);
};

#endif
