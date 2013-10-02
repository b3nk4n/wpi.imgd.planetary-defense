/*******************************************************************************
 * @file        TestCollidableObject.h
 * @author      bsautermeister
 * @description Test object used by the simple unit test tool.
 ******************************************************************************/

#ifndef __TEST_COLLIDABLE_OBJECT_H__
#define __TEST_COLLIDABLE_OBJECT_H__

#include "TestObject.h"

#define TYPE_TEST_COLLIDABLE_OBJECT "test__colidable_object"

/**
 * The collidable test object implementation for unit testing.
 */
class TestCollidableObject : public TestObject
{
public:
	/**
	 * Creates a new test object instance.
	 */
	TestCollidableObject(void);

	/**
	 * Handles the events.
	 */
	virtual int eventHandler(Event *p_event);

	/**
	 * Renders the test game object.
	 */
	virtual void draw(void);
};

#endif
