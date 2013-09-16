/*******************************************************************************
 * @file        UnitTestManager.cpp
 * @author      bsautermeister
 * @description Manager of a simplified unit test framework.
 ******************************************************************************/

#include <unistd.h>
#include "UnitTestManager.h"

#define UI_WIDTH 80
#define TITLE_TEXT_BORDER 3

/**
 * Creates a new unit test manager instance.
 */
UnitTestManager::UnitTestManager(void)
{
	_casesCount = 0;
	p_file = stdout;
}

/**
 * Hides copy constructor.
 */
UnitTestManager::UnitTestManager(UnitTestManager const&)
{
}

/**
 * Hides equals operator.
 */
void UnitTestManager::operator=(UnitTestManager const&)
{
}

/**
 * Runs all unit tests.
 * @return The number of succeeded tests.
 */
int UnitTestManager::testRunAll(void)
{
	int successCounter = 0;

	for (int i = 0; i < _casesCount; ++i)
	{
		// run test
		successCounter += testRun(i);
	}

	return successCounter;
}

/**
 * Runs the specified unit test.
 * @param testIndex The index of the test to run.
 * @return The number of succeeded tests.
 */
int UnitTestManager::testRun(int testIndex)
{
	// print title
	print("\n");
	printBordered("RUNNING TEST [%2d]",
		testIndex);
	printBordered("TEST NAME:");
	printBordered("%s",
		_testCases[testIndex].name.c_str());

	// run before function
	if (_funcBefore != NULL)
		_funcBefore();

	// run current unit test
	bool result = _testCases[testIndex].function();

	// run after function
	if (_funcAfter != NULL)
		_funcAfter();
	
	printBordered("TEST RESULT:");
	printBordered("%s", result == true ? "SUCCESS" : "FAIL");

	return result ? 1 : 0;
}

/**
 * Gets the singleton unit test manager instance.
 * @return The singleton unit test manager instance.
 */
UnitTestManager& UnitTestManager::getInstance(void)
{
	static UnitTestManager unitTestManager;
	return unitTestManager;
}

/**
 * Configures the setup function.
 * @param function The setup function.
 */
void UnitTestManager::configureSetupFunc(void (* function)(void))
{
	_funcSetup = function;
}

/**
 * Configures the cleanup function.
 * @param function The cleanup function.
 */
void UnitTestManager::configureCleanupFunc(void (* function)(void))
{
	_funcCleanup = function;
}

/**
 * Configures the before function.
 * @param function The before function.
 */
void UnitTestManager::configureBeforeFunc(void (* function)(void))
{
	_funcBefore = function;
}

/**
 * Configures the after function.
 * @param function The after function.
 */
void UnitTestManager::configureAfterFunc(void (* function)(void))
{
	_funcAfter = function;
}

/**
 * Registers a new unit test function
 * @param function The test function to add.
 */
void UnitTestManager::registerTestFunction(string name, bool (*function)(void))
{
	if (_casesCount < MAX_TEST_CASES)
	{
		struct testCase newTestCase;
		newTestCase.name = name;
		newTestCase.function = function;
		_testCases[_casesCount++] = newTestCase;
	}
}

/**
 * Starts up the unit test manager and loads/opens all resources.
 * @return Returns 0 if succeeded, else -1.
 */
int UnitTestManager::startUp(void)
{
	// open the log file
	p_file = fopen(TESTSFILE_NAME, "w");

	// verify open was successful
	if (p_file == NULL)
	{
		perror("[UnitTestManager::startUp()]: Error while opening file.");
		return -1;
	}

	return 0;
}

/**
 * Shuts down the unit test manager and releases all resources.
 */
void UnitTestManager::shutDown(void)
{
	// close the test results file (fclose() flushes automatically)
	if (p_file != NULL)
	{
		fclose(p_file);
		p_file = stdout;
	}
}

/**
 * Runs the unit testing framework.
 * @param argc The main's argc.
 * @param argv The main's argv
 */
int UnitTestManager::run(int argc, char *argv[])
{
	int casesThisRun = 0;
	int successed = 0;

	printLogo();

	if (argc != 2)
	{
		// show help:
		printHelp();
		return 0;
	}

	// switch to log file printing
	if (startUp())
	{
		return -1;
	}

	printLogo();
	
	// wait a little to ensure the logo is printed
	sleep(1);

	if (_funcSetup != NULL)
		_funcSetup();

	if (strcmp(argv[1], "all") == 0)
	{
		printLine('#', UI_WIDTH);
		printBordered("UNIT TESTING TOOL >>> RUN ALL TESTS");
		printLine('#', UI_WIDTH);
		successed = testRunAll();
		casesThisRun = _casesCount;
	}
	else
	{
		int index = atoi(argv[1]);

		if (index >= 0 && index < _casesCount)
		{
			printLine('#', UI_WIDTH);
			printBordered("UNIT TESTING TOOL >>> RUN TEST INDEX %d", index);
			printLine('#', UI_WIDTH);
			successed = testRun(index);
			casesThisRun = 1;
		}
		else
		{
			print("Test function index out of range. Valid range is [%d - %d]\n",
				0,
				_casesCount - 1);
			return -1;
		}
	}

	printSummary(casesThisRun, successed);

	// foot note
	print("\n");
	printLine('-', UI_WIDTH);
	print("        Note: More details can be found in the game engines logfile.\n");

	if (_funcCleanup != NULL)
	_funcCleanup();

	// swith back to terminal output
	shutDown();

	printSummary(casesThisRun, successed);

	// console foot note
	print("\n");
	printLine('-', UI_WIDTH);
	print("       Note: Test results have been written to the file %s\n", TESTSFILE_NAME);

	return 0;
}

/**
 * Writes a line log massage to the configured output stream.
 * @param format The format string in classic printf() style.
 * @param ... Additional parameters.
 * @return Returns number of bytes written or -1 if an error occured.
 */
int UnitTestManager::print(const char *format, ...)
{
	int bytesWritten = 0;

	va_list args;

	// setup argmument stack
	va_start(args, format);

	// write formatted log content including given arguments
	bytesWritten += vfprintf(p_file, format, args);

	if (ferror(p_file))
	{
		return -1;
	}

	// try to flush the output
	if(fflush(p_file))
	{
		return -1;
	}

	// cleanup argument stack
	va_end(args);

	return bytesWritten;
}

/**
 * Prints the frameworks ASCII bordered line.
 * @param format The format string in classic printf() style.
 * @param ... Additional parameters.
 */
void UnitTestManager::printBordered(const char *format, ...)
{
	char buffer[256];

	// GET TITLE BY ARGUMENTS
	va_list args;
	// setup argmument stack
	va_start(args, format);
	// write formatted log content including given arguments
	vsprintf(buffer, format, args);
	// cleanup argument stack
	va_end(args);

	int lineCharCount = UI_WIDTH - strlen(buffer) - 2 * TITLE_TEXT_BORDER;
	int lineAfter = lineCharCount / 2;
	int lineBefore = lineCharCount - lineAfter;

	// LINE LEFT
	for (int i = 0; i < lineBefore; ++i)
		fprintf(p_file, "#");

	// BORDER LEFT
	for (int i = 0; i < TITLE_TEXT_BORDER; ++i)
		fprintf(p_file, " ");

	// TITLE
	fprintf(p_file, "%s", buffer);

	// BORDER RIGHT
	for (int i = 0; i < TITLE_TEXT_BORDER; ++i)
		fprintf(p_file, " ");

	// LINE RIGHT
	for (int i = 0; i < lineAfter; ++i)
		fprintf(p_file, "#");

	fprintf(p_file, "\n");
}

/**
 * Prints the frameworks ASCII title.
 */
void UnitTestManager::printLogo(void)
{
	printLine('#', UI_WIDTH);
	print("##             ____ ___       __  __ ___________              __              ##\n");
	print("##            |    |   \\____ |__|/  |\\__    ___/___   _______/  |_            ##\n");
	print("##            |    |   /    \\|  \\   __\\|    |_/ __ \\ /  ___/\\   __\\           ##\n");
	print("##            |    |  /   |  \\  ||  |  |    |\\  ___/ \\___ \\  |  |             ##\n");
	print("##            |______/|___|  /__||__|  |____| \\___  >____  > |__|             ##\n");
	print("##                         \\/                     \\/     \\/                   ##\n"); 
	print("##                       by Benjamin Sautermeister (c) 2013                   ##\n");
	printLine('#', UI_WIDTH); 
	print("\n");
}

/**
 * Prints an ASCII line.
 * @param type The character type for the line.
 * @param length The line length.
 */
void UnitTestManager::printLine(char type, int length)
{
	for (int i = 0; i < length; ++i)
		print("%c", type);

	print("\n");
}

/**
 * Prints an ASCII summary.
 * @param total The number of tests.
 * @param succeeded The number of succeeded tests.
 */
void UnitTestManager::printSummary(int total, int succeeded)
{
	print("\n");
	printLine('=', UI_WIDTH);
	print("\n");
	printBordered("TEST SUMMARY");
	printBordered(" >>> SUCCEEDED: %4d",
		succeeded);
	printBordered(" >>> FAILED:    %4d",
		total - succeeded);
	printBordered(" -------------------");
	printBordered(" >>> TOTAL:     %4d",
		total);
}

/**
 * Prints the help text.
 */
void UnitTestManager::printHelp(void)
{
	printLine('#', UI_WIDTH);
	printBordered("UNIT TESTING TOOL >>> HELP PAGE");
	printLine('#', UI_WIDTH);
	print("\n");
	printBordered("Description:");
	print("\n\tA very simple unit testing framework for automated testing");
	print("\n\twithout any dependecies to external libraries.\n\n");
	printBordered("Call:");
	print("\n\t>./test [option]\n\n");
	printBordered("Options:");
	print("\n\tall:   Run all test\n");
	print("\t%%d:    Run test with given index\n\n");
	printBordered("Example calls:");
	print("\n\t>./test all\n");
	print("\t>./test 0\n");
	print("\t>./test 10\n\n");
	printBordered("Unit tests overview:");
	print("\n");
	for (int i = 0; i < _casesCount; ++i)
	{
		print("%4d: %s \n",
			i,
			_testCases[i].name.c_str());
	}
	print("\n");
	printLine('#', UI_WIDTH);
}
