/*******************************************************************************
 * @file        UnitTestManager.cpp
 * @author      bsautermeister
 * @description Manager of a simplified unit test framework.
 ******************************************************************************/

#include "UnitTestManager.h"

#define UI_WIDTH 80
#define TITLE_TEXT_BORDER 3

/**
 * Creates a new unit test manager instance.
 */
UnitTestManager::UnitTestManager(void)
{
	_casesCount = 0;
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
 */
void UnitTestManager::testRunAll(void)
{
	int successCounter = 0;

	for (int i = 0; i < _casesCount; ++i)
	{
		// run test
		bool result = testRun(i);
		
		// test for success or fail
		if (result)
		{
			++successCounter;
		}
	}

	// prints summary
	printf("\n");
	printLine('=', UI_WIDTH);
	printf("\n");
	printTitle("TEST SUMMARY");
	printf(" >>> SUCCEEDED: %4d\n",
		successCounter);
	printf(" >>> FAILED:    %4d\n",
		_casesCount - successCounter);
}

/**
 * Runs the specified unit test.
 * @param testIndex The index of the test to run.
 * @return TRUE if test was successful, else FALSE 
 */
bool UnitTestManager::testRun(int testIndex)
{
	// print title
	printf("\n");
	printTitle("RUNNING TEST [%2d]",
		testIndex);
	printf(" > TEST NAME:   %s\n",
		_testCases[testIndex].name.c_str());

	// run before function
	if (_funcBefore != NULL)
		_funcBefore();

	// run current unit test
	bool result = _testCases[testIndex].function();

	// run after function
	if (_funcAfter != NULL)
		_funcAfter();
	
	printf(" > TEST RESULT: ");
	printf("%s\n", result == true ? "SUCCESS" : "FAIL");

	return result;
}

/**
 * Prints the frameworks ASCII title.
 */
void UnitTestManager::printLogo(void)
{
	printLine('#', UI_WIDTH);
	printf("##             ____ ___       __  __ ___________              __              ##\n");
	printf("##            |    |   \\____ |__|/  |\\__    ___/___   _______/  |_            ##\n");
	printf("##            |    |   /    \\|  \\   __\\|    |_/ __ \\ /  ___/\\   __\\           ##\n");
	printf("##            |    |  /   |  \\  ||  |  |    |\\  ___/ \\___ \\  |  |             ##\n");
	printf("##            |______/|___|  /__||__|  |____| \\___  >____  > |__|             ##\n");
	printf("##                         \\/                     \\/     \\/                   ##\n"); 
	printf("##                       by Benjamin Sautermeister (c) 2013                   ##\n");
	printLine('#', UI_WIDTH); 
	printf("\n");
}

/**
 * Prints an ASCII line.
 * @param type The character type for the line.
 * @param length The line length.
 */
void UnitTestManager::printLine(char type, int length)
{
	for (int i = 0; i < length; ++i)
		printf("%c", type);

	printf("\n");
}

/**
 * Prints the frameworks ASCII title.
 * @param format The format string in classic printf() style.
 * @param ... Additional parameters.
 */
void UnitTestManager::printTitle(const char *format, ...)
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
		printf("#");

	// BORDER LEFT
	for (int i = 0; i < TITLE_TEXT_BORDER; ++i)
		printf(" ");

	// TITLE
	printf("%s", buffer);

	// BORDER RIGHT
	for (int i = 0; i < TITLE_TEXT_BORDER; ++i)
		printf(" ");

	// LINE RIGHT
	for (int i = 0; i < lineAfter; ++i)
		printf("#");

	printf("\n");
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
 * Runs the unit testing framework.
 * @param argc The main's argc.
 * @param argv The main's argv
 */
int UnitTestManager::run(int argc, char *argv[])
{
	printLogo();

	if (argc != 2)
	{
		// show help:
		printLine('#', UI_WIDTH);
		printTitle("UNIT TESTING TOOL >>> HELP PAGE");
		printLine('#', UI_WIDTH);
		printf("\n");
		printTitle("Description:");
		printf("\n\tA very simple unit testing framework.\n\n");
		printTitle("Call:");
		printf("\n\t>./test [option]\n\n");
		printTitle("Options:");
		printf("\n\tall: Run all test\n");
		printf("\t%%d: Run test with given index\n\n");
		printTitle("Example calls:");
		printf("\n\t>./test all\n");
		printf("\t>./test 0\n");
		printf("\t>./test 10\n\n");
		printLine('#', UI_WIDTH);
		return 0;
	}

	if (_funcSetup != NULL)
		_funcSetup();

	if (strcmp(argv[1], "all") == 0)
	{
		printLine('#', UI_WIDTH);
		printTitle("UNIT TESTING TOOL >>> RUN ALL TESTS");
		printLine('#', UI_WIDTH);
		testRunAll();
	}
	else
	{
		int index = atoi(argv[1]);

		if (index >= 0 && index < _casesCount)
		{
			printLine('#', UI_WIDTH);
			printTitle("UNIT TESTING TOOL >>> RUN TEST INDEX %d", index);
			printLine('#', UI_WIDTH);
			testRun(index);
		}
		else
		{
			printf("Test function index out of range. Valid range is [%d - %d]\n",
				0,
				_casesCount - 1);
			return -1;
		}
	}
	// foot note
	printf("\n");
	printLine('-', UI_WIDTH);
	printf("\tNote: More details can be found in the log file.\n");

	if (_funcCleanup != NULL)
	_funcCleanup();

	return 0;
}
