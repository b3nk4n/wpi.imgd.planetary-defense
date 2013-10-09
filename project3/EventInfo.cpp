/*******************************************************************************
 * @file        EventInfo.h
 * @author      bsautermeister
 * @description User event, which is fired when the user navigates the cursor to
 *              some extra building information.
 ******************************************************************************/

#include "EventInfo.h"

/**
 * Creates a new info event instance with no data.
 */
EventInfo::EventInfo(void)
{
	setType(INFO_EVENT);
	_infoType = NONE;
	_name = "";
	_energy = 0;
	_sellingPrice = 0;
	_fireRate = 0;
	_firePower = 0;
	_fireRange = 0;
}

/**
 * Creates a new info event instance with building data.
 * @param name The buildings name.
 * @param energy The buildings energy value.
 * @param sellingPrice The buildings selling price.
 */
EventInfo::EventInfo(string name, int energy, int sellingPrice)
{
	setType(INFO_EVENT);
	_infoType = BUILDING;
	_name = name;
	_energy = energy;
	_sellingPrice = sellingPrice;
	_fireRate = 0;
	_firePower = 0;
	_fireRange = 0;
}

/**
 * Creates a new info event instance with building data.
 * @param name The buildings name.
 * @param energy The buildings energy value.
 * @param sellingPrice The buildings selling price.
 * @param fireRate The buildings fire rate.
 * @param firePower The buildings fire power.
 * @param fireRange The buildings fire range.
 */
EventInfo::EventInfo(string name, int energy, int sellingPrice,
	int fireRate, int firePower, int fireRange)
{
	setType(INFO_EVENT);
	_infoType = TOWER;
	_name = name;
	_energy = energy;
	_sellingPrice = sellingPrice;
	_fireRate = fireRate;
	_firePower = firePower;
	_fireRange = fireRange;
}

/**
 * Gets whether additional info are available.
 * @return Returns TRUE if additional info should be displayed, else FALSE.
 */
InfoType EventInfo::getInfoType(void)
{
	return _infoType;
}

/**
 * Gets the name.
 * @return The name.
 */
string EventInfo::getName()
{
	return _name;
}

/**
 * Gets the energy.
 * @return The energy.
 */
int EventInfo::getEnergy()
{
	return _energy;
}

/**
 * Gets the selling price.
 * @return The selling price.
 */
int EventInfo::getSellingPrice()
{
	return _sellingPrice;
}

/**
 * Gets the fire rate.
 * @return The fire rate.
 */
int EventInfo::getFireRate()
{
	return _fireRate;
}

/**
 * Gets the fire power.
 * @return The fire power.
 */
int EventInfo::getFirePower()
{
	return _firePower;
}

/**
 * Gets the fire range.
 * @return The fire range.
 */
int EventInfo::getFireRange()
{
	return _fireRange;
}
