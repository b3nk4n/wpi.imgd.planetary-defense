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
private:
	/**
	 * Indicates whether additional information should be displayed.
	 */
	bool _showInfo;
	
public:
	/**
	 * Creates a new info event instance.
	 * @param showInfo If additional info should be displayed.
	 */
	EventInfo(bool showInfo);

	/**
	 * Gets whether additional info should be displayed or not.
	 * @return Returns TRUE if additional info should be displayed, else FALSE.
	 */
	bool getShowInfo(void);
};

#endif
