/*******************************************************************************
 * @file        EventTest.h
 * @author      bsautermeister
 * @description Test event class for unit testing.
 ******************************************************************************/

#ifndef __EVENT_TEST_H__
#define __EVENT_TEST_H__

#include "Event.h"

#define TEST_EVENT "__test__"

/**
 * The test event class.
 */
class EventTest : public Event
{
public:
	/**
	 * Creates a new test event instance.
	 */
	EventTest(void);
};

#endif
