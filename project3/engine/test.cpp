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
#include "EventView.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "EventOut.h"
#include "EventCollision.h"
#include "Frame.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "ViewObject.h"
#include "SceneGraph.h"
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
bool testGameManager_registerInvalidEvent(void);
bool testGraphicsManager_verifyIsStarted(void);
bool testWorldManager_markOneObjectForDelete(void);
bool testWorldManager_markOneObjectForDeleteTwice(void);
bool testWorldManager_clearAllObjects(void);
bool testWorldManager_verifyIsStarted(void);
bool testWorldManager_insertAndRemoveObject(void);
bool testWorldManager_stepEventIsNotValid(void);
bool testWorldManager_testEventIsValid(void);
bool testWorldManager_checkDefaultLevel(void);
bool testWorldManager_setLevelShouldNotChangeWithoutUpdate(void);
bool testWorldManager_setLevelShouldChangeAfterUpdate(void);
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
bool testCircle_createDefaultCircle(void);
bool testCircle_createCustomCircle(void);
bool testCircle_centerGetterSetter(void);
bool testCircle_radiusGetterSetter(void);
bool testCircle_sameCirclesComparedIsTrue(void);
bool testCircle_differentCirclesComparedIsFalse(void);
bool testCircle_sameCirclesNotComparedIsFalse(void);
bool testCircle_differentCirclesNotComparedIsTrue(void);
bool testLine_createDefaultLine(void);
bool testLine_createCustomLine(void);
bool testLine_positionGetterSetter(void);
bool testLine_sameLinesComparedIsTrue(void);
bool testLine_differentLinesComparedIsFalse(void);
bool testLine_sameLinesNotComparedIsFalse(void);
bool testLine_differentLinesNotComparedIsTrue(void);
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
bool testObject_updateVisiblilty(void);
bool testObject_updatePersistence(void);
bool testObject_updateSolidness(void);
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
bool testSceneGraph_createDefault(void);
bool testSceneGraph_insertAndRemoveOneSolidObject(void);
bool testSceneGraph_insertAndRemoveOneNonSolidObject(void);
bool testSceneGraph_insertAndRemoveMultipleMixedObject(void);
bool testSceneGraph_insertAndRemoveWithLevelChange(void);
bool testFrame_ceateDefault(void);
bool testFrame_createCustom(void);
bool testFrame_getterAndSetter(void);
bool testSprite_createEmpty(void);
bool testSprite_createSingleFrame(void);
bool testSprite_frameOverflowReturnsError(void);
bool testViewObject_ceateDefault();
bool testViewObject_ceateRegistersToWorldManager();
bool testViewObject_setAndGetBorder();
bool testViewObject_setAndGetViewString();
bool testViewObject_setAndGetValue();
bool testViewObject_viewEventChangeValue();
bool testViewObject_viewEventReplaceValue();
bool testUtility_positionIntersectOverlappingTrue(void);
bool testUtility_positionIntersectNoOverlappingLeftFalse(void);
bool testUtility_positionIntersectNoOverlappingRightFalse(void);
bool testUtility_positionIntersectNoOverlappingTopFalse(void);
bool testUtility_positionIntersectNoOverlappingBottomFalse(void);
bool testUtility_boxIntersectsBoxOverlappingTrue(void);
bool testUtility_boxIntersectsBoxEmptyOverlappingTrue(void);
bool testUtility_boxIntersectsBoxNoOverlappingLeftFalse(void);
bool testUtility_boxIntersectsBoxNoOverlappingRightFalse(void);
bool testUtility_boxIntersectsBoxNoOverlappingTopFalse(void);
bool testUtility_boxIntersectsBoxNoOverlappingBottomFalse(void);
bool testUtility_boxContainsPointInsideTrue(void);
bool testUtility_boxContainsPointOutsideFalse(void);
bool testUtility_valueInRangeInsideTrue(void);
bool testUtility_valueInRangeOnLowerBorderTrue(void);
bool testUtility_valueInRangeOnHigherBorderTrue(void);
bool testUtility_valueInRangeOutsideFalse(void);
bool testUtility_clipValueInside(void);
bool testUtility_clipValueOnLowerBorder(void);
bool testUtility_clipValueOnHigherBorder(void);
bool testUtility_clipValueOutside(void);
bool testUtility_getWorldBoxObjectOriginObject(void);
bool testUtility_getWorldBoxObjectMovedObject(void);
bool testUtility_getWorldBoxObjectOriginObjectMovedBox(void);
bool testUtility_getWorldBoxObjectMovedObjectMovedBox(void);
bool testUtility_getWorldBoxObjectOriginObjectNotCentered(void);
bool testUtility_getWorldBoxObjectMovedObjectNotCentered(void);
bool testUtility_getWorldBoxObjectOriginObjectMovedBoxNotCentered(void);
bool testUtility_getWorldBoxObjectMovedObjectMovedBoxNotCentered(void);
bool testUtility_lineIntersectsLineOverlappingTrue(void);
bool testUtility_lineIntersectsLineDiagonalOverlappingTrue(void);
bool testUtility_lineIntersectsLineParallelOverlappingFalse(void);
bool testUtility_lineIntersectsLineNotOverlappingFalse(void);
bool testUtility_lineIntersectsBoxBothInsideTrue(void);
bool testUtility_lineIntersectsBoxInAndOutsideTrue(void);
bool testUtility_lineIntersectsBoxBothOutsideDiagonalCrossTrue(void);
bool testUtility_lineIntersectsBoxBothOutsideDiagonalNotCrossFalse(void);
bool testUtility_lineIntersectsBoxBothOutsideNotCrossFalse(void);
bool testUtility_circleIntersectsBoxInsideTrue(void);
bool testUtility_circleIntersectsBoxSideOverlappingTrue(void);
bool testUtility_circleIntersectsBoxEdgeOverlappingTrue(void);
bool testUtility_circleIntersectsBoxEdgeNotOverlappingFalse(void);
bool testUtility_circleIntersectsBoxOutsideFalse(void);
bool testUtility_circleIntersectsCircleInsideTrue(void);
bool testUtility_circleIntersectsCircleOutsideOverlappingTrue(void);
bool testUtility_circleIntersectsCircleOutsideNotOverlappingFalse(void);
bool testUtility_distanceZero(void);
bool testUtility_distanceSqrt2(void);
bool testUtility_distanceSquaredZero(void);
bool testUtility_distanceSquared2(void);
bool testUtility_intToStringZero(void);
bool testUtility_intToStringPositive(void);
bool testUtility_intToStringNegative(void);

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
	unitTestManager.registerTestFunction("testWorldManager_checkDefaultLevel", &testWorldManager_checkDefaultLevel);
	unitTestManager.registerTestFunction("testWorldManager_setLevelShouldNotChangeWithoutUpdate", &testWorldManager_setLevelShouldNotChangeWithoutUpdate);
	unitTestManager.registerTestFunction("testWorldManager_setLevelShouldChangeAfterUpdate", &testWorldManager_setLevelShouldChangeAfterUpdate);

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

	unitTestManager.registerTestFunction("testCircle_createDefaultCircle", &testCircle_createDefaultCircle);
	unitTestManager.registerTestFunction("testCircle_createCustomCircle", &testCircle_createCustomCircle);
	unitTestManager.registerTestFunction("testCircle_centerGetterSetter", &testCircle_centerGetterSetter);
	unitTestManager.registerTestFunction("testCircle_radiusGetterSetter", &testCircle_radiusGetterSetter);
	unitTestManager.registerTestFunction("testCircle_sameCirclesComparedIsTrue", &testCircle_sameCirclesComparedIsTrue);
	unitTestManager.registerTestFunction("testCircle_differentCirclesComparedIsFalse", &testCircle_differentCirclesComparedIsFalse);
	unitTestManager.registerTestFunction("testCircle_sameCirclesNotComparedIsFalse", &testCircle_sameCirclesNotComparedIsFalse);
	unitTestManager.registerTestFunction("testCircle_differentCirclesNotComparedIsTrue", &testCircle_differentCirclesNotComparedIsTrue);

	unitTestManager.registerTestFunction("testLine_createDefaultLine", &testLine_createDefaultLine);
	unitTestManager.registerTestFunction("testLine_createCustomLine", &testLine_createCustomLine);
	unitTestManager.registerTestFunction("testLine_positionGetterSetter", &testLine_positionGetterSetter);
	unitTestManager.registerTestFunction("testLine_sameLinesComparedIsTrue", &testLine_sameLinesComparedIsTrue);
	unitTestManager.registerTestFunction("testLine_differentLinesComparedIsFalse", &testLine_differentLinesComparedIsFalse);
	unitTestManager.registerTestFunction("testLine_sameLinesNotComparedIsFalse", &testLine_sameLinesNotComparedIsFalse);
	unitTestManager.registerTestFunction("testLine_differentLinesNotComparedIsTrue", &testLine_differentLinesNotComparedIsTrue);

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
	unitTestManager.registerTestFunction("testObject_updateVisiblilty", &testObject_updateVisiblilty);
	unitTestManager.registerTestFunction("testObject_updatePersistence", &testObject_updatePersistence);
	unitTestManager.registerTestFunction("testObject_updateSolidness", &testObject_updateSolidness);

	unitTestManager.registerTestFunction("testSceneGraph_createDefault", &testSceneGraph_createDefault);
	unitTestManager.registerTestFunction("testSceneGraph_insertAndRemoveOneSolidObject", &testSceneGraph_insertAndRemoveOneSolidObject);
	unitTestManager.registerTestFunction("testSceneGraph_insertAndRemoveOneNonSolidObject", &testSceneGraph_insertAndRemoveOneNonSolidObject);
	unitTestManager.registerTestFunction("testSceneGraph_insertAndRemoveMultipleMixedObject", &testSceneGraph_insertAndRemoveMultipleMixedObject);
	unitTestManager.registerTestFunction("testSceneGraph_insertAndRemoveWithLevelChange", &testSceneGraph_insertAndRemoveWithLevelChange);

	unitTestManager.registerTestFunction("testFrame_ceateDefault", &testFrame_ceateDefault);
	unitTestManager.registerTestFunction("testFrame_createCustom", &testFrame_createCustom);
	unitTestManager.registerTestFunction("testFrame_getterAndSetter", &testFrame_getterAndSetter);

	unitTestManager.registerTestFunction("testSprite_createEmpty", &testSprite_createEmpty);
	unitTestManager.registerTestFunction("testSprite_createSingleFrame", &testSprite_createSingleFrame);
	unitTestManager.registerTestFunction("testSprite_frameOverflowReturnsError", &testSprite_frameOverflowReturnsError);

	unitTestManager.registerTestFunction("testViewObject_ceateRegistersToWorldManager", &testViewObject_ceateRegistersToWorldManager);
	unitTestManager.registerTestFunction("testViewObject_setAndGetBorder", &testViewObject_setAndGetBorder);
	unitTestManager.registerTestFunction("testViewObject_setAndGetViewString", &testViewObject_setAndGetViewString);
	unitTestManager.registerTestFunction("testViewObject_setAndGetValue", &testViewObject_setAndGetValue);
	unitTestManager.registerTestFunction("testViewObject_viewEventChangeValue", &testViewObject_viewEventChangeValue);
	unitTestManager.registerTestFunction("testViewObject_viewEventReplaceValue", &testViewObject_viewEventReplaceValue);

	unitTestManager.registerTestFunction("testUtility_positionIntersectOverlappingTrue", &testUtility_positionIntersectOverlappingTrue);
	unitTestManager.registerTestFunction("testUtility_positionIntersectNoOverlappingLeftFalse", &testUtility_positionIntersectNoOverlappingLeftFalse);
	unitTestManager.registerTestFunction("testUtility_positionIntersectNoOverlappingRightFalse", &testUtility_positionIntersectNoOverlappingRightFalse);
	unitTestManager.registerTestFunction("testUtility_positionIntersectNoOverlappingTopFalse", &testUtility_positionIntersectNoOverlappingTopFalse);
	unitTestManager.registerTestFunction("testUtility_positionIntersectNoOverlappingBottomFalse", &testUtility_positionIntersectNoOverlappingBottomFalse);
	unitTestManager.registerTestFunction("testUtility_boxIntersectsBoxOverlappingTrue", &testUtility_boxIntersectsBoxOverlappingTrue);
	unitTestManager.registerTestFunction("testUtility_boxIntersectsBoxEmptyOverlappingTrue", &testUtility_boxIntersectsBoxEmptyOverlappingTrue);
	unitTestManager.registerTestFunction("testUtility_boxIntersectsBoxNoOverlappingLeftFalse", &testUtility_boxIntersectsBoxNoOverlappingLeftFalse);
	unitTestManager.registerTestFunction("testUtility_boxIntersectsBoxNoOverlappingRightFalse", &testUtility_boxIntersectsBoxNoOverlappingRightFalse);
	unitTestManager.registerTestFunction("testUtility_boxIntersectsBoxNoOverlappingTopFalse", &testUtility_boxIntersectsBoxNoOverlappingTopFalse);
	unitTestManager.registerTestFunction("testUtility_boxIntersectsBoxNoOverlappingBottomFalse", &testUtility_boxIntersectsBoxNoOverlappingBottomFalse);
	unitTestManager.registerTestFunction("testUtility_boxContainsPointInsideTrue", &testUtility_boxContainsPointInsideTrue);
	unitTestManager.registerTestFunction("testUtility_boxContainsPointOutsideFalse", &testUtility_boxContainsPointOutsideFalse);
	unitTestManager.registerTestFunction("testUtility_valueInRangeInsideTrue", &testUtility_valueInRangeInsideTrue);
	unitTestManager.registerTestFunction("testUtility_valueInRangeOnLowerBorderTrue", &testUtility_valueInRangeOnLowerBorderTrue);
	unitTestManager.registerTestFunction("testUtility_valueInRangeOnHigherBorderTrue", &testUtility_valueInRangeOnHigherBorderTrue);
	unitTestManager.registerTestFunction("testUtility_valueInRangeOutsideFalse", &testUtility_valueInRangeOutsideFalse);
	unitTestManager.registerTestFunction("testUtility_clipValueInside", &testUtility_clipValueInside);
	unitTestManager.registerTestFunction("testUtility_clipValueOnLowerBorder", &testUtility_clipValueOnLowerBorder);
	unitTestManager.registerTestFunction("testUtility_clipValueOnHigherBorder", &testUtility_clipValueOnHigherBorder);
	unitTestManager.registerTestFunction("testUtility_clipValueOutside", &testUtility_clipValueOutside);
	unitTestManager.registerTestFunction("testUtility_getWorldBoxObjectOriginObject", &testUtility_getWorldBoxObjectOriginObject);
	unitTestManager.registerTestFunction("testUtility_getWorldBoxObjectMovedObject", &testUtility_getWorldBoxObjectMovedObject);
	unitTestManager.registerTestFunction("testUtility_getWorldBoxObjectOriginObjectMovedBox", &testUtility_getWorldBoxObjectOriginObjectMovedBox);
	unitTestManager.registerTestFunction("testUtility_getWorldBoxObjectMovedObjectMovedBox", &testUtility_getWorldBoxObjectMovedObjectMovedBox);
	unitTestManager.registerTestFunction("testUtility_getWorldBoxObjectOriginObjectNotCentered", &testUtility_getWorldBoxObjectOriginObjectNotCentered);
	unitTestManager.registerTestFunction("testUtility_getWorldBoxObjectMovedObjectNotCentered", &testUtility_getWorldBoxObjectMovedObjectNotCentered);
	unitTestManager.registerTestFunction("testUtility_getWorldBoxObjectOriginObjectMovedBoxNotCentered", &testUtility_getWorldBoxObjectOriginObjectMovedBoxNotCentered);
	unitTestManager.registerTestFunction("testUtility_getWorldBoxObjectMovedObjectMovedBoxNotCentered", &testUtility_getWorldBoxObjectMovedObjectMovedBoxNotCentered);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsLineOverlappingTrue", &testUtility_lineIntersectsLineOverlappingTrue);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsLineDiagonalOverlappingTrue", &testUtility_lineIntersectsLineDiagonalOverlappingTrue);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsLineParallelOverlappingFalse", &testUtility_lineIntersectsLineParallelOverlappingFalse);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsLineNotOverlappingFalse", &testUtility_lineIntersectsLineNotOverlappingFalse);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsBoxBothInsideTrue", &testUtility_lineIntersectsBoxBothInsideTrue);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsBoxInAndOutsideTrue", &testUtility_lineIntersectsBoxInAndOutsideTrue);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsBoxBothOutsideDiagonalCrossTrue", &testUtility_lineIntersectsBoxBothOutsideDiagonalCrossTrue);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsBoxBothOutsideDiagonalNotCrossFalse", &testUtility_lineIntersectsBoxBothOutsideDiagonalNotCrossFalse);
	unitTestManager.registerTestFunction("testUtility_lineIntersectsBoxBothOutsideNotCrossFalse", &testUtility_lineIntersectsBoxBothOutsideNotCrossFalse);
	unitTestManager.registerTestFunction("testUtility_circleIntersectsBoxInsideTrue", &testUtility_circleIntersectsBoxInsideTrue);
	unitTestManager.registerTestFunction("testUtility_circleIntersectsBoxSideOverlappingTrue", &testUtility_circleIntersectsBoxSideOverlappingTrue);
	unitTestManager.registerTestFunction("testUtility_circleIntersectsBoxEdgeOverlappingTrue", &testUtility_circleIntersectsBoxEdgeOverlappingTrue);
	unitTestManager.registerTestFunction("testUtility_circleIntersectsBoxEdgeNotOverlappingFalse", &testUtility_circleIntersectsBoxEdgeNotOverlappingFalse);
	unitTestManager.registerTestFunction("testUtility_circleIntersectsBoxOutsideFalse", &testUtility_circleIntersectsBoxOutsideFalse);
	unitTestManager.registerTestFunction("testUtility_circleIntersectsCircleInsideTrue", &testUtility_circleIntersectsCircleInsideTrue);
	unitTestManager.registerTestFunction("testUtility_circleIntersectsCircleOutsideOverlappingTrue", &testUtility_circleIntersectsCircleOutsideOverlappingTrue);
	unitTestManager.registerTestFunction("testUtility_circleIntersectsCircleOutsideNotOverlappingFalse", &testUtility_circleIntersectsCircleOutsideNotOverlappingFalse);
	unitTestManager.registerTestFunction("testUtility_distanceZero", &testUtility_distanceZero);
	unitTestManager.registerTestFunction("testUtility_distanceSqrt2", &testUtility_distanceSqrt2);
	unitTestManager.registerTestFunction("testUtility_distanceSquaredZero", &testUtility_distanceSquaredZero);
	unitTestManager.registerTestFunction("testUtility_distanceSquared2", &testUtility_distanceSquared2);
	unitTestManager.registerTestFunction("testUtility_intToStringZero", &testUtility_intToStringZero);
	unitTestManager.registerTestFunction("testUtility_intToStringPositive", &testUtility_intToStringPositive);
	unitTestManager.registerTestFunction("testUtility_intToStringNegative", &testUtility_intToStringNegative);

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
	WorldManager &worldManager = WorldManager::getInstance();
	
	logManager.setVerbosity(LOG_DEBUG);
	gameManager.setGameOver(false);

	// reset level
	worldManager.setLevel(DEFAULT_LEVEL);
	worldManager.update(DEFAULT_FRAME_TIME);
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

bool testWorldManager_checkDefaultLevel(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	int level = worldManager.getLevel();

	return level == DEFAULT_LEVEL;
}

bool testWorldManager_setLevelShouldNotChangeWithoutUpdate(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	int level = 10;
	int res = worldManager.setLevel(level);

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
		"testWorldManager_setLevelShouldNotChangeWithoutUpdate()",
		"res=%d, level=%d",
		res,
		worldManager.getLevel());

	return res == 0 &&
		worldManager.getLevel() != level;
}

bool testWorldManager_setLevelShouldChangeAfterUpdate(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	int level = 10;
	int res = worldManager.setLevel(level);
	int levelBefore = worldManager.getLevel();
	worldManager.update(DEFAULT_FRAME_TIME);
	int levelAfter = worldManager.getLevel();

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
		"testWorldManager_setLevelShouldNotChangeWithoutUpdate()",
		"res=%d, levelBefore=%d, levelAfter=%d",
		res,
		levelBefore,
		levelAfter);

	return res == 0 &&
		levelBefore != level &&
		levelAfter == level;
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

bool testCircle_createDefaultCircle(void)
{
	Circle circle;

	return circle.getCenter().getX() == 0 &&
		circle.getCenter().getY() == 0 &&
		circle.getRadius() == 0;
}

bool testCircle_createCustomCircle(void)
{
	int x = 4;
	int y = 6;
	int r = 2;
	Circle circle(Position(x, y), r);

	return circle.getCenter().getX() == x &&
		circle.getCenter().getY() == y &&
		circle.getRadius() == r;
}

bool testCircle_centerGetterSetter(void)
{
	int x = 4;
	int y = 6;
	Circle circle;
	circle.setCenter(Position(x, y));

	return circle.getCenter().getX() == x &&
		circle.getCenter().getY() == y;
}

bool testCircle_radiusGetterSetter(void)
{
	int r = 2;
	Circle circle;
	circle.setRadius(r);

	return circle.getRadius() == r;
}

bool testCircle_sameCirclesComparedIsTrue(void)
{
	int x = 1;
	int y = 2;
	int r = 3;
	Circle circle1(Position(x, y), r);
	Circle circle2(Position(x, y), r);
	
	return circle1 == circle2;
}

bool testCircle_differentCirclesComparedIsFalse(void)
{
	Circle circle1(Position(1, 2), 3);
	Circle circle2(Position(2, 3), 4);
	
	return !(circle1 == circle2);
}

bool testCircle_sameCirclesNotComparedIsFalse(void)
{
	int x = 1;
	int y = 2;
	int r = 3;
	Circle circle1(Position(x, y), r);
	Circle circle2(Position(x, y), r);
	
	return !(circle1 != circle2);
}

bool testCircle_differentCirclesNotComparedIsTrue(void)
{
	Circle circle1(Position(1, 2), 3);
	Circle circle2(Position(2, 3), 4);
	
	return circle1 != circle2;
}

bool testLine_createDefaultLine(void)
{
	Line line;

	return line.getPosition1().getX() == 0 &&
		line.getPosition1().getY() == 0 &&
		line.getPosition2().getX() == 0 &&
		line.getPosition2().getY() == 0;
}

bool testLine_createCustomLine(void)
{
	int x1 = 2;
	int y1 = 3;
	int x2 = 4;
	int y2 = 5;
	Line line(Position(x1, y1), Position(x2, y2));

	return line.getPosition1().getX() == x1 &&
		line.getPosition1().getY() == y1 &&
		line.getPosition2().getX() == x2 &&
		line.getPosition2().getY() == y2;
}

bool testLine_positionGetterSetter(void)
{
	int x1 = 2;
	int y1 = 3;
	int x2 = 4;
	int y2 = 5;
	Line line;
	line.setPosition1(Position(x1, y1));
	line.setPosition2(Position(x2, y2));

	return line.getPosition1().getX() == x1 &&
		line.getPosition1().getY() == y1 &&
		line.getPosition2().getX() == x2 &&
		line.getPosition2().getY() == y2;
}

bool testLine_sameLinesComparedIsTrue(void)
{
	int x1 = 2;
	int y1 = 3;
	int x2 = 4;
	int y2 = 5;
	Line line1(Position(x1, y1), Position(x2, y2));
	Line line2(Position(x1, y1), Position(x2, y2));
	
	return line1 == line2;
}

bool testLine_differentLinesComparedIsFalse(void)
{
	Line line1(Position(1, 2), Position(3, 4));
	Line line2(Position(2, 1), Position(3, 5));
	
	return !(line1 == line2);
}

bool testLine_sameLinesNotComparedIsFalse(void)
{
	int x1 = 2;
	int y1 = 3;
	int x2 = 4;
	int y2 = 5;
	Line line1(Position(x1, y1), Position(x2, y2));
	Line line2(Position(x1, y1), Position(x2, y2));
	
	return !(line1 != line2);
}

bool testLine_differentLinesNotComparedIsTrue(void)
{
	Line line1(Position(1, 2), Position(3, 4));
	Line line2(Position(2, 1), Position(3, 5));
	
	return line1 != line2;
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

bool testObject_updateVisiblilty(void)
{
	Object *p_object = new Object();
	p_object->setAltitude(2);

	WorldManager &worldManager = WorldManager::getInstance();
	SceneGraph &sceneGraph = worldManager.getSceneGraph();
	int countBefore = sceneGraph.visibleObjects(2).getCount();
	p_object->setAltitude(3);
	int countOldAfter = sceneGraph.visibleObjects(2).getCount();
	int countNewAfter = sceneGraph.visibleObjects(3).getCount();

	return countBefore == 1 &&
		countOldAfter == 0 &&
		countNewAfter == 1;
}

bool testObject_updatePersistence(void)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();
	SceneGraph &sceneGraph = worldManager.getSceneGraph();
	sceneGraph.setLevel(1);
	Object *p_object1 = new TestObject();
	p_object1->setPersistence(false);
	Object *p_object2 = new TestObject();
	p_object2->setPersistence(false);
	sceneGraph.setLevel(2);
	Object *p_object3 = new TestObject();
	p_object3->setPersistence(false);
	sceneGraph.setLevel(1);

	worldManager.setLevel(1);
	worldManager.update(DEFAULT_FRAME_TIME);
	int countBefore = worldManager.getAllObjects().getCount();
	worldManager.setLevel(2);
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfter1 =  worldManager.getAllObjects().getCount();
	worldManager.setLevel(1);
	worldManager.update(DEFAULT_FRAME_TIME);
	p_object1->setPersistence(true);
	int countAfter2 =  worldManager.getAllObjects().getCount();
	p_object2->setPersistence(true);
	int countAfter3 =  worldManager.getAllObjects().getCount();
	worldManager.setLevel(2);
	worldManager.update(DEFAULT_FRAME_TIME); // switch because obj3 is on level 2
	p_object3->setPersistence(true);
	int countAfter4 =  worldManager.getAllObjects().getCount();
	worldManager.setLevel(1);
	worldManager.update(DEFAULT_FRAME_TIME);
	int countAfter5 =  worldManager.getAllObjects().getCount();
	ObjectList all = worldManager.getAllObjects();
	ObjectListIterator it(&all);

	logManager.writeLog(LOG_DEBUG,
		"testObject_updatePersistence",
		"Results: %d, %d, %d, %d, %d, %d\n",
		countBefore,
		countAfter1,
		countAfter2,
		countAfter3,
		countAfter4,
		countAfter5);

	return countBefore == 2 &&
		countAfter1 == 1 &&
		countAfter2 == 2 &&
		countAfter3 == 2 &&
		countAfter4 == 3 &&
		countAfter5 == 3;
}

bool testObject_updateSolidness(void)
{
	LogManager &logManager = LogManager::getInstance();
	WorldManager &worldManager = WorldManager::getInstance();
	SceneGraph &sceneGraph = worldManager.getSceneGraph();
	Object *p_object1 = new TestObject();
	p_object1->setSolidness(HARD);
	Object *p_object2 = new TestObject();
	p_object2->setSolidness(SOFT);
	Object *p_object3 = new TestObject();
	p_object3->setSolidness(SPECTRAL);

	int all0 = worldManager.getAllObjects().getCount();
	int solid0 = sceneGraph.solidObjects().getCount();
	p_object1->setSolidness(SOFT);
	int all1 = worldManager.getAllObjects().getCount();
	int solid1 = sceneGraph.solidObjects().getCount();
	p_object2->setSolidness(SPECTRAL);
	int all2 = worldManager.getAllObjects().getCount();
	int solid2 = sceneGraph.solidObjects().getCount();
	p_object3->setSolidness(HARD);
	int all3 = worldManager.getAllObjects().getCount();
	int solid3 = sceneGraph.solidObjects().getCount();
	p_object2->setSolidness(SOFT);
	int all4 = worldManager.getAllObjects().getCount();
	int solid4 = sceneGraph.solidObjects().getCount();

	// remove all:
	worldManager.markForDelete(p_object1);
	worldManager.markForDelete(p_object2);
	worldManager.markForDelete(p_object3);
	worldManager.update(DEFAULT_FRAME_TIME);
	int all5 = worldManager.getAllObjects().getCount();
	int solid5 = sceneGraph.solidObjects().getCount();
	
	logManager.writeLog(LOG_DEBUG,
		"testObject_updateSolidness",
		"Results: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
		all0,
		solid0,
		all1,
		solid1,
		all2,
		solid2,
		all3,
		solid3,
		all4,
		solid4,
		all5,
		solid5);

	// Results: 3, 5, 3, 5, 3, 4, 3, 5, 3, 6, 0, 3
	// result: 3, 3, 3, 3, 3, 2, 3, 2, 3, 3, 0, 0

	return all0 == 3 &&
		solid0 == 2 &&
		all1 == 3 &&
		solid1 == 2 &&
		all2 == 3 &&
		solid2 == 1 &&
		all3 == 3 &&
		solid3 == 2 &&
		all4 == 3 &&
		solid4 == 3 &&
		all5 == 0 &&
		solid5 == 0;
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

	return addedList.getCount() == 0 &&
		firstList.getCount() == 0 &&
		secondList.getCount() == 0;
}

bool testObjectList_operatorPlusEmptyListPlusFilledListIsFilled(void)
{
	ObjectList firstList;
	ObjectList secondList;
	int fullSize = 4;

	objectListFillWithObject(&secondList, fullSize);

	ObjectList addedList = firstList + secondList;

	return addedList.getCount() == fullSize &&
		firstList.getCount() == 0 &&
		secondList.getCount() == fullSize;
}

bool testObjectList_operatorPlusFilledListPlusFilledListIsDoubledList(void)
{
	ObjectList firstList;
	ObjectList secondList;
	int fullSize = 4;

	objectListFillWithObject(&firstList, fullSize);
	objectListFillWithObject(&secondList, fullSize);

	ObjectList addedList = firstList + secondList;

	return addedList.getCount() == 2 * fullSize &&
		firstList.getCount() == fullSize &&
		secondList.getCount() == fullSize;
}

bool testObjectList_operatorPlusTwoFullListsEqualsDoubledListWithRealloc(void)
{
	ObjectList firstList;
	ObjectList secondList;
	int fullSize = INIT_LIST_SIZE;

	objectListFillWithObject(&firstList, fullSize);
	objectListFillWithObject(&secondList, fullSize);

	ObjectList addedList = firstList + secondList;

	return addedList.getCount() == 2 * fullSize &&
		firstList.getCount() == INIT_LIST_SIZE &&
		secondList.getCount() == INIT_LIST_SIZE;
}

bool testSceneGraph_createDefault(void)
{
	SceneGraph sceneGraph;

	return sceneGraph.getLevel() == DEFAULT_LEVEL;
}

bool testSceneGraph_insertAndRemoveOneSolidObject(void)
{
	SceneGraph sceneGraph;
	Object *p_object = new Object();
	p_object->setSolidness(HARD);

	int countAllBeforeInsert = sceneGraph.allObjects().getCount();
	int res1 = sceneGraph.insertObject(p_object);
	int countAllAfterInsert = sceneGraph.allObjects().getCount();
	int countSolidAfterInsert = sceneGraph.solidObjects().getCount();
	int res2 = sceneGraph.removeObject(p_object);
	int countAllAfterRemove = sceneGraph.allObjects().getCount();
	int countSolidAfterRemove = sceneGraph.solidObjects().getCount();

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
			"testSceneGraph_insertAndRemoveOneSolidObject()",
			"%d, %d : %d, %d, %d, %d, %d\n",
			res1,
			res2,
			countAllBeforeInsert,
			countAllAfterInsert,
			countSolidAfterInsert,
			countAllAfterRemove,
			countSolidAfterRemove);

	return res1 == 0 &&
		res2 == 0 &&
		countAllBeforeInsert == 0 &&
		countAllAfterInsert == 1 &&
		countSolidAfterInsert == 1 &&
		countAllAfterRemove == 0 &&
		countSolidAfterRemove == 0;
}

bool testSceneGraph_insertAndRemoveOneNonSolidObject(void)
{
	SceneGraph sceneGraph;
	Object *p_object = new Object();
	p_object->setSolidness(SPECTRAL);

	int countAllBeforeInsert = sceneGraph.allObjects().getCount();
	int res1 = sceneGraph.insertObject(p_object);
	int countAllAfterInsert = sceneGraph.allObjects().getCount();
	int countSolidAfterInsert = sceneGraph.solidObjects().getCount();
	int res2 = sceneGraph.removeObject(p_object);
	int countAllAfterRemove = sceneGraph.allObjects().getCount();
	int countSolidAfterRemove = sceneGraph.solidObjects().getCount();

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
			"testSceneGraph_insertAndRemoveOneNonSolidObject()",
			"%d, %d : %d, %d, %d, %d, %d\n",
			res1,
			res2,
			countAllBeforeInsert,
			countAllAfterInsert,
			countSolidAfterInsert,
			countAllAfterRemove,
			countSolidAfterRemove);

	return res1 == 0 &&
		res2 == 0 &&
		countAllBeforeInsert == 0 &&
		countAllAfterInsert == 1 &&
		countSolidAfterInsert == 0 &&
		countAllAfterRemove == 0 &&
		countSolidAfterRemove == 0;
}

bool testSceneGraph_insertAndRemoveMultipleMixedObject(void)
{
	SceneGraph sceneGraph;
	int altitude = 2;
	Object *p_object1 = new Object();
	p_object1->setSolidness(SPECTRAL);
	p_object1->setAltitude(altitude);
	Object *p_object2 = new Object();
	p_object2->setSolidness(SOFT);
	p_object2->setAltitude(altitude);
	Object *p_object3 = new Object();
	p_object3->setSolidness(HARD);
	p_object3->setAltitude(altitude);
	p_object3->setPersistence(true);
	Object *p_object4 = new Object();
	p_object4->setSolidness(SOFT);
	p_object4->setAltitude(altitude);
	p_object4->setVisibility(false);

	int res1 = sceneGraph.insertObject(p_object1);
	int res2 = sceneGraph.insertObject(p_object2);
	int res3 = sceneGraph.insertObject(p_object3);
	int res4 = sceneGraph.insertObject(p_object4);
	int countAllAfterInsert = sceneGraph.allObjects().getCount();
	int countSolidAfterInsert = sceneGraph.solidObjects().getCount();
	int countVisibleAfterInsert = sceneGraph.visibleObjects(altitude).getCount();
	int res5 = sceneGraph.removeObject(p_object1);
	int res6 = sceneGraph.removeObject(p_object3);
	int countAllAfterRemove = sceneGraph.allObjects().getCount();
	int countSolidAfterRemove = sceneGraph.solidObjects().getCount();
	int countVisibleAfterRemove = sceneGraph.visibleObjects(altitude).getCount();

	LogManager &logManager = LogManager::getInstance();
	logManager.writeLog(LOG_DEBUG,
			"testSceneGraph_insertAndRemoveOneNonSolidObject()",
			"%d, %d, %d, %d, %d, %d : %d, %d, %d, %d, %d\n",
			res1,
			res2,
			res3,
			res4,
			res5,
			res6,
			countAllAfterInsert,
			countSolidAfterInsert,
			countAllAfterRemove,
			countAllAfterRemove,
			countSolidAfterRemove,
			countVisibleAfterRemove);

	return res1 == 0 &&
		res2 == 0 &&
		res3 == 0 &&
		res4 == 0 &&
		res5 == 0 &&
		res6 == 0 &&
		countAllAfterInsert == 4 &&
		countSolidAfterInsert == 3 &&
		countVisibleAfterInsert == 3 &&
		countAllAfterRemove == 2 &&
		countSolidAfterRemove == 2 &&
		countVisibleAfterRemove == 1;
}

bool testSceneGraph_insertAndRemoveWithLevelChange(void)
{
	LogManager &logManager = LogManager::getInstance();
	SceneGraph sceneGraph;
	Object *p_object1 = new Object();
	Object *p_object11 = new Object();
	Object *p_object2 = new Object();
	
	sceneGraph.setLevel(1);
	sceneGraph.insertObject(p_object1);
	sceneGraph.insertObject(p_object11);
	int countAll1AfterInsert = sceneGraph.allObjects().getCount();
	sceneGraph.setLevel(2);
	sceneGraph.insertObject(p_object2);
	int countAll2AfterInsert = sceneGraph.allObjects().getCount();
	sceneGraph.setLevel(1);
	int countAll1AfterLevelRevert = sceneGraph.allObjects().getCount();
	int res1 = sceneGraph.removeObject(p_object1);
	int countAll1AfterRemove = sceneGraph.allObjects().getCount();
	sceneGraph.setLevel(2);
	int countAll2AfterRemove = sceneGraph.allObjects().getCount();

	return res1 == 0 &&
		countAll1AfterInsert == 2 &&
		countAll2AfterInsert == 1 &&
		countAll1AfterLevelRevert == 2 &&
		countAll1AfterRemove == 1 &&
		countAll2AfterRemove == 1;
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

bool testViewObject_ceateDefault()
{
	ViewObject *vo = new ViewObject();

	return vo->getSolidness() == SPECTRAL &&
		vo->getAltitude() == MAX_ALTITUDE &&
		vo->getType() == TYPE_VIEW_OBJECT &&
		vo->getBorder() == true &&
		vo->getColor() == COLOR_DEFAULT &&
		vo->getValue() == 0;
}

bool testViewObject_ceateRegistersToWorldManager()
{
	WorldManager &worldManager = WorldManager::getInstance();
	ViewObject *vo = new ViewObject();
	int objCount = worldManager.getAllObjects().getCount();

	return objCount == 1;
}

bool testViewObject_setAndGetBorder()
{
	ViewObject *vo = new ViewObject();
	vo->setBorder(false);

	return vo->getBorder() == false;
}

bool testViewObject_setAndGetViewString()
{
	ViewObject *vo = new ViewObject();
	string viewString = "Test123";
	vo->setViewString(viewString);

	return vo->getViewString() == viewString;
}

bool testViewObject_setAndGetValue()
{
	ViewObject *vo = new ViewObject();
	int value = 123;
	vo->setValue(value);

	return vo->getValue() == value;
}

bool testViewObject_viewEventChangeValue()
{
	WorldManager &worldManager = WorldManager::getInstance();
	ViewObject *vo = new ViewObject();
	int valueBefore = 100;
	int deltaValue = 10;
	string viewString = "test";
	vo->setValue(valueBefore);
	vo->setViewString(viewString);

	EventView ev(viewString, deltaValue, true);
	worldManager.onEvent(&ev);

	worldManager.update(DEFAULT_FRAME_TIME);

	return vo->getValue() == valueBefore + deltaValue;
}

bool testViewObject_viewEventReplaceValue()
{
	WorldManager &worldManager = WorldManager::getInstance();
	ViewObject *vo = new ViewObject();
	int valueBefore = 100;
	int deltaValue = 10;
	string viewString = "test";
	vo->setValue(valueBefore);
	vo->setViewString(viewString);

	EventView ev(viewString, deltaValue, false);
	worldManager.onEvent(&ev);

	worldManager.update(DEFAULT_FRAME_TIME);

	return vo->getValue() == deltaValue;
}

bool testUtility_positionIntersectOverlappingTrue(void)
{
	Position position1(5, 5);
	Position position2(5, 5);

	return positionIntersect(position1, position2);
}

bool testUtility_positionIntersectNoOverlappingLeftFalse(void)
{
	Position position1(5, 5);
	Position position2(4, 5);

	return !positionIntersect(position1, position2);
}

bool testUtility_positionIntersectNoOverlappingRightFalse(void)
{
	Position position1(5, 5);
	Position position2(6, 5);

	return !positionIntersect(position1, position2);
}

bool testUtility_positionIntersectNoOverlappingTopFalse(void)
{
	Position position1(5, 5);
	Position position2(5, 4);

	return !positionIntersect(position1, position2);
}

bool testUtility_positionIntersectNoOverlappingBottomFalse(void)
{
	Position position1(5, 5);
	Position position2(5, 6);

	return !positionIntersect(position1, position2);
}

bool testUtility_boxIntersectsBoxOverlappingTrue(void)
{
	Box box1(Position(1 , 1), 4, 4);
	Box box2(Position(2 , 2), 4, 4);

	return boxIntersectsBox(box1, box2);
}

bool testUtility_boxIntersectsBoxEmptyOverlappingTrue(void)
{
	Box box1(Position(1 , 1), 0, 0);
	Box box2(Position(1 , 1), 0, 0);

	return boxIntersectsBox(box1, box2);
}

bool testUtility_boxIntersectsBoxNoOverlappingLeftFalse(void)
{
	Box box1(Position(2 , 2), 2, 2);
	Box box2(Position(0 , 2), 2, 2);

	return !boxIntersectsBox(box1, box2);
}

bool testUtility_boxIntersectsBoxNoOverlappingRightFalse(void)
{
	Box box1(Position(2 , 2), 2, 2);
	Box box2(Position(4 , 2), 2, 2);

	return !boxIntersectsBox(box1, box2);
}

bool testUtility_boxIntersectsBoxNoOverlappingTopFalse(void)
{
	Box box1(Position(2 , 2), 2, 2);
	Box box2(Position(2 , 0), 2, 2);

	return !boxIntersectsBox(box1, box2);
}

bool testUtility_boxIntersectsBoxNoOverlappingBottomFalse(void)
{
	Box box1(Position(2 , 2), 2, 2);
	Box box2(Position(2 , 4), 2, 2);

	return !boxIntersectsBox(box1, box2);
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

bool testUtility_getWorldBoxObjectOriginObject(void)
{
	Box bounds(Position(), 1, 2);
	Object *p_object = new Object();
	p_object->setBox(bounds);
	Box box = getWorldBox(p_object);

	return box.getCorner().getX() == 0 &&
		box.getCorner().getY() == -1 &&
		box.getHorizontal() == 1 &&
		box.getVertical() == 2;
}

bool testUtility_getWorldBoxObjectMovedObject(void)
{
	Box bounds(Position(), 1, 2);
	Object *p_object = new Object();
	p_object->setBox(bounds);
	p_object->setPosition(Position(3, 4));
	Box box = getWorldBox(p_object);

	return box.getCorner().getX() == 3 &&
		box.getCorner().getY() == 3 &&
		box.getHorizontal() == 1 &&
		box.getVertical() == 2;
}

bool testUtility_getWorldBoxObjectOriginObjectMovedBox(void)
{
	Box bounds(Position(5, 6), 1, 2);
	Object *p_object = new Object();
	p_object->setBox(bounds);
	Box box = getWorldBox(p_object);

	return box.getCorner().getX() == 5 &&
		box.getCorner().getY() == 5 &&
		box.getHorizontal() == 1 &&
		box.getVertical() == 2;
}

bool testUtility_getWorldBoxObjectMovedObjectMovedBox(void)
{
	Box bounds(Position(5, 6), 1, 2);
	Object *p_object = new Object();
	p_object->setBox(bounds);
	p_object->setPosition(Position(3, 4));
	Box box = getWorldBox(p_object);

	return box.getCorner().getX() == 8 &&
		box.getCorner().getY() == 9 &&
		box.getHorizontal() == 1 &&
		box.getVertical() == 2;
}

bool testUtility_getWorldBoxObjectOriginObjectNotCentered(void)
{
	Box bounds(Position(), 1, 2);
	Object *p_object = new Object();
	p_object->setBox(bounds);
	p_object->setCentered(false);
	Box box = getWorldBox(p_object);

	return box.getCorner().getX() == 0 &&
		box.getCorner().getY() == 0 &&
		box.getHorizontal() == 1 &&
		box.getVertical() == 2;
}

bool testUtility_getWorldBoxObjectMovedObjectNotCentered(void)
{
	Box bounds(Position(), 1, 2);
	Object *p_object = new Object();
	p_object->setBox(bounds);
	p_object->setPosition(Position(3, 4));
	p_object->setCentered(false);
	Box box = getWorldBox(p_object);

	return box.getCorner().getX() == 3 &&
		box.getCorner().getY() == 4 &&
		box.getHorizontal() == 1 &&
		box.getVertical() == 2;
}

bool testUtility_getWorldBoxObjectOriginObjectMovedBoxNotCentered(void)
{
	Box bounds(Position(5, 6), 1, 2);
	Object *p_object = new Object();
	p_object->setBox(bounds);
	p_object->setCentered(false);
	Box box = getWorldBox(p_object);

	return box.getCorner().getX() == 5 &&
		box.getCorner().getY() == 6 &&
		box.getHorizontal() == 1 &&
		box.getVertical() == 2;
}

bool testUtility_getWorldBoxObjectMovedObjectMovedBoxNotCentered(void)
{
	Box bounds(Position(5, 6), 1, 2);
	Object *p_object = new Object();
	p_object->setBox(bounds);
	p_object->setPosition(Position(3, 4));
	p_object->setCentered(false);
	Box box = getWorldBox(p_object);

	return box.getCorner().getX() == 8 &&
		box.getCorner().getY() == 10 &&
		box.getHorizontal() == 1 &&
		box.getVertical() == 2;
}

bool testUtility_valueInRangeInsideTrue(void)
{
	return valueInRange(10, 5, 12);
}

bool testUtility_valueInRangeOnLowerBorderTrue(void)
{
	return valueInRange(5, 5, 12);
}

bool testUtility_valueInRangeOnHigherBorderTrue(void)
{
	return valueInRange(12, 5, 12);
}

bool testUtility_valueInRangeOutsideFalse(void)
{
	return !valueInRange(16, 5, 12);
}

bool testUtility_clipValueInside(void)
{
	int value = 10;
	return clipValue(value, 5, 15) == value;
}

bool testUtility_clipValueOnLowerBorder(void)
{
	int value = 5;
	return clipValue(value, 5, 12) == value;
}

bool testUtility_clipValueOnHigherBorder(void)
{
	int value = 12;
	return clipValue(value, 5, 12) == value;
}

bool testUtility_clipValueOutside(void)
{
	int value = 16;
	int max = 12;
	return clipValue(value, 5, max) == max;
}

bool testUtility_lineIntersectsLineOverlappingTrue(void)
{
	Line line1(Position(5, 5), Position(5, 0));
	Line line2(Position(0, 2), Position(10, 2));

	return lineIntersectsLine(line1, line2);
}

bool testUtility_lineIntersectsLineDiagonalOverlappingTrue(void)
{
	Line line1(Position(0, 0), Position(10, 10));
	Line line2(Position(1, 0), Position(10, 11));

	return lineIntersectsLine(line1, line2);
}

bool testUtility_lineIntersectsLineParallelOverlappingFalse(void)
{
	Line line1(Position(0, 0), Position(10, 10));
	Line line2(Position(0, 1), Position(10, 11));

	return !lineIntersectsLine(line1, line2);
}

bool testUtility_lineIntersectsLineNotOverlappingFalse(void)
{
	Line line1(Position(0, 0), Position(10, 10));
	Line line2(Position(4, 3), Position(8, 6));

	return !lineIntersectsLine(line1, line2);
}

bool testUtility_lineIntersectsBoxBothInsideTrue(void)
{
	Line line(Position(1, 1), Position(4, 4));
	Box box(Position(0, 0), 5, 5);

	return lineIntersectsBox(line, box);
}

bool testUtility_lineIntersectsBoxInAndOutsideTrue(void)
{
	Line line(Position(3, 3), Position(6, 4));
	Box box(Position(0, 0), 5, 5);

	return lineIntersectsBox(line, box);
}

bool testUtility_lineIntersectsBoxBothOutsideDiagonalCrossTrue(void)
{
	Line line(Position(3, 6), Position(6, 2));
	Box box(Position(0, 0), 5, 5);

	return lineIntersectsBox(line, box);
}

bool testUtility_lineIntersectsBoxBothOutsideDiagonalNotCrossFalse(void)
{
	Line line(Position(4, 9), Position(7, 4));
	Box box(Position(0, 0), 5, 5);

	return !lineIntersectsBox(line, box);
}

bool testUtility_lineIntersectsBoxBothOutsideNotCrossFalse(void)
{
	Line line(Position(1, 8), Position(7, 6));
	Box box(Position(0, 0), 5, 5);

	return !lineIntersectsBox(line, box);
}

bool testUtility_circleIntersectsBoxInsideTrue(void)
{
	Circle circle(Position(2, 2), 3);
	Box box(Position(0, 0), 5, 5);

	return circleIntersectsBox(circle, box);
}

bool testUtility_circleIntersectsBoxSideOverlappingTrue(void)
{
	Circle circle(Position(7, 2), 4);
	Box box(Position(0, 0), 5, 5);

	return circleIntersectsBox(circle, box);
}

bool testUtility_circleIntersectsBoxEdgeOverlappingTrue(void)
{
	Circle circle(Position(12, 12), 5);
	Box box(Position(0, 0), 10, 10);

	return circleIntersectsBox(circle, box);
}

bool testUtility_circleIntersectsBoxEdgeNotOverlappingFalse(void)
{
	Circle circle(Position(13, 13), 3);
	Box box(Position(0, 0), 10, 10);

	return !circleIntersectsBox(circle, box);
}

bool testUtility_circleIntersectsBoxOutsideFalse(void)
{
	Circle circle(Position(5, 16), 3);
	Box box(Position(0, 0), 10, 10);

	return !circleIntersectsBox(circle, box);
}

bool testUtility_circleIntersectsCircleInsideTrue(void)
{
	Circle circle1(Position(5, 5), 3);
	Circle circle2(Position(5, 6), 3);

	return circleIntersectsCircle(circle1, circle2);
}

bool testUtility_circleIntersectsCircleOutsideOverlappingTrue(void)
{
	Circle circle1(Position(5, 5), 3);
	Circle circle2(Position(5, 10), 3);

	return circleIntersectsCircle(circle1, circle2);
}

bool testUtility_circleIntersectsCircleOutsideNotOverlappingFalse(void)
{
	Circle circle1(Position(5, 5), 3);
	Circle circle2(Position(5, 12), 3);

	return !circleIntersectsCircle(circle1, circle2);
}

bool testUtility_distanceZero(void)
{
	float delta = 0.0001f;
	float expacted = 0.0f;
	Position position1(5, 5);
	Position position2(5, 5);

	float result = distance(position1, position2);

	return expacted - delta <= result && result <= expacted + delta;
}

bool testUtility_distanceSqrt2(void)
{
	float delta = 0.0001f;
	float expacted = 1.4142135624f;
	Position position1(0, 0);
	Position position2(1, 1);

	float result = distance(position1, position2);

	return expacted - delta <= result && result <= expacted + delta;
}

bool testUtility_distanceSquaredZero(void)
{
	float delta = 0.0001f;
	float expacted = 0.0f;
	Position position1(5, 5);
	Position position2(5, 5);

	float result = distanceSquared(position1, position2);

	return expacted - delta <= result && result <= expacted + delta;
}

bool testUtility_distanceSquared2(void)
{
	float delta = 0.0001f;
	float expacted = 2;
	Position position1(0, 0);
	Position position2(1, 1);

	float result = distanceSquared(position1, position2);

	return expacted - delta <= result && result <= expacted + delta;
}

bool testUtility_intToStringZero(void)
{
	int value = 0;

	return intToString(value) == "0";
}

bool testUtility_intToStringPositive(void)
{
	int value = 2;

	return intToString(value) == "2";
}

bool testUtility_intToStringNegative(void)
{
	int value = -2;

	return intToString(value) == "-2";
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
