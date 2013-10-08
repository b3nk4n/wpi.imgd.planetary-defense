/*******************************************************************************
 * @file        EventInfo.cpp
 * @author      bsautermeister
 * @description User event, which is fired when the user wants to see
 *              some extra information.
 ******************************************************************************/

#include "EventInfo.h"

/**
 * Creates a new info event instance.
 * @param showInfo If additional info should be displayed.
 */
EventInfo::EventInfo(bool showInfo)
{
	setType(INFO_EVENT);
	_showInfo = showInfo;
}

/**
 * Gets whether additional info should be displayed or not.
 * @return Returns TRUE if additional info should be displayed, else FALSE.
 */
bool EventInfo::getShowInfo(void)
{
	return _showInfo;
}
