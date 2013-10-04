/*******************************************************************************
* @file        Building.cpp
* @author      bsautermeister
* @description The base class for all buildings, no matter what kind of.
******************************************************************************/

#include "Building.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "EventBuildingChanged.h"

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
}

/**
 * Cleans the building object and nodifies the player.
 */
Building::~Building(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	EventBuildingChanged event(_cost * SELL_FACTOR, _energy);
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
 * Gets the buildings energy requirement or value.
 * @return The energy requirement or value.
 */
int Building::getEnergy(void)
{
	return _energy;
}
