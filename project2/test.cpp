/*******************************************************************************
 * @file        test.cpp
 * @author      bsautermeister
 * @description The test module for the game engine.
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LogManager.h"
#include "Clock.h"
#include "GameManager.h"
#include "ObjectList.h"

using std::string;

#define MAX_TEST_CASES 128

// prototypes
void testMain(int argc, char *argv[]);
void testSetup(void);
void testCleanup(void);
void testRunAll(void);
bool testRun(int testIndex);
void registerTestFunction(string name, bool (*function)(void));

bool testLogManager_writeLogNoParam(void);
bool testLogManager_writeLogMixedParam(void);
bool testClock_1SecSleep(void);
bool testClock_deltaRestsTime(void);
bool testClock_splitNotRestsTime(void);

bool testObjectList_emptyListIsEmpty(void);
bool testObjectList_emptyListNotFull(void);
bool testObjectList_emptyListCountZero(void);
bool testObjectList_singleListCountOne(void);
bool testObjectList_singleListNotEmpty(void);
bool testObjectList_singleListNotFull(void);
bool testObjectList_fullListIsFull(void);
bool testObjectList_removeInsertedObject(void);
bool testObjectList_removeNotInsertedObject(void);
bool testObjectList_realloc(void);
bool testObjectList_countZeroAfterClear(void);
bool testObjectList_operatorPlusEmptyListPlusEmptyListIsZero(void);
bool testObjectList_operatorPlusEmptyListPlusFilledListIsFilled(void);
bool testObjectList_operatorPlusFilledListPlusFilledListIsDoubledList(void);
bool testObjectList_operatorPlusFullListPlusFullListIsDoubledListWithRealloc(void);

void objectListFillWithObject(ObjectList *p_objectList, int count);
void objectList2Log(ObjectList *p_objectList);

/**
 * A test case.
 */
struct testCase
{
	string name;
	bool (* function)(void);
};

// global variables
struct testCase g_testCases[MAX_TEST_CASES];
int g_casesCount = 0;

/**
 * The games main function.
 * @param argc The arguments count.
 * @param argv The argument vector.
 * @return The succes code.
 */
int main(int argc, char *argv[])
{
	LogManager &logManager = LogManager::getInstance();
	GameManager &gameManager = GameManager::getInstance();
	
	// startup the game manager
	if (gameManager.startUp(true))
	{
		logManager.writeLog(LOG_ERROR,
			"main()",
			"Game manager startup error\n");
		gameManager.shutDown();
		exit(1);
	}

	// configure the log manager
	logManager.setVerbosity(LOG_DEBUG);

	testMain(argc, argv);

	// shutdown everything
	gameManager.shutDown();

	return 0;
}

/****************************************************************************
 *  PRIMITIVES UNIT TEST FRAMEWORK FUNCTIONS.
 ***************************************************************************/

/**
 * Primitives test framework main.
 */
void testMain(int argc, char *argv[])
{
	// show help
	if (argc != 2)
	{
		// help:
		printf("##############################################\n");
		printf("GAME ENGINE TEST TOOL >>> HELP\n");
		printf("##############################################\n\n");
		printf("Call:\n");
		printf("\t>./test [option]\n\n");
		printf("Example calls:\n");
		printf("\t>./test all\n");
		printf("\t>./test 0\n");
		printf("\t>./test 10\n\n");
		printf("Options:\n");
		printf("\tall: Run all test\n");
		printf("\t%%d: Run test with given index\n\n");
		printf("##############################################\n");
		return;
	}

	testSetup();

	if (strcmp(argv[1], "all") == 0)
	{
		printf("##############################################\n");
		printf("GAME ENGINE TEST TOOL >>> RUN ALL TESTS\n");
		printf("##############################################\n\n");
		testRunAll();
	}
	else
	{
		int index = atoi(argv[1]);

		if (index >= 0 && index < g_casesCount)
		{
			printf("##############################################\n");
			printf("GAME ENGINE TEST TOOL >>> RUN TEST INDEX %d\n", index);
			printf("##############################################\n\n");
			testRun(index);
		}
		else
		{
			printf("Test function index out of range. Valid range is [%d - %d]\n",
				0,
				g_casesCount - 1);
		}
	}
	testCleanup();
}

/**
 * Primitives test framework setup.
 */
void testSetup(void)
{
	// register functions
	registerTestFunction("testLogManager_writeLogNoParam", &testLogManager_writeLogNoParam);
	registerTestFunction("testLogManager_writeLogMixedParam", &testLogManager_writeLogMixedParam);
	
	registerTestFunction("testClock_1SecSleep", &testClock_1SecSleep);
	registerTestFunction("testClock_deltaRestsTime", &testClock_deltaRestsTime);
	registerTestFunction("testClock_splitNotRestsTime", &testClock_splitNotRestsTime);

	registerTestFunction("testObjectList_emptyListIsEmpty", &testObjectList_emptyListIsEmpty);
	registerTestFunction("testObjectList_emptyListNotFull", &testObjectList_emptyListNotFull);
	registerTestFunction("testObjectList_emptyListCountZero", &testObjectList_emptyListCountZero);
	registerTestFunction("testObjectList_singleListCountOne", &testObjectList_singleListCountOne);
	registerTestFunction("testObjectList_singleListNotEmpty", &testObjectList_singleListNotEmpty);
	registerTestFunction("testObjectList_singleListNotFull", &testObjectList_singleListNotFull);
	registerTestFunction("testObjectList_fullListIsFull", &testObjectList_fullListIsFull);
	registerTestFunction("testObjectList_removeInsertedObject", &testObjectList_removeInsertedObject);
	registerTestFunction("testObjectList_removeNotInsertedObject", &testObjectList_removeNotInsertedObject);
	registerTestFunction("testObjectList_realloc", &testObjectList_realloc);
	registerTestFunction("testObjectList_countZeroAfterClear", &testObjectList_countZeroAfterClear);
	registerTestFunction("testObjectList_operatorPlusEmptyListPlusEmptyListIsZero", &testObjectList_operatorPlusEmptyListPlusEmptyListIsZero);
	registerTestFunction("testObjectList_operatorPlusEmptyListPlusFilledListIsFilled", &testObjectList_operatorPlusEmptyListPlusFilledListIsFilled);
	registerTestFunction("testObjectList_operatorPlusFilledListPlusFilledListIsDoubledList", &testObjectList_operatorPlusFilledListPlusFilledListIsDoubledList);
	registerTestFunction("testObjectList_operatorPlusFullListPlusFullListIsDoubledListWithRealloc", &testObjectList_operatorPlusFullListPlusFullListIsDoubledListWithRealloc);
}

/**
 * Primitives test framework cleanup.
 */
void testCleanup(void)
{

}

/**
 * Primitives test framework run all tests.
 */
void testRunAll(void)
{
	int successCounter = 0;

	for (int i = 0; i < g_casesCount; ++i)
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
	printf("\n##############################################\n\n");
	printf("############### TEST SUMMARY: ################\n");
	printf(">>> SUCCEEDED: %2d\n",
		successCounter);
	printf(">>> FAILED:    %2d\n",
		g_casesCount - successCounter);

	// foot note
	printf("\n################## NOTE: #####################\n");
	printf("Note: More details can be found in '%s'.\n\n", LOGFILE_NAME);
}

/**
 * Primitives test framework run single test.
 */
bool testRun(int testIndex)
{
	// print title
	printf("\n############# RUNNING TEST [%2d] ##############\n",
		testIndex);
	printf("########## TEST NAME:   %s\n",
		g_testCases[testIndex].name.c_str());

	// run test
	bool result = g_testCases[testIndex].function();
	
	printf("########## TEST RESULT: ");
	printf("%s\n", result == true ? "SUCCESS" : "FAIL");

	return result;
}

/**
 * Primitives test framework test registration function.
 */
void registerTestFunction(string name, bool (*function)(void))
{
	if (g_casesCount < MAX_TEST_CASES)
	{
		struct testCase newTestCase;
		newTestCase.name = name;
		newTestCase.function = function;
		g_testCases[g_casesCount++] = newTestCase;
	}
}

/****************************************************************************
 *  UNIT TEST FUNCTIONS.
 ***************************************************************************/

bool testLogManager_writeLogNoParam(void)
{
	LogManager &logManager = LogManager::getInstance();
	int written = logManager.writeLog(LOG_DEBUG,
		"testLogManager_writeLogNoParam()",
		"Text with no param\n");
	logManager.writeLog(LOG_DEBUG,
		"testLogManager_writeLogNoParam()",
		"Written: %d bytes\n",
		written);

	return written == 67;
}

bool testLogManager_writeLogMixedParam(void)
{
	LogManager &logManager = LogManager::getInstance();
	int written = logManager.writeLog(LOG_DEBUG,
		"testLogManager_writeLogMixedParam()",
		"Nummer: %d, String: %s, Char: %c\n",
		123,
		"hallo",
		'x');
	logManager.writeLog(LOG_DEBUG,
		"testLogManager_writeLogMixedParam()",
		"Written: %d bytes\n",
		written);

	return written == 87;
}

bool testClock_1SecSleep(void)
{
	LogManager &logManager = LogManager::getInstance();
	Clock clock;

	clock.delta();
	sleep(1);
	long int diff = clock.split();

	logManager.writeLog(LOG_DEBUG,
		"clock_test1SecSleep()",
		"sleep(1) took exactly: %ldusec\n",
		diff);

	return diff > 985000 && diff < 1015000;
}

bool testClock_deltaRestsTime(void)
{
	LogManager &logManager = LogManager::getInstance();
	Clock clock;

	clock.delta();
	sleep(1);
	clock.delta();
	long int secondDelta = clock.delta();

	return secondDelta < 1000;
}

bool testClock_splitNotRestsTime(void)
{
	LogManager &logManager = LogManager::getInstance();
	Clock clock;

	clock.delta();
	sleep(1);
	clock.split();
	long int secondSplit = clock.split();

	return secondSplit > 990000;
}

bool testObjectList_emptyListIsEmpty(void)
{
	ObjectList list;

	return list.isEmpty();
}

bool testObjectList_emptyListNotFull(void)
{
	ObjectList list;

	return !list.isFull();
}

bool testObjectList_emptyListCountZero(void)
{
	ObjectList list;

	return list.getCount() == 0;
}

bool testObjectList_singleListCountOne(void)
{
	ObjectList list;

	objectListFillWithObject(&list, 1);

	return list.getCount() == 1;
}

bool testObjectList_singleListNotEmpty(void)
{
	ObjectList list;

	objectListFillWithObject(&list, 1);

	return !list.isEmpty();
}

bool testObjectList_singleListNotFull(void)
{
	ObjectList list;

	objectListFillWithObject(&list, 1);

	return !list.isFull();
}

bool testObjectList_fullListIsFull(void)
{
	ObjectList list;

	objectListFillWithObject(&list, INIT_LIST_SIZE);

	return list.isFull();
}

bool testObjectList_removeInsertedObject(void)
{
	LogManager &logManager = LogManager::getInstance();
	ObjectList list;
	Object obj;
	obj.setPosition(Position(9999, 9999));

	objectListFillWithObject(&list, 2);
	list.insert(&obj);
	objectListFillWithObject(&list, 2);

	objectList2Log(&list);

	int countBeforeRemove = list.getCount();

	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Removing the added object from list with count %d\n",
			countBeforeRemove);

	list.remove(&obj);

	int countAfterRemove = list.getCount();

	objectList2Log(&list);

	return countBeforeRemove - countAfterRemove == 1;
}

bool testObjectList_removeNotInsertedObject(void)
{
	LogManager &logManager = LogManager::getInstance();
	ObjectList list;
	Object obj;
	obj.setPosition(Position(9999, 9999));

	objectListFillWithObject(&list, 4);

	objectList2Log(&list);

	int countBeforeRemove = list.getCount();

	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Removing the added object from list with count %d\n",
			countBeforeRemove);

	list.remove(&obj);

	int countAfterRemove = list.getCount();

	objectList2Log(&list);

	return countBeforeRemove == countAfterRemove;
}

bool testObjectList_realloc(void)
{
	ObjectList list;

	objectListFillWithObject(&list, INIT_LIST_SIZE);

	bool isFullBeforeRealloc = list.isFull();

	objectListFillWithObject(&list, 1);

	bool isFullAfterRealloc = list.isFull();

	return isFullBeforeRealloc && !isFullAfterRealloc;
}

bool testObjectList_countZeroAfterClear(void)
{
	ObjectList list;

	objectListFillWithObject(&list, 4);

	int countBeforeClear = list.getCount();

	list.clear();

	int countAfterClear = list.getCount();

	return countBeforeClear > 0 && countAfterClear == 0;
}

bool testObjectList_operatorPlusEmptyListPlusEmptyListIsZero(void)
{
	ObjectList firstList;
	ObjectList secondList;

	ObjectList addedList = firstList + secondList;

	return addedList.getCount() == 0;
}

bool testObjectList_operatorPlusEmptyListPlusFilledListIsFilled(void)
{
	ObjectList firstList;
	ObjectList secondList;
	int fullSize = 4;

	objectListFillWithObject(&secondList, fullSize);

	ObjectList addedList = firstList + secondList;

	return addedList.getCount() == fullSize;
}

bool testObjectList_operatorPlusFilledListPlusFilledListIsDoubledList(void)
{
	ObjectList firstList;
	ObjectList secondList;
	int fullSize = 4;

	objectListFillWithObject(&firstList, fullSize);
	objectListFillWithObject(&secondList, fullSize);

	ObjectList addedList = firstList + secondList;

	return addedList.getCount() == 2 * fullSize;
}

bool testObjectList_operatorPlusFullListPlusFullListIsDoubledListWithRealloc(void)
{
	ObjectList firstList;
	ObjectList secondList;
	int fullSize = INIT_LIST_SIZE;

	objectListFillWithObject(&firstList, fullSize);
	objectListFillWithObject(&secondList, fullSize);

	ObjectList addedList = firstList + secondList;

	return addedList.getCount() == 2 * fullSize;
}

/****************************************************************************
 *  HELPER FUNCTIONS.
 ***************************************************************************/

/**
 * Fills the object list with setting its objecs position.
 * @param p_objectList The object list to fill.
 * @param count The cumber of objects to insert.
 */
void objectListFillWithObject(ObjectList *p_objectList, int count)
{
	for (int i = 0; i < count; ++i)
	{
		Object *obj = new Object();
		obj->setPosition(Position(i, i));
		p_objectList->insert(obj);
	}
}

/**
 * Logs the object list to a log file using its iterator.
 * @param p_objectList The object list to log.
 */
void objectList2Log(ObjectList *p_objectList)
{
	LogManager &logManager = LogManager::getInstance();

	ObjectListIterator li(p_objectList);
	for (li.first(); !li.isDone(); li.next())
	{
		logManager.writeLog(LOG_DEBUG,
			"objectList2Log()",
			"Object position: %d, %d\n",
			li.currentObject()->getPosition().getX(),
			li.currentObject()->getPosition().getY());
	}
}
