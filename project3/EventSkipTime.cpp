/*******************************************************************************
 * @file        EventSkipTime.cpp
 * @author      bsautermeister
 * @description User event, which sets the next wave timer to zero.
 ******************************************************************************/

#include "EventSkipTime.h"

/**
 * Creates a new skip time event instance.
 */
EventSkipTime::EventSkipTime(void)
{
	setType(SKIP_TIME_EVENT);
}
