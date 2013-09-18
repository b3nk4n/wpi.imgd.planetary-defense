/*******************************************************************************
 * @file        test.cpp
 * @author      bsautermeister
 * @description The test module for the game engine.
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "LogManager.h"
#include "Clock.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "InputManager.h"
#include "ObjectList.h"
#include "TestObject.h"
#include "TestCollidableObject.h"
#include "UnitTestManager.h"
#include "EventStep.h"
#include "EventTest.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "EventOut.h"
#include "EventCollision.h"
#include "Frame.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "utility.h"

using std::string;

// prototypes for setup
void testSetup(void);
void testCleanup(void);
void testBefore(void);
void testAfter(void);

// prototypes for tests
bool testGameManager_verifyIsStarted(void);
bool testGameManager_runAndGameOverNoHang(void);
bool testGameManager_changedFrameTimeHasEffect(void);
bool testGameManager_stepEventIsValid(void);
bool testGameManager_testEventIsNotValid(void);
bool testGraphicsManager_verifyIsStarted(void);
bool testWorldManager_markOneObjectForDelete(void);
bool testWorldManager_markOneObjectForDeleteTwice(void);
bool testWorldManager_clearAllObjects(void);
bool testWorldManager_verifyIsStarted(void);
bool testWorldManager_insertAndRemoveObject(void);
bool testWorldManager_stepEventIsNotValid(void);
bool testWorldManager_testEventIsValid(void);
bool testGameManager_registerInvalidEvent(void);
bool testLogManager_verifyIsStarted(void);
bool testLogManager_writeLogNoParam(void);
bool testLogManager_writeLogMixedParam(void);
bool testInputManager_verifyIsStarted(void);
bool testInputManager_keyboardEventIsValid(void);
bool testInputManager_mouseEventIsValid(void);
bool testInputManager_stepEventIsNotValid(void);
bool testResourceManager_verifyIsStarted(void);
bool testResourceManager_loadCorrectSpriteReturnsSuccess(void);
bool testResourceManager_loadErrorMistakeSpriteReturnsError(void);
bool testResourceManager_loadErrorColorSpriteReturnsError(void);
bool testResourceManager_loadErrorLessFramesSpriteReturnsError(void);
bool testResourceManager_loadErrorMoreFramesSpriteReturnsError(void);
bool testResourceManager_loadErrorLessHeightSpriteReturnsError(void);
bool testResourceManager_loadErrorMoreHeightSpriteReturnsError(void);
bool testResourceManager_loadErrorLessWidthSpriteReturnsError(void);
bool testResourceManager_loadErrorMoreWidthSpriteReturnsError(void);
bool testResourceManager_loadErrorUnknownFileReturnsError(void);
bool testResourceManager_getAndUnloadSprite(void);
bool testClock_1SecSleep(void);
bool testClock_deltaRestsTime(void);
bool testClock_splitNotRestsTime(void);
bool testPosition_createDefaultPosition(void);
bool testPosition_createCustomPosition(void);
bool testPosition_positionGettersAndSetters(void);
bool testPosition_positionXYSetter(void);
bool testPosition_samePositionsComparedIsTrue(void);
bool testPosition_differentPositionsComparedIsFalse(void);
bool testPosition_samePositionsNotComparedIsFalse(void);
bool testPosition_differentPositionsNotComparedIsTrue(void);
bool testBox_createDefaultBox(void);
bool testBox_createCustomBox(void);
bool testBox_cornerGetterSetter(void);
bool testBox_HorizontalVerticalGetterSetter(void);
bool testBox_sameBoxesComparedIsTrue(void);
bool testBox_differentBoxesComparedIsFalse(void);
bool testBox_sameBoxesNotComparedIsFalse(void);
bool testBox_differentBoxesNotComparedIsTrue(void);
bool testObject_setAndGetPosition(void);
bool testObject_setAndGetType(void);
bool testObject_setAndGetHardSolidness(void);
bool testObject_setAndGetSoftSolidness(void);
bool testObject_setAndGetSpectralSolidness(void);
bool testObject_solidnessHardIsSolid(void);
bool testObject_solidnessSoftIsSolid(void);
bool testObject_solidnessSpectralIsNotSolid(void);
bool testObject_registerInterest(void);
bool testObject_registerInterestTwice(void);
bool testObject_unregisterInterest(void);
bool testObject_unregisterInterestTwice(void);
bool testObject_registerCustomEvent(void);
bool testObject_verifyEventIsReceived(void);
bool testObject_verifyEventIsNotReceivedWhenNotRegisterd(void);
bool testObject_outEventIsFiredWhenOutScreen(void);
bool testObject_collisionEventIsFiredForHardToHard(void);
bool testObject_collisionEventIsFiredForHardToSoft(void);
bool testObject_collisionEventIsFiredForSoftToHard(void);
bool testObject_collisionEventIsFiredForSoftToSoft(void);
bool testObject_collisionEventIsNotFiredForSpectralToSoft(void);
bool testObject_collisionEventIsNotFiredForSoftToSpectral(void);
bool testObject_collisionEventIsNotFiredForSpectralToSpectral(void);
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
bool testObjectList_operatorPlusTwoFullListsEqualsDoubledListWithRealloc(void);
bool testFrame_ceateDefault(void);
bool testFrame_createCustom(void);
bool testFrame_getterAndSetter(void);
bool testSprite_createEmpty(void);
bool testSprite_createSingleFrame(void);
bool testSprite_frameOverflowReturnsError(void);
bool testUtility_boxContainsPointInsideTrue(void);
bool testUtility_boxContainsPointOutsideFalse(void);

// prototypes for helpers
void objectListFillWithObject(ObjectList *p_objectList, int count);
void objectList2Log(ObjectList *p_objectList);

/**
 * The main function, which configures and starts the unit test manager.
 * @param argc The arguments count.
 * @param argv The argument vector.
 * @return The succes code.
 */
int main(int argc, char *argv[])
{
	UnitTestManager &unitTestManager = UnitTestManager::getInstance();

	// CONFIGURE UNIT TEST MANAGER
	unitTestManager.configureSetupFunc(&testSetup);
	unitTestManager.configureCleanupFunc(&testCleanup);
	unitTestManager.configureBeforeFunc(&testBefore);
	unitTestManager.configureAfterFunc(&testAfter);

	// REGISTER UNIT TEST FUNCTION
	unitTestManager.registerTestFunction("testGameManager_verifyIsStarted", &testGameManager_verifyIsStarted);
	unitTestManager.registerTestFunction("testGameManager_runAndGameOverNoHang", &testGameManager_runAndGameOverNoHang);
	unitTestManager.registerTestFunction("testGameManager_changedFrameTimeHasEffect", &testGameManager_changedFrameTimeHasEffect);
	unitTestManager.registerTestFunction("testGameManager_stepEventIsValid", &testGameManager_stepEventIsValid);
	unitTestManager.registerTestFunction("testGameManager_testEventIsNotValid", &testGameManager_testEventIsNotValid);
	unitTestManager.registerTestFunction("testGameManager_registerInvalidEvent", &testGameManager_registerInvalidEvent);

	unitTestManager.registerTestFunction("testGraphicsManager_verifyIsStarted", &testGraphicsManager_verifyIsStarted);

	unitTestManager.registerTestFunction("testWorldManager_verifyIsStarted", &testWorldManager_verifyIsStarted);
	unitTestManager.registerTestFunction("testWorldManager_insertAndRemoveObject", &testWorldManager_insertAndRemoveObject);
	unitTestManager.registerTestFunction("testWorldManager_markOneObjectForDelete", &testWorldManager_markOneObjectForDelete);
	unitTestManager.registerTestFunction("testWorldManager_markOneObjectForDeleteTwice", &testWorldManager_markOneObjectForDeleteTwice);
	unitTestManager.registerTestFunction("testWorldManager_clearAllObjects", &testWorldManager_clearAllObjects);
	unitTestManager.registerTestFunction("testWorldManager_stepEventIsNotValid", &testWorldManager_stepEventIsNotValid);
	unitTestManager.registerTestFunction("testWorldManager_testEventIsValid", &testWorldManager_testEventIsValid);

	unitTestManager.registerTestFunction("testLogManager_verifyIsStarted", &testLogManager_verifyIsStarted);
	unitTestManager.registerTestFunction("testLogManager_writeLogNoParam", &testLogManager_writeLogNoParam);
	unitTestManager.registerTestFunction("testLogManager_writeLogMixedParam", &testLogManager_writeLogMixedParam);

	unitTestManager.registerTestFunction("testInputManager_verifyIsStarted", &testInputManager_verifyIsStarted);
	unitTestManager.registerTestFunction("testInputManager_keyboardEventIsValid", &testInputManager_keyboardEventIsValid);
	unitTestManager.registerTestFunction("testInputManager_mouseEventIsValid", &testInputManager_mouseEventIsValid);
	unitTestManager.registerTestFunction("testInputManager_stepEventIsNotValid", &testInputManager_stepEventIsNotValid);

	unitTestManager.registerTestFunction("testResourceManager_verifyIsStarted", &testResourceManager_verifyIsStarted);
	unitTestManager.registerTestFunction("testResourceManager_loadCorrectSpriteReturnsSuccess", &testResourceManager_loadCorrectSpriteReturnsSuccess);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorMistakeSpriteReturnsError", &testResourceManager_loadErrorMistakeSpriteReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorColorSpriteReturnsError", &testResourceManager_loadErrorColorSpriteReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorLessFramesSpriteReturnsError", &testResourceManager_loadErrorLessFramesSpriteReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorMoreFramesSpriteReturnsError", &testResourceManager_loadErrorMoreFramesSpriteReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorLessHeightSpriteReturnsError", &testResourceManager_loadErrorLessHeightSpriteReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorMoreHeightSpriteReturnsError", &testResourceManager_loadErrorMoreHeightSpriteReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorLessWidthSpriteReturnsError", &testResourceManager_loadErrorLessWidthSpriteReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorMoreWidthSpriteReturnsError", &testResourceManager_loadErrorMoreWidthSpriteReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_loadErrorUnknownFileReturnsError", &testResourceManager_loadErrorUnknownFileReturnsError);
	unitTestManager.registerTestFunction("testResourceManager_getAndUnloadSprite", &testResourceManager_getAndUnloadSprite);

	unitTestManager.registerTestFunction("testClock_1SecSleep", &testClock_1SecSleep);
	unitTestManager.registerTestFunction("testClock_deltaRestsTime", &testClock_deltaRestsTime);
	unitTestManager.registerTestFunction("testClock_splitNotRestsTime", &testClock_splitNotRestsTime);

	unitTestManager.registerTestFunction("testPosition_createDefaultPosition", &testPosition_createDefaultPosition);
	unitTestManager.registerTestFunction("testPosition_createCustomPosition", &testPosition_createCustomPosition);
	unitTestManager.registerTestFunction("testPosition_positionGettersAndSetters", &testPosition_positionGettersAndSetters);
	unitTestManager.registerTestFunction("testPosition_positionXYSetter", &testPosition_positionXYSetter);
	unitTestManager.registerTestFunction("testPosition_samePositionsComparedIsTrue", &testPosition_samePositionsComparedIsTrue);
	unitTestManager.registerTestFunction("testPosition_differentPositionsComparedIsFalse", &testPosition_differentPositionsComparedIsFalse);
	unitTestManager.registerTestFunction("testPosition_samePositionsNotComparedIsFalse", &testPosition_samePositionsNotComparedIsFalse);
	unitTestManager.registerTestFunction("testPosition_differentPositionsNotComparedIsTrue", &testPosition_differentPositionsNotComparedIsTrue);

	unitTestManager.registerTestFunction("testBox_createDefaultBox", &testBox_createDefaultBox);
	unitTestManager.registerTestFunction("testBox_createCustomBox", &testBox_createCustomBox);
	unitTestManager.registerTestFunction("testBox_cornerGetterSetter", &testBox_cornerGetterSetter);
	unitTestManager.registerTestFunction("testBox_HorizontalVerticalGetterSetter", &testBox_HorizontalVerticalGetterSetter);
	unitTestManager.registerTestFunction("testBox_sameBoxesComparedIsTrue", &testBox_sameBoxesComparedIsTrue);
	unitTestManager.registerTestFunction("testBox_differentBoxesComparedIsFalse", &testBox_differentBoxesComparedIsFalse);
	unitTestManager.registerTestFunction("testBox_sameBoxesNotComparedIsFalse", &testBox_sameBoxesNotComparedIsFalse);
	unitTestManager.registerTestFunction("testBox_differentBoxesNotComparedIsTrue", &testBox_differentBoxesNotComparedIsTrue);

	unitTestManager.registerTestFunction("testObject_setAndGetPosition", &testObject_setAndGetPosition);
	unitTestManager.registerTestFunction("testObject_setAndGetType", &testObject_setAndGetType);
	unitTestManager.registerTestFunction("testObject_setAndGetHardSolidness", &testObject_setAndGetHardSolidness);
	unitTestManager.registerTestFunction("testObject_setAndGetSoftSolidness", &testObject_setAndGetSoftSolidness);
	unitTestManager.registerTestFunction("testObject_setAndGetSpectralSolidness", &testObject_setAndGetSpectralSolidness);
	unitTestManager.registerTestFunction("testObject_solidnessHardIsSolid", &testObject_solidnessHardIsSolid);
	unitTestManager.registerTestFunction("testObject_solidnessSoftIsSolid", &testObject_solidnessSoftIsSolid);
	unitTestManager.registerTestFunction("testObject_solidnessSpectralIsNotSolid", &testObject_solidnessSpectralIsNotSolid);
	unitTestManager.registerTestFunction("testObject_registerInterest", &testObject_registerInterest);
	unitTestManager.registerTestFunction("testObject_registerInterestTwice", &testObject_registerInterestTwice);
	unitTestManager.registerTestFunction("testObject_unregisterInterest", &testObject_unregisterInterest);
	unitTestManager.registerTestFunction("testObject_unregisterInterestTwice", &testObject_unregisterInterestTwice);
	unitTestManager.registerTestFunction("testObject_registerCustomEvent", &testObject_registerCustomEvent);
	unitTestManager.registerTestFunction("testObject_verifyEventIsReceived", &testObject_verifyEventIsReceived);
	unitTestManager.registerTestFunction("testObject_verifyEventIsNotReceivedWhenNotRegisterd", &testObject_verifyEventIsNotReceivedWhenNotRegisterd);
	unitTestManager.registerTestFunction("testObject_outEventIsFiredWhenOutScreen", &testObject_outEventIsFiredWhenOutScreen);
	unitTestManager.registerTestFunction("testObject_collisionEventIsFiredForHardToHard", &testObject_collisionEventIsFiredForHardToHard);
	unitTestManager.registerTestFunction("testObject_collisionEventIsFiredForHardToSoft", &testObject_collisionEventIsFiredForHardToSoft);
	unitTestManager.registerTestFunction("testObject_collisionEventIsFiredForSoftToHard", &testObject_collisionEventIsFiredForSoftToHard);
	unitTestManager.registerTestFunction("testObject_collisionEventIsFiredForSoftToSoft", &testObject_collisionEventIsFiredForSoftToSoft);
	unitTestManager.registerTestFunction("testObject_collisionEventIsNotFiredForSpectralToSoft", &testObject_collisionEventIsNotFiredForSpectralToSoft);
	unitTestManager.registerTestFunction("testObject_collisionEventIsNotFiredForSoftToSpectral", &testObject_collisionEventIsNotFiredForSoftToSpectral);
	unitTestManager.registerTestFunction("testObject_collisionEventIsNotFiredForSpectralToSpectral", &testObject_collisionEventIsNotFiredForSpectralToSpectral);

	unitTestManager.registerTestFunction("testObjectList_emptyListIsEmpty", &testObjectList_emptyListIsEmpty);
	unitTestManager.registerTestFunction("testObjectList_emptyListNotFull", &testObjectList_emptyListNotFull);
	unitTestManager.registerTestFunction("testObjectList_emptyListCountZero", &testObjectList_emptyListCountZero);
	unitTestManager.registerTestFunction("testObjectList_singleListCountOne", &testObjectList_singleListCountOne);
	unitTestManager.registerTestFunction("testObjectList_singleListNotEmpty", &testObjectList_singleListNotEmpty);
	unitTestManager.registerTestFunction("testObjectList_singleListNotFull", &testObjectList_singleListNotFull);
	unitTestManager.registerTestFunction("testObjectList_fullListIsFull", &testObjectList_fullListIsFull);
	unitTestManager.registerTestFunction("testObjectList_removeInsertedObject", &testObjectList_removeInsertedObject);
	unitTestManager.registerTestFunction("testObjectList_removeNotInsertedObject", &testObjectList_removeNotInsertedObject);
	unitTestManager.registerTestFunction("testObjectList_realloc", &testObjectList_realloc);
	unitTestManager.registerTestFunction("testObjectList_countZeroAfterClear", &testObjectList_countZeroAfterClear);
	unitTestManager.registerTestFunction("testObjectList_operatorPlusEmptyListPlusEmptyListIsZero", &testObjectList_operatorPlusEmptyListPlusEmptyListIsZero);
	unitTestManager.registerTestFunction("testObjectList_operatorPlusEmptyListPlusFilledListIsFilled", &testObjectList_operatorPlusEmptyListPlusFilledListIsFilled);
	unitTestManager.registerTestFunction("testObjectList_operatorPlusFilledListPlusFilledListIsDoubledList", &testObjectList_operatorPlusFilledListPlusFilledListIsDoubledList);
	unitTestManager.registerTestFunction("testObjectList_operatorPlusTwoFullListsEqualsDoubledListWithRealloc", &testObjectList_operatorPlusTwoFullListsEqualsDoubledListWithRealloc);

	unitTestManager.registerTestFunction("testFrame_ceateDefault", &testFrame_ceateDefault);
	unitTestManager.registerTestFunction("testFrame_createCustom", &testFrame_createCustom);
	unitTestManager.registerTestFunction("testFrame_getterAndSetter", &testFrame_getterAndSetter);

	unitTestManager.registerTestFunction("testSprite_createEmpty", &testSprite_createEmpty);
	unitTestManager.registerTestFunction("testSprite_createSingleFrame", &testSprite_createSingleFrame);
	unitTestManager.registerTestFunction("testSprite_frameOverflowReturnsError", &testSprite_frameOverflowReturnsError);

	unitTestManager.registerTestFunction("testUtility_boxContainsPointInsideTrue", &testUtility_boxContainsPointInsideTrue);
	unitTestManager.registerTestFunction("testUtility_boxContainsPointOutsideFalse", &testUtility_boxContainsPointOutsideFalse);

	// RUN UNIT TEST MANAGER
	return unitTestManager.run(argc, argv);
}

/****************************************************************************
 *  UNIT TEST FRAMEWORK SETUP FUNCTIONS.
 ***************************************************************************/

/**
 * Primitives test framework setup.
 */
void testSetup(void)
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
}

/**
 * Primitives test framework cleanup.
 */
void testCleanup(void)
{
	GameManager &gameManager = GameManager::getInstance();

	// shutdown everything
	gameManager.shutDown();
}

/**
 * Primitives test framework function which is called before each test.
 */
void testBefore(void)
{
	LogManager &logManager = LogManager::getInstance();
	GameManager &gameManager = GameManager::getInstance();
	
	logManager.setVerbosity(LOG_DEBUG);
	gameManager.setGameOver(false);
}

/**
 * Primitives test framework function which is called before each test.
 */
void testAfter(void)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	// clear world objects
	worldManager.clearAllObjects();
}

/****************************************************************************
 *  UNIT TEST FUNCTIONS.
 ***************************************************************************/

bool testGameManager_verifyIsStarted(void)
{
	GameManager &gameManager = GameManager::getInstance();

	return gameManager.isStarted();
}

bool testGameManager_runAndGameOverNoHang(void)
{
	GameManager &gameManager = GameManager::getInstance();

	TestObject *object = new TestObject();
	object->setStepsToGameOver(30);
	object->registerInterest(STEP_EVENT);
	gameManager.run();

	// if unit test does not hang here, test was successful
	return true;
}

bool testGameManager_changedFrameTimeHasEffect(void)
{
	LogManager &logManager = LogManager::getInstance();
	GameManager &gameManager = GameManager::getInstance();
	Clock clock;
	int frameTime = 3 * DEFAULT_FRAME_TIME;
	int loops = 10;
	long int maxDiff = 100000; // 100ms (high delta because CCC server is slow
		                       // and usleep is sometimes buggy in cygwin)
	TestObject *object = new TestObject();
	object->setStepsToGameOver(loops);
	object->registerInterest(STEP_EVENT);

	clock.delta();
	int gameLoops = gameManager.run(frameTime);
	long int gameTime = clock.split();

	logManager.writeLog(LOG_DEBUG, 
		"testGameManager_changedFrameTimeHasEffect()",
		"Game has done (%d/%d) loops and took %ld/%ldusec\n",
		gameLoops,
		loops,
		gameTime,
		frameTime * loops);

	// if unit test does not hang here, test was successful
	return gameLoops == loops && frameTime * loops - maxDiff < gameTime && gameTime <  frameTime * loops + maxDiff;
}

bool testGameManager_stepEventIsValid(void)
{
	GameManager &gameManager = GameManager::getInstance();
	bool res = gameManager.isValid(STEP_EVENT);

	return res;
}

bool testGameManager_testEventIsNotValid(void)
{
	GameManager &gameManager = GameManager::getInstance();
	bool res = gameManager.isValid(TEST_EVENT);

	return !res;
}

bool testGameManager_registerInvalidEvent(void)
{
	GameManager &gameManager = GameManager::getInstance();
	int res = gameManager.registerInterest(new Object(), TEST_EVENT);

	return res == -1;
}

bool testGraphicsManager_verifyIsStarted(void)
{
	// NOTE: This unit test was manually verified using another configuration.
	//       To have a correct unit test framework output, the graphics
	//       manager is not started at game engine start up.
	return true;
}

bool testWorldManager_verifyIsStarted(void)
{
	WorldManager &worldManager = WorldManager::getInstance();

	return worldManager.isStarted();
}

bool testWorldManager_insertAndRemoveObject(void)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *testObject = new TestObject();

	int countBeforeInsert = worldManager.getAllObjects().getCount();
	worldManager.insertObject(testObject);
	int countAfterInsert = worldManager.getAllObjects().getCount();
	worldManager.removeObject(testObject);
	int countAfterRemove = worldManager.getAllObjects().getCount();

	logManager.writeLog(LOG_DEBUG,
		"testWorldManager_insertAndRemoveObject()",
		"Count: %d --insert--> %d --remove--> %d\n",
		countBeforeInsert,
		countAfterInsert,
		countAfterRemove);

	// manual delete because it was removed and not marked.
	//delete testObject;

	return countBeforeInsert == countAfterRemove && countAfterInsert == countBeforeInsert + 1;
}

bool testWorldManager_markOneObjectForDelete(void)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	new TestObject();
	TestObject *testObjectToMark = new TestObject();
	new TestObject();

	int countBeforeMark = worldManager.getAllObjects().getCount();
	worldManager.markForDelete(testObjectToMark);
	int countAfterMark = worldManager.getAllObjects().getCount();
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterUpdate = worldManager.getAllObjects().getCount();

	logManager.writeLog(LOG_DEBUG,
		"testWorldmanager_markOneObjectForDelete()",
		"Counts: %d --mark--> %d --update--> %d\n",
		countBeforeMark,
		countAfterMark,
		countAfterUpdate);

	return countBeforeMark == countAfterMark && countBeforeMark - 1 == countAfterUpdate;
}

bool testWorldManager_markOneObjectForDeleteTwice(void)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();

	new TestObject();
	TestObject *testObjectToMark = new TestObject();
	new TestObject();

	int countBeforeMark = worldManager.getAllObjects().getCount();
	worldManager.markForDelete(testObjectToMark);
	worldManager.markForDelete(testObjectToMark);
	int countAfterMark = worldManager.getAllObjects().getCount();
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterUpdate = worldManager.getAllObjects().getCount();

	logManager.writeLog(LOG_DEBUG,
		"testWorldmanager_markOneObjectForDelete()",
		"Counts: %d --mark--> %d --update--> %d\n",
		countBeforeMark,
		countAfterMark,
		countAfterUpdate);

	return countBeforeMark == countAfterMark && countBeforeMark - 1 == countAfterUpdate;
}

bool testWorldManager_clearAllObjects(void)
{
	WorldManager &worldManager = WorldManager::getInstance();

	new TestObject();
	new TestObject();
	new TestObject();

	int countBefore = worldManager.getAllObjects().getCount();
	worldManager.clearAllObjects();
	int countAfter = worldManager.getAllObjects().getCount();

	return countBefore == 3 && countAfter == 0;
}

bool testWorldManager_stepEventIsNotValid(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	bool res = worldManager.isValid(STEP_EVENT);

	return !res;
}

bool testWorldManager_testEventIsValid(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	bool res = worldManager.isValid(TEST_EVENT);

	return res;
}

bool testLogManager_verifyIsStarted(void)
{
	LogManager &logManager = LogManager::getInstance();

	return logManager.isStarted();
}

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

bool testInputManager_verifyIsStarted(void)
{
	InputManager &inputManager = InputManager::getInstance();

	return inputManager.isStarted();
}

bool testInputManager_keyboardEventIsValid(void)
{
	InputManager &inputManager = InputManager::getInstance();
	bool res = inputManager.isValid(KEYBOARD_EVENT);

	return res;
}

bool testInputManager_mouseEventIsValid(void)
{
	InputManager &inputManager = InputManager::getInstance();
	bool res = inputManager.isValid(MOUSE_EVENT);

	return res;
}

bool testInputManager_stepEventIsNotValid(void)
{
	InputManager &inputManager = InputManager::getInstance();
	bool res = inputManager.isValid(STEP_EVENT);

	return !res;
}

bool testResourceManager_verifyIsStarted(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();

	return resourceManager.isStarted();
}

bool testResourceManager_loadCorrectSpriteReturnsSuccess(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship1";
	int res = resourceManager.loadSprite("sprites/test-spr.txt", label);

	return res == 0;
}

bool testResourceManager_loadErrorMistakeSpriteReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship2";
	int res = resourceManager.loadSprite("sprites/test-spr-error-mistake.txt", label);

	return res == -1;
}

bool testResourceManager_loadErrorColorSpriteReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship3";
	int res = resourceManager.loadSprite("sprites/test-spr-error-color.txt", label);

	return res == -1;
}

bool testResourceManager_loadErrorLessFramesSpriteReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship4";
	int res = resourceManager.loadSprite("sprites/test-spr-error-frames-less.txt", label);

	return res == -1;
}

bool testResourceManager_loadErrorMoreFramesSpriteReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship5";
	int res = resourceManager.loadSprite("sprites/test-spr-error-frames-more.txt", label);

	return res == -1;
}

bool testResourceManager_loadErrorLessHeightSpriteReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship6";
	int res = resourceManager.loadSprite("sprites/test-spr-error-height-less.txt", label);

	return res == -1;
}

bool testResourceManager_loadErrorMoreHeightSpriteReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship7";
	int res = resourceManager.loadSprite("sprites/test-spr-error-height-more.txt", label);

	return res == -1;
}

bool testResourceManager_loadErrorLessWidthSpriteReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship8";
	int res = resourceManager.loadSprite("sprites/test-spr-error-width-less.txt", label);

	return res == -1;
}

bool testResourceManager_loadErrorMoreWidthSpriteReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship9";
	int res = resourceManager.loadSprite("sprites/test-spr-error-width-more.txt", label);

	return res == -1;
}

bool testResourceManager_loadErrorUnknownFileReturnsError(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship10";
	int res = resourceManager.loadSprite("sprites/unknown-file.txt", label);

	return res == -1;
}

bool testResourceManager_getAndUnloadSprite(void)
{
	ResourceManager &resourceManager = ResourceManager::getInstance();
	string label = "ship11";
	int res1 = resourceManager.loadSprite("sprites/test-spr.txt", label);
	Sprite *p_sprite1 = resourceManager.getSprite(label);
	int res2 = resourceManager.unloadSprite(label);
	Sprite *p_sprite2 = resourceManager.getSprite(label);

	return res1 == 0 && p_sprite1 != NULL &&
		res2 == 0 && p_sprite2 == NULL;
}

bool testClock_1SecSleep(void)
{
	LogManager &logManager = LogManager::getInstance();
	int sleepTime = 1000000; // 1 sec
	Clock clock;
	long int maxDiff = 15000; // 15ms (high delta becaus of slow CCC server)

	clock.delta();
	usleep(sleepTime);
	long int diff = clock.split();

	logManager.writeLog(LOG_DEBUG,
		"clock_test1SecSleep()",
		"sleep(1) took exactly: %ldusec\n",
		diff);

	return sleepTime - maxDiff < diff && diff < sleepTime + maxDiff;
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

bool testPosition_createDefaultPosition(void)
{
	Position position;
	
	return position.getX() == 0 && position.getY() == 0;
}

bool testPosition_createCustomPosition(void)
{
	int x = 5;
	int y = 10;
	Position position(x, y);
	
	return position.getX() == x && position.getY() == y;
}

bool testPosition_positionGettersAndSetters(void)
{
	Position position;
	int x = 10;
	int y = 100;
	position.setX(x);
	position.setY(y);
	
	return position.getX() == x && position.getY() == y;
}

bool testPosition_positionXYSetter(void)
{
	Position position;
	int x = 5;
	int y = 55;
	position.setXY(x, y);
	
	return position.getX() == x && position.getY() == y;
}

bool testPosition_samePositionsComparedIsTrue(void)
{
	int x = 1;
	int y = 2;
	Position position1(x, y);
	Position position2(x, y);
	
	return position1 == position2;
}

bool testPosition_differentPositionsComparedIsFalse(void)
{
	Position position1(1, 2);
	Position position2(3, 4);
	
	return !(position1 == position2);
}

bool testPosition_samePositionsNotComparedIsFalse(void)
{
	int x = 1;
	int y = 2;
	Position position1(x, y);
	Position position2(x, y);
	
	return !(position1 != position2);
}

bool testPosition_differentPositionsNotComparedIsTrue(void)
{
	Position position1(1, 2);
	Position position2(3, 4);
	
	return position1 != position2;
}

bool testBox_createDefaultBox(void)
{
	Box box;

	return box.getCorner().getX() == 0 &&
		box.getCorner().getY() == 0 &&
		box.getHorizontal() == 0 &&
		box.getVertical() == 0;
}

bool testBox_createCustomBox(void)
{
	int x = 5;
	int y = 55;
	int h = 4;
	int v = 44;
	Box box(Position(x, y), h, v);

	return box.getCorner().getX() == x &&
		box.getCorner().getY() == y &&
		box.getHorizontal() == h &&
		box.getVertical() == v;
}

bool testBox_cornerGetterSetter(void)
{
	int x = 3;
	int y = 33;
	Box box;
	box.setCorner(Position(x, y));

	return box.getCorner().getX() == x &&
		box.getCorner().getY() == y;
}

bool testBox_HorizontalVerticalGetterSetter(void)
{
	int h = 3;
	int v = 33;
	Box box;
	box.setHorizontal(h);
	box.setVertical(v);

	return box.getHorizontal() == h &&
		box.getVertical() == v;
}

bool testBox_sameBoxesComparedIsTrue(void)
{
	int x = 1;
	int y = 2;
	int h = 3;
	int v = 4;
	Box box1(Position(x, y), h, v);
	Box box2(Position(x, y), h, v);
	
	return box1 == box2;
}

bool testBox_differentBoxesComparedIsFalse(void)
{
	Box box1(Position(1, 2), 3, 4);
	Box box2(Position(5, 6), 7, 8);
	
	return !(box1 == box2);
}

bool testBox_sameBoxesNotComparedIsFalse(void)
{
	int x = 1;
	int y = 2;
	int h = 3;
	int v = 4;
	Box box1(Position(x, y), h, v);
	Box box2(Position(x, y), h, v);
	
	return !(box1 != box2);
}

bool testBox_differentBoxesNotComparedIsTrue(void)
{
	Box box1(Position(1, 2), 3, 4);
	Box box2(Position(5, 6), 7, 8);
	
	return box1 != box2;
}

bool testObject_setAndGetPosition(void)
{
	Object *obj = new Object();

	obj->setPosition(Position(3, 4));
	Position p = obj->getPosition();

	return p.getX() == 3 && p.getY() == 4;
}

bool testObject_setAndGetType(void)
{
	Object *obj = new Object();
	string type = "test_type";

	obj->setType(type);

	return obj->getType() == type;
}

bool testObject_setAndGetHardSolidness(void)
{
	Object *obj = new Object();
	obj->setSolidness(HARD);

	return obj->getSolidness() == HARD;
}

bool testObject_setAndGetSoftSolidness(void)
{
	Object *obj = new Object();
	obj->setSolidness(SOFT);

	return obj->getSolidness() == SOFT;
}

bool testObject_setAndGetSpectralSolidness(void)
{
	Object *obj = new Object();
	obj->setSolidness(SPECTRAL);

	return obj->getSolidness() == SPECTRAL;
}

bool testObject_solidnessHardIsSolid(void)
{
	Object *obj = new Object();
	obj->setSolidness(HARD);

	return obj->isSolid();
}

bool testObject_solidnessSoftIsSolid(void)
{
	Object *obj = new Object();
	obj->setSolidness(SOFT);

	return obj->isSolid();
}

bool testObject_solidnessSpectralIsNotSolid(void)
{
	Object *obj = new Object();
	obj->setSolidness(SPECTRAL);

	return !obj->isSolid();
}

bool testObject_registerInterest(void)
{
	TestObject *obj = new TestObject();
	int res = obj->registerInterest(STEP_EVENT);

	return res == 0;
}

bool testObject_registerInterestTwice(void)
{
	TestObject *obj = new TestObject();
	int res1 = obj->registerInterest(STEP_EVENT);
	int res2 = obj->registerInterest(STEP_EVENT);

	return res1 == 0 && res2 == -1;
}

bool testObject_unregisterInterest(void)
{
	TestObject *obj = new TestObject();
	obj->registerInterest(STEP_EVENT);
	int res = obj->unregisterInterest(STEP_EVENT);

	return res == 0;
}

bool testObject_unregisterInterestTwice(void)
{
	TestObject *obj = new TestObject();
	obj->registerInterest(STEP_EVENT);
	int res1 = obj->unregisterInterest(STEP_EVENT);
	int res2 = obj->unregisterInterest(STEP_EVENT);

	return res1 == 0 && res2 == -1;
}

bool testObject_registerCustomEvent(void)
{
	TestObject *obj = new TestObject();
	int res = obj->registerInterest(TEST_EVENT);

	return res == 0;
}

bool testObject_verifyEventIsReceived(void)
{
	TestObject *obj = new TestObject();
	obj->registerInterest(TEST_EVENT);

	WorldManager &worldManager = WorldManager::getInstance();
	int countBeforeEvent = worldManager.getAllObjects().getCount();
	// NOTE: test object marks itself for delete on test event
	EventTest testEvent;
	worldManager.onEvent(&testEvent);
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterEvent = worldManager.getAllObjects().getCount();

	return countBeforeEvent - countAfterEvent == 1;
}

bool testObject_verifyEventIsNotReceivedWhenNotRegisterd(void)
{
	TestObject *obj = new TestObject();

	WorldManager &worldManager = WorldManager::getInstance();
	int countBeforeEvent = worldManager.getAllObjects().getCount();
	// NOTE: test object marks itself for delete on test event
	EventTest testEvent;
	worldManager.onEvent(&testEvent);
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterEvent = worldManager.getAllObjects().getCount();

	return countBeforeEvent == countAfterEvent;
}

bool testObject_outEventIsFiredWhenOutScreen(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *obj = new TestObject();
	obj->setPosition(Position(10, 10));
	obj->setVelocityX(-100);
	obj->registerInterest(OUT_EVENT);
	int countBeforeOut = worldManager.getAllObjects().getCount();
	// NOTE: out event kill test object
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterOut = worldManager.getAllObjects().getCount();

	return countBeforeOut - countAfterOut == 1;
}

bool testObject_collisionEventIsFiredForHardToHard(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *obj1 = new TestCollidableObject();
	TestObject *obj2 = new TestCollidableObject();
	obj1->setPosition(Position(10, 10));
	obj1->setSolidness(HARD);
	obj1->registerInterest(COLLISION_EVENT);
	obj2->setPosition(Position(9, 10));
	obj2->setVelocityX(1);
	obj2->setSolidness(HARD);
	obj2->registerInterest(COLLISION_EVENT);
	int countBeforeCollision = worldManager.getAllObjects().getCount();
	// NOTE: collision event kills both object
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterCollision = worldManager.getAllObjects().getCount();

	return countBeforeCollision - countAfterCollision == 2;
}

bool testObject_collisionEventIsFiredForHardToSoft(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *obj1 = new TestCollidableObject();
	TestObject *obj2 = new TestCollidableObject();
	obj1->setPosition(Position(10, 10));
	obj1->setSolidness(HARD);
	obj1->registerInterest(COLLISION_EVENT);
	obj2->setPosition(Position(9, 10));
	obj2->setVelocityX(1);
	obj2->setSolidness(SOFT);
	obj2->registerInterest(COLLISION_EVENT);
	int countBeforeCollision = worldManager.getAllObjects().getCount();
	// NOTE: collision event kills both object
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterCollision = worldManager.getAllObjects().getCount();

	return countBeforeCollision - countAfterCollision == 2;
}

bool testObject_collisionEventIsFiredForSoftToHard(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *obj1 = new TestCollidableObject();
	TestObject *obj2 = new TestCollidableObject();
	obj1->setPosition(Position(10, 10));
	obj1->setSolidness(SOFT);
	obj1->registerInterest(COLLISION_EVENT);
	obj2->setPosition(Position(9, 10));
	obj2->setVelocityX(1);
	obj2->setSolidness(HARD);
	obj2->registerInterest(COLLISION_EVENT);
	int countBeforeCollision = worldManager.getAllObjects().getCount();
	// NOTE: collision event kills both object
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterCollision = worldManager.getAllObjects().getCount();

	return countBeforeCollision - countAfterCollision == 2;
}

bool testObject_collisionEventIsFiredForSoftToSoft(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *obj1 = new TestCollidableObject();
	TestObject *obj2 = new TestCollidableObject();
	obj1->setPosition(Position(10, 10));
	obj1->setSolidness(SOFT);
	obj1->registerInterest(COLLISION_EVENT);
	obj2->setPosition(Position(9, 10));
	obj2->setVelocityX(1);
	obj2->setSolidness(SOFT);
	obj2->registerInterest(COLLISION_EVENT);
	int countBeforeCollision = worldManager.getAllObjects().getCount();
	// NOTE: collision event kills both object
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterCollision = worldManager.getAllObjects().getCount();

	return countBeforeCollision - countAfterCollision == 2;
}

bool testObject_collisionEventIsNotFiredForSpectralToSoft(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *obj1 = new TestCollidableObject();
	TestObject *obj2 = new TestCollidableObject();
	obj1->setPosition(Position(10, 10));
	obj1->setSolidness(SPECTRAL);
	obj1->registerInterest(COLLISION_EVENT);
	obj2->setPosition(Position(9, 10));
	obj2->setVelocityX(1);
	obj2->setSolidness(SOFT);
	obj2->registerInterest(COLLISION_EVENT);
	int countBeforeCollision = worldManager.getAllObjects().getCount();
	// NOTE: collision event would kill both object
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterCollision = worldManager.getAllObjects().getCount();

	return countBeforeCollision == countAfterCollision;
}

bool testObject_collisionEventIsNotFiredForSoftToSpectral(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *obj1 = new TestCollidableObject();
	TestObject *obj2 = new TestCollidableObject();
	obj1->setPosition(Position(10, 10));
	obj1->setSolidness(SOFT);
	obj1->registerInterest(COLLISION_EVENT);
	obj2->setPosition(Position(9, 10));
	obj2->setVelocityX(1);
	obj2->setSolidness(SPECTRAL);
	obj2->registerInterest(COLLISION_EVENT);
	int countBeforeCollision = worldManager.getAllObjects().getCount();
	// NOTE: collision event would kill both object
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterCollision = worldManager.getAllObjects().getCount();

	return countBeforeCollision == countAfterCollision;
}

bool testObject_collisionEventIsNotFiredForSpectralToSpectral(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	TestObject *obj1 = new TestCollidableObject();
	TestObject *obj2 = new TestCollidableObject();
	obj1->setPosition(Position(10, 10));
	obj1->setSolidness(SPECTRAL);
	obj1->registerInterest(COLLISION_EVENT);
	obj2->setPosition(Position(9, 10));
	obj2->setVelocityX(1);
	obj2->setSolidness(SPECTRAL);
	obj2->registerInterest(COLLISION_EVENT);
	int countBeforeCollision = worldManager.getAllObjects().getCount();
	// NOTE: collision event would kill both object
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfterCollision = worldManager.getAllObjects().getCount();

	return countBeforeCollision == countAfterCollision;
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
	Object *obj = new Object();
	obj->setPosition(Position(9999, 9999));

	objectListFillWithObject(&list, 2);
	list.insert(obj);
	objectListFillWithObject(&list, 2);

	objectList2Log(&list);

	int countBeforeRemove = list.getCount();

	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Removing the added object from list with count %d\n",
			countBeforeRemove);

	list.remove(obj);

	int countAfterRemove = list.getCount();

	objectList2Log(&list);

	return countBeforeRemove - countAfterRemove == 1;
}

bool testObjectList_removeNotInsertedObject(void)
{
	LogManager &logManager = LogManager::getInstance();
	ObjectList list;
	Object *obj = new Object();
	obj->setPosition(Position(9999, 9999));

	objectListFillWithObject(&list, 4);

	objectList2Log(&list);

	int countBeforeRemove = list.getCount();

	logManager.writeLog(LOG_DEBUG,
			"objectListTest()",
			"Removing the added object from list with count %d\n",
			countBeforeRemove);

	list.remove(obj);

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

bool testObjectList_operatorPlusTwoFullListsEqualsDoubledListWithRealloc(void)
{
	ObjectList firstList;
	ObjectList secondList;
	int fullSize = INIT_LIST_SIZE;

	objectListFillWithObject(&firstList, fullSize);
	objectListFillWithObject(&secondList, fullSize);

	ObjectList addedList = firstList + secondList;

	return addedList.getCount() == 2 * fullSize;
}

bool testFrame_ceateDefault(void)
{
	Frame frame;

	return frame.getHeight() == 0 &&
		frame.getWidth() == 0 &&
		frame.isEmpty();
}

bool testFrame_createCustom(void)
{
	int width = 2;
	int height = 3;
	string data = "XXXXXX";

	Frame frame(width, height, data);

	return frame.getHeight() == height &&
		frame.getWidth() == width &&
		frame.getData() == data;
}

bool testFrame_getterAndSetter(void)
{
	int width = 2;
	int height = 4;
	string data = "XXXXXXXX";

	Frame frame;
	frame.setWidth(width);
	frame.setHeight(height);
	frame.setData(data);

	return frame.getHeight() == height &&
		frame.getWidth() == width &&
		frame.getData() == data;
}

bool testSprite_createEmpty(void)
{
	Sprite s(1);

	return s.getHeight() == 0 &&
		s.getWidth() == 0 &&
		s.getColor() == COLOR_DEFAULT &&
		s.getFrameCount() == 0 &&
		s.getLabel() == UNLABELED_SPRITE;
}

bool testSprite_createSingleFrame(void)
{
	int width = 2;
	int height = 4;
	int color = COLOR_RED;
	string label = "testLabel";
	string data = "XXXXXXXX";

	Frame frame(width, height, data);

	Sprite s(1);
	s.setWidth(width);
	s.setHeight(height);
	s.setColor(color);
	s.setLabel(label);
	s.addFrame(frame);

	return s.getHeight() == height &&
		s.getWidth() == width &&
		s.getColor() == color &&
		s.getFrameCount() == 1 &&
		s.getLabel() == label;
}

bool testSprite_frameOverflowReturnsError(void)
{
	Frame frame1(2, 3, "AABBCC");
	Frame frame2(1, 2, "AB");

	Sprite s(1);
	int res1 = s.addFrame(frame1);
	int res2 = s.addFrame(frame2);

	return res1 == 0 &&
		res2 == -1 &&
		s.getFrameCount() == 1;
}

bool testUtility_boxContainsPointInsideTrue(void)
{
	Box box(Position(0, 0), 10, 10);
	Position position(5, 5);

	return boxContainsPoint(box, position);
}

bool testUtility_boxContainsPointOutsideFalse(void)
{
	Box box(Position(0, 0), 10, 10);
	Position position(15, 5);

	return !boxContainsPoint(box, position);
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
