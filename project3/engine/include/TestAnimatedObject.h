/*******************************************************************************
 * @file        TestAnimatedObject.h
 * @author      bsautermeister
 * @description Test animated sprite object used by the simple unit test tool.
 ******************************************************************************/

#ifndef __TEST_ANIMATED_OBJECT_H__
#define __TEST_ANIMATED_OBJECT_H__

#include <string>
#include "TestObject.h"

using std::string;

#define TYPE_TEST_ANIMATED_OBJECT "__test_colidable_object__"

/**
 * The animated test object implementation for unit testing.
 */
class TestAnimatedObject : public TestObject
{
public:
	/**
	 * Creates a new test object instance.
	 */
	TestAnimatedObject(string spriteLabel, int slowdown);

	/**
	 * Renders the test game object.
	 */
	virtual void draw(void);
};

#endif
