/*******************************************************************************
 * @file        EventInfo.h
 * @author      bsautermeister
 * @description User event, which is fired when the user navigates the cursor to
 *              some extra building information.
 ******************************************************************************/

#ifndef __EVENT_INFO_H__
#define __EVENT_INFO_H__

#include <string>
#include "Event.h"

using std::string;

#define INFO_EVENT "info"

enum InfoType
{
	NONE,
	BUILDING,
	TOWER
};

/**
 * The info event class.
 */
class EventInfo : public Event
{
private:
	/**
	 * Indicates which kind of additional info is available.
	 */
	InfoType _infoType;

	/**
	 * The name of the selected bulding.
	 */
	string _name;

	/**
	 * The energy value of the selected bulding.
	 */
	int _energy;

	/**
	 * The selling price of the selected bulding.
	 */
	int _sellingPrice;

	/**
	 * The level.
	 */
	int _level;

	/**
	 * The fire rate.
	 */
	int _fireRate;

	/**
	 * The fire power.
	 */
	int _firePower;

	/**
	 * The fire range.
	 */
	int _fireRange;
	
public:
	/**
	 * Creates a new info event instance with no data.
	 */
	EventInfo(void);

	/**
	 * Creates a new info event instance with building data.
	 * @param name The buildings name.
	 * @param energy The buildings energy value.
	 * @param sellingPrice The buildings selling price.
	 */
	EventInfo(string name, int energy, int sellingPrice);

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
	EventInfo(string name, int energy, int sellingPrice,
		int level, int fireRate, int firePower, int fireRange);

	/**
	 * Gets whether additional info are available.
	 * @return Returns TRUE if additional info should be displayed, else FALSE.
	 */
	InfoType getInfoType(void);

	/**
	 * Gets the name.
	 * @return The name.
	 */
	string getName(void);

	/**
	 * Gets the energy.
	 * @return The energy.
	 */
	int getEnergy(void);

	/**
	 * Gets the selling price.
	 * @return The selling price.
	 */
	int getSellingPrice(void);

	/**
	 * Gets the level.
	 * @return The level.
	 */
	int getLevel(void);

	/**
	 * Gets the fire rate.
	 * @return The fire rate.
	 */
	int getFireRate(void);

	/**
	 * Gets the fire power.
	 * @return The fire power.
	 */
	int getFirePower(void);

	/**
	 * Gets the fire range.
	 * @return The fire range.
	 */
	int getFireRange(void);
};

#endif
