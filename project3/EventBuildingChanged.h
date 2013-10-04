/*******************************************************************************
* @file        EventBuildingChanged.h
* @author      bsautermeister
* @description Building event, which is fired when a building was constructed
*              or sold.
******************************************************************************/

#ifndef __EVENT_BUILDING_CHANGED_H__
#define __EVENT_BUILDING_CHANGED_H__

#include "Event.h"

#define BUILDING_CHANGED_EVENT "building_changed"

/**
 * The building changed event class.
 */
class EventBuildingChanged : public Event
{
private:
	/**
	 * The credits change for the player to buy or sell the building.
	 */
	int _creditsDelta;

	/**
	 * The energy change for that building, so it could be
	 * positive or negative.
	 */
	int _energyDelta;

public:
	/**
	 * Creates a new building changed event instance.
	 * @param credits The credits the player has to pay.
	 * @param energyDelta The energy change.
	 */
	EventBuildingChanged(int creditsDelta, int energyDelta);

	/**
	 * Gets the credits change for the player.
	 * @return The credits change for the player.
	 */
	int getCreditsDelta(void);

	/**
	 * Gets the energy change.
	 * @return The energy change.
	 */
	int getEnergyDelta(void);
};

#endif
