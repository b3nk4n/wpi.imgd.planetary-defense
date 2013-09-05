/*******************************************************************************
 * @file        game.cpp
 * @author      bsautermeister
 * @description The engines dummy game.
 ******************************************************************************/

#include <stdlib.h>
#include "LogManager.h"
#include "Clock.h"
#include "GameManager.h"
#include "ObjectList.h"

// prototypes
void logManagerTest(void);
void clockTest(void);
void objectListTest(void);
void objectListFillWithObject(ObjectList *p_objectList, int count);
void objectList2Log(ObjectList *p_objectList);

/**
 * The games main function.
 * @param argc The arguments count.
 * @param argv The argument vector.
 * @return The succes code.
 */
int main(int argc, char *argv[])
{
	LogManager &logManager = LogManager::getInstance();
	logManager.setVerbosity(LOG_DEBUG);

	// start up game manager
	GameManager &gameManager = GameManager::getInstance();

	if (gameManager.startUp(true))
	{
		logManager.writeLog(LOG_ERROR,
			"main()",
			"Game startup error");
		gameManager.shutDown();
		exit(1);
	}

	// RUN TESTS
	logManagerTest();
	clockTest();
	objectListTest();

	// RUN GAME
	/*long int loops = gameManager.run();

	logManager.writeLog(LOG_DEBUG,
		"main()",
		"Loops done by the game manager: %ld\n",
		loops);*/

	// shutdown everything
	gameManager.shutDown();

	return 0;
}

/**
 * Tests the log manager.
 */
void logManagerTest(void)
{
	LogManager &logManager = LogManager::getInstance();
	int written = logManager.writeLog(LOG_DEBUG,
		"main()",
		"Test nummer: %d, string: %s\n",
		123,
		"hallo");
	logManager.writeLog(LOG_DEBUG,
		"main()",
		"Written: %d bytes\n",
		written);
}

/**
 * Tests the clock manager.
 */
void clockTest(void)
{
	LogManager &logManager = LogManager::getInstance();
	Clock clock;

	clock.delta();
	sleep(1);
	long int diff = clock.split();

	logManager.writeLog(LOG_DEBUG,
		"main()",
		"sleep(1) took exactly: %ldusec\n",
		diff);
}

/**
 * Tests the object list and its iterator.
 */
void objectListTest(void)
{
	LogManager &logManager = LogManager::getInstance();

	ObjectList list_empty;
	ObjectList list_singleObject;
	ObjectList list_threeObjects;
	ObjectList list_full;

	// insert tests
	objectListFillWithObject(&list_singleObject, 1);
	objectListFillWithObject(&list_threeObjects, 3);
	objectListFillWithObject(&list_full, MAX_OBJECTS);

	objectList2Log(&list_empty);
	objectList2Log(&list_singleObject);
	objectList2Log(&list_threeObjects);
	objectList2Log(&list_full);

	// add/remove tests
	Object obj;
	obj.setPosition(Position(9999, 9999));

	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Adding one object in list_threeObject\n");

	list_threeObjects.insert(&obj);

	objectList2Log(&list_threeObjects);

	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Removing the last added object from list_threeObject\n");

	list_threeObjects.remove(&obj);

	objectList2Log(&list_threeObjects);

	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Trying to remove a not inserted object from list_threeObject\n");

	Object obj_notInserted;
	list_threeObjects.remove(&obj_notInserted);

	objectList2Log(&list_threeObjects);

	// test for full list
	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Empty list with size %d is not full (%s), but empty (%s)\n",
			list_empty.getCount(),
			list_empty.isFull() == false ? "true" : "false",
			list_empty.isEmpty() == true ? "true" : "false");
	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Full list with size %d is full (%s), but not empty (%s)\n",
			list_full.getCount(),
			list_full.isFull() == true ? "true" : "false",
			list_full.isEmpty() == false ? "true" : "false");

	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Inserting to full list returns error (%s)\n",
			list_full.insert(&obj) == -1 ? "true" : "false");
}

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
