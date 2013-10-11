/*******************************************************************************
 * @file        Building.h
 * @author      bsautermeister
 * @description The base class for all buildings, no matter what kind of.
 ******************************************************************************/
#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <string>
#include "Object.h"
#include "Event.h"

using std::string;

#define TYPE_BUILDING "building"
#define SELL_FACTOR 0.5f

/*
* Represents a general building.
*/
 class Building : public Object
 {
 private:
 	/**
 	 * The name of the building.
 	 */
 	string _name;

 	/**
 	 * The always positive cost of the building.
 	 */
 	int _cost;

 	/**
 	 * The energy requirement or value of the building.
 	 * @note The value can be positive and negative.
 	 */
 	int _energy;

 public:
 	/**
 	 * Creates a new building object and notifies the player.
 	 * @param name The name.
 	 * @param spriteName The name of the sprite.
 	 * @param cost The cost.
 	 * @param energy The energy cost or value.
 	 */
 	Building(string name, string spriteName, int cost, int energy);

 	/**
 	 * Cleans the building object and nodifies the player.
 	 */
 	virtual ~Building(void);

 	/**
 	 * Gets the buildings name.
 	 * @return The building name.
 	 */
 	string getName(void);

 	/**
 	 * Gets the building cost.
 	 * @return The building cost.
 	 */
 	int getCost(void);

 	/**
	 * Gets the building selling price.
	 * @return The building selling price.
	 */
	int getSellingPrice(void);

 	/**
 	 * Gets the buildings energy requirement or value.
 	 * @return The energy requirement or value.
 	 */
 	int getEnergy(void);

	/**
	 * Handle events
	 * @param p_event The event.
	 * @return Returns 1 if event was handled, else 0.
	 */
	virtual int eventHandler(Event *p_event);
};

#endif

