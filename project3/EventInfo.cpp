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
	_sellingEnergy = 0;
	_upgradeEnergy = 0;
	_sellingPrice = 0;
	_upgradePrice = 0;
	_level = 1;
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
EventInfo::EventInfo(string name, int sellingEnergy, int sellingPrice)
{
	setType(INFO_EVENT);
	_infoType = BUILDING;
	_name = name;
	_sellingEnergy = sellingEnergy;
	_upgradeEnergy = 0;
	_sellingPrice = sellingPrice;
	_upgradePrice = 0;
	_level = 1;
	_fireRate = 0;
	_firePower = 0;
	_fireRange = 0;
}

/**
 * Creates a new info event instance with building data.
 * @param name The buildings name.
 * @param energy The buildings energy value.
 * @param sellingPrice The buildings selling price.
 * @param level The level.
 * @param fireRate The buildings fire rate.
 * @param firePower The buildings fire power.
 * @param fireRange The buildings fire range.
 */
EventInfo::EventInfo(string name, int sellingEnergy, int upgradeEnergy, int sellingPrice, int upgradePrice,
		int level, int fireRate, int firePower, int fireRange)
{
	setType(INFO_EVENT);
	_infoType = TOWER;
	_name = name;
	_sellingEnergy = sellingEnergy;
	_upgradeEnergy = upgradeEnergy;
	_sellingPrice = sellingPrice;
	_upgradePrice = upgradePrice;
	_level = level;
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
int EventInfo::getSellingEnergy(void)
{
	return _sellingEnergy;
}

/**
 * Gets the upgrade energy.
 * @return The upgrade energy.
 */
int EventInfo::getUpgradeEnergy(void)
{
	return _upgradeEnergy;
}

/**
 * Gets the selling price.
 * @return The selling price.
 */
int EventInfo::getSellingPrice(void)
{
	return _sellingPrice;
}

/**
 * Gets the upgrade price.
 * @return The upgrade price.
 */
int EventInfo::getUpgradePrice(void)
{
	return _upgradePrice;
}

/**
 * Gets the level.
 * @return The level.
 */
int EventInfo::getLevel(void)
{
	return _level;
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
