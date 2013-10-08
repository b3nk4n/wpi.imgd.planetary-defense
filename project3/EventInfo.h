/*******************************************************************************
 * @file        EventInfo.h
 * @author      bsautermeister
 * @description User event, which is fired when the user wants to see
 *              some extra information.
 ******************************************************************************/

#ifndef __EVENT_INFO_H__
#define __EVENT_INFO_H__

#include "Event.h"

#define INFO_EVENT "info"

/**
 * The info event class.
 */
class EventInfo : public Event
{
	/**
	 * The number of ticks to show additional information.
	 */
	int _infoTicks;

public:
	/**
	 * Creates a new info event instance.
	 * @param infoTicks The number of ticks to show additional info.
	 */
	EventInfo(int infoTicks);

	/**
	 * Gets the duration in ticks to show the information.
	 * @return The number of ticks to show additional info. 
	 */
	int getInfoTicks(void);
};

#endif
