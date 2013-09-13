/*******************************************************************************
 * @file        TestObject.h
 * @author      bsautermeister
 * @description Test object used by the simple unit test tool.
 ******************************************************************************/

#ifndef __TEST_OBJECT_H__
#define __TEST_OBJECT_H__

#include "Object.h"

#define TYPE_TEST_OBJECT "test_object"

/**
 * The test object implementation for unit testing.
 */
class TestObject : public Object
{
private:

	/**
	 * The test object time to end the game (in steps)
	 */
	int _stepsToGameOver;

	/**
	 * The test object steps to live
	 */
	int _stl;

	/**
	 * Updates the test object.
	 */
	 void step(void);

protected:
	
	/**
	 * The objects random generated id.
	 */
	int _id;

public:
	/**
	 * Creates a new test object instance.
	 */
	TestObject(void);

	/**
	 * Handles the events.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Renders the test game object.
	 */
	virtual void draw(void);

	/**
	 * Sets the sets until the objects sets the game over flag.
	 */
	void setStepsToGameOver(int value);

	/**
	 * Sets the steps to live.
	 */
	void setSTL(int value);
};

#endif
