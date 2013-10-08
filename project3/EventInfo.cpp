/*******************************************************************************
 * @file        EventInfo.cpp
 * @author      bsautermeister
 * @description User event, which is fired when the user wants to see
 *              some extra information.
 ******************************************************************************/

#include "EventInfo.h"

/**
 * Creates a new info event instance.
 * @param infoTicks The number of ticks to show additional info.
 */
EventInfo::EventInfo(int infoTicks)
{
	setType(INFO_EVENT);
	_infoTicks = infoTicks;
}

/**
 * Gets the duration in ticks to show the information.
 * @return The number of ticks to show additional info. 
 */
int EventInfo::getInfoTicks(void)
{
	return _infoTicks;
}
