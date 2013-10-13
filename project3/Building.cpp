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
#include "GraphicsManager.h"
#include "EventStep.h"

/**
 * Creates a new building object and notifies the player.
 * @param name The name.
 * @param spriteName The name of the sprite.
 * @param price The price.
 * @param energy The energy price or value.
 */
Building::Building(string name, string spriteName, int price, int energy)
{
	LogManager &logManager = LogManager::getInstance();
	ResourceManager &resourceManager = ResourceManager::getInstance();

	setType(TYPE_BUILDING);
	_name = name;
	_price = price;
	_energy = energy;
	_level = 1;
	_levelBlinkCounter = LEVEL_BLINK_INTERVALL;

	_totalPrice = _price;
	_totalEnergy = _energy;

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
	EventBuildingChanged event(-getPrice(), getEnergy());
	worldManager.onEvent(&event);

	registerInterest(PLAYER_KILLED_EVENT);
	registerInterest(STEP_EVENT);
}

/**
 * Cleans the building object and nodifies the player.
 */
Building::~Building(void)
{
	WorldManager &worldManager = WorldManager::getInstance();
	EventBuildingChanged event(getSellingPrice(), -getSellingEnergy());
	worldManager.onEvent(&event);
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
		return 0; // forward to subclass
	}

	if (p_event->getType() == STEP_EVENT)
	{
		--_levelBlinkCounter;

		if (_levelBlinkCounter < - 2 * LEVEL_BLINK_INTERVALL)
			_levelBlinkCounter = LEVEL_BLINK_INTERVALL;

		return 0; // forward to subclass
	}

	return 0;
}

/**
 * Renders additional upgrade information.
 */
void Building::draw(void)
{
	Object::draw();

	GraphicsManager &graphicsManager = GraphicsManager::getInstance();

	if(getLevel() > 1 && _levelBlinkCounter > 0)
	{
		graphicsManager.drawStringFormat(getPosition(), "%d", getLevel());
	}
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
 * Gets the building price.
 * @return The building price.
 */
int Building::getPrice(void)
{
	return _price;
}

/**
 * Gets the building selling price.
 * @return The building selling price.
 */
int Building::getSellingPrice(void)
{
	return (int)(_totalPrice * SELL_FACTOR);
}

/**
 * Gets the building upgrade  price.
 * @return The building upgrade price.
 */
int Building::getUpgradePrice(void)
{
	return _price * (getLevel());
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
 * Gets the buildings energy for selling.
 * @return The energy for selling.
 */
int Building::getSellingEnergy(void)
{
	return _totalEnergy;
}

/**
 * Gets the buildings upgrade energy requirement or value.
 * @return The energy for upgrading.
 */
int Building::getUpgradeEnergy(void)
{
	return _energy + (_energy * getLevel() / 2);
}

/**
 * Indicates whether the building is able to upgrade.
 * @note Default is FALSE.
 * @param credits The players credits.
 * @param energy The players energy.
 * @return Returns if the building is able to upgrade.
 */
bool Building::canUpgrade(int credits, int energy)
{
	return getLevel() < MAX_UPGRADE_LEVEL && getUpgradePrice() <= credits && getUpgradeEnergy() <= energy;
}

/**
 * Upgrades the building.
 */
void Building::upgrade(void)
{
	_totalPrice += getUpgradePrice();
	_totalEnergy += getUpgradeEnergy();

	// notify player
	WorldManager &worldManager = WorldManager::getInstance();
	EventBuildingChanged event(-getUpgradePrice(), getUpgradeEnergy());
	worldManager.onEvent(&event);

	_level++;
}

/**
 * Gets the upgrade level of the building.
 * @return The upgrade level.
 */
int Building::getLevel(void)
{
	return _level;
}
