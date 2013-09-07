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
	 */
	void testRunAll(void);

	/**
	 * Runs the specified unit test.
	 * @param testIndex The index of the test to run.
	 * @return TRUE if test was successful, else FALSE 
	 */
	bool testRun(int testIndex);

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
	 * Prints the frameworks ASCII title.
	 * @param format The format string in classic printf() style.
 	 * @param ... Additional parameters.
	 */
	void printTitle(const char *format, ...);

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
	 * Runs the unit testing framework.
	 * @param argc The main's argc.
	 * @param argv The main's argv
	 */
	int run(int argc, char *argv[]);
};

#endif
