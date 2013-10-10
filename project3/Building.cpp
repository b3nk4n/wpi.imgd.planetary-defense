/*******************************************************************************
 * @file        Building.cpp
 * @author      bsautermeister
 * @description The base class for all buildings, no matter what kind of.
 ******************************************************************************/

#include "Building.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "Event.h"
#include "EventBuildingChanged.h"
#include "EventPlayerKilled.h"

/**
 * Creates a new building object and notifies the player.
 * @param name The name.
 * @param spriteName The name of the sprite.
 * @param cost The cost.
 * @param energy The energy cost or value.
 */
Building::Building(string name, string spriteName, int cost, int energy)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	setType(TYPE_BUILDING);
	_name = name;
	_cost = cost;
	_energy = energy;

	Sprite *p_tempSprite = resourceManager.getSprite(spriteName);
  	if (!p_tempSprite)
  	{
  		logManager.writeLog(LOG_ERROR,
  			"Building::Building()",
  			"Loading sprite failed.\n");
  	}
  	else
  	{
  		setSprite(p_tempSprite);
    	setSpriteSlowdown(10);	
  	}

	WorldManager &worldManager = WorldManager::getInstance();
	EventBuildingChanged event(-_cost, _energy);
	worldManager.onEvent(&event);

	registerInterest(PLAYER_KILLED_EVENT);
}

/**
 * Cleans the building object and nodifies the player.
 */
Building::~Building(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	EventBuildingChanged event(getSellingPrice(), -_energy);
	worldManager.onEvent(&event);
}

/**
 * Gets the buildings name.
 * @return The building name.
 */
string Building::getName(void)
{
	return _name;
}

/**
 * Gets the building cost.
 * @return The building cost.
 */
int Building::getCost(void)
{
	return _cost;
}

/**
 * Gets the building selling price.
 * @return The building selling price.
 */
int Building::getSellingPrice(void)
{
	return _cost * SELL_FACTOR;
}

/**
 * Gets the buildings energy requirement or value.
 * @return The energy requirement or value.
 */
int Building::getEnergy(void)
{
	return _energy;
}

/**
 * Handle events
 * @param p_event The event.
 * @return Returns 1 if event was handled, else 0.
 */
int Building::eventHandler(Event *p_event)
{
	if (p_event->getType() == PLAYER_KILLED_EVENT)
	{
		WorldManager &worldManager = WorldManager::getInstance();
		worldManager.markForDelete(this);
		return 1;
	}

	return 0;
}