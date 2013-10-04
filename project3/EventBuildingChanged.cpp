/*******************************************************************************
* @file        EventBuildingChanged.h
* @author      bsautermeister
* @description Building event, which is fired when a building was constructed
*              or sold.
******************************************************************************/

#include "EventBuildingChanged.h"

/**
 * Creates a new building changed event instance.
 * @param credits The credits the player has to pay.
 * @param energyDelta The energy change.
 */
EventBuildingChanged::EventBuildingChanged(int creditsDelta, int energyDelta)
{
	setType(BUILDING_CHANGED_EVENT);
	_creditsDelta = creditsDelta;
	_energyDelta = energyDelta;
}

/**
 * Gets the credits change for the player.
 * @return The credits change for the player.
 */
int EventBuildingChanged::getCreditsDelta(void)
{
	return _creditsDelta;
}

/**
 * Gets the energy change.
 * @return The energy change.
 */
int EventBuildingChanged::getEnergyDelta(void)
{
	return _energyDelta;
}
